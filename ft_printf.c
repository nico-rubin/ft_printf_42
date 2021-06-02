#include "libftprintf.h"


// Initializes flag structure.
t_list ft_flags(void)
{
	t_list flags;
	flags.width = 0;
	flags.minus = 0;
	flags.zero = 0;
	flags.dot = -1;
	flags.count = 0;

	return (flags);
}

// Parses through format string to fill flags structure with information.
void	ft_parser(char *format, t_list *flags, va_list args)
{
	format++;
	while (*format == '-' || *format == '0')
	{
		if (*format == '-')
			flags->minus = 1;
		if (*format == '0')
			flags->zero = 1;
		format++;
	}
	if (*format == '*')
	{
		flags->width = va_arg(args, int);
		format++;
	}
	while (*format >= '0' && *format <= '9')
	{
		flags->width = flags->width * 10 + *format - '0';
		format++;
	}
	if (*format == '.')
	{
		flags->dot = 0;
		format++;
	}
	if (*format == '*')
	{
		flags->dot = va_arg(args, int);
		format++;
	}
	while (*format >= '0' && *format <= '9')
	{
		flags->dot = flags->dot * 10 + *format - '0';
		format++;
	}
}

// Calls the correct depending or conversion type.
int		ft_printer(char *format, t_list flags, va_list args)
{
	if (*format == 'i' || *format == 'd')
		return (ft_print_int(flags, args));
	else
		return (0);
}

int	ft_manager(char *format, va_list args)
{
	int	count;
	t_list	flags;

	flags = ft_flags();
	count = 0;
	while (*format)
	{
		if (*format == '%' && *(format + 1) == '%')
		{
			ft_putchar_n(*format, &count);
			format += 2;
		}
		else if (*format == '%')
		{
			ft_parser(format, &flags, args);
			while(ft_is_identifier(*format) || *format == '%')
				format++;
			count += ft_printer(format, flags, args);
			flags = ft_flags();
			format++;
		}
		else
		{
			ft_putchar_n(*format, &count);
			format++;
		}
	}
	return (count);
}

int	ft_printf(const char *str, ...)
{
	va_list args;
	int		count;
	char 	*format;

	format = ft_strdup(str);
	count = 0;

	va_start(args, str);
	count = ft_manager(format, args);
	va_end(args);
	free(format);
	return (count);
}

int	main(void)
{
	printf("\n%i\n", ft_printf("%*.*i", 10, 5, -456));
	printf("\n%i\n", printf("%*.*i", 10, 5, -456));
}
