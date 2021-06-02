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
	if (*format == 'c')
		return (ft_print_char(flags, args));
	if (*format == 's')
		return (ft_print_str(flags, args));
	if (*format == 'x')
		return (ft_print_low_hex(flags, args));
	//if (*format == 'X')
		//return (ft_print_up_hex(flags, args));
	//if (*format == 'p')
		//return (ft_print_pointer(flags, args));
	//if (*format == 'u')
		//return (ft_print_unsigned(flags, args));
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
	//printf("| count: %i\n\n", ft_printf("output: |%*.*i", 10, 5, -456));
	//printf("| count: %i\n\n", printf("output: |%*.*i", 10, 5, -456));

	//printf("| count: %i\n", ft_printf("output: |%0*c", 10, 'c'));
	//printf("| count: %i\n\n", printf("output: |%0*c", 10, 'c'));

	//printf("| count: %i\n\n", ft_printf("output: |%12.2s", "hello"));
	//printf("| count: %i\n\n", printf("output: |%12.2s", "hello"));

	printf("| count: %i\n\n", ft_printf("output: |%x", 75));
	printf("| count: %i\n\n", printf("output: |%x", 75));

	//printf("| count: %i\n\n", ft_printf("output: |%12x", -123));
	//printf("| count: %i\n\n", printf("output: |%12x", -123));

	//printf("| count: %i\n\n", ft_printf("output: |%.2x", -123));
	//printf("| count: %i\n\n", printf("output: |%.2x", -123));

	//printf("| count: %i\n\n", ft_printf("output: |%5.2x", -123));
	//printf("| count: %i\n\n", printf("output: |%5.2x", -123));
}
