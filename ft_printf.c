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
t_list	ft_parser(char *format, t_list flags, va_list args)
{
	format++;
	while (*format == '-' || *format == '0')
	{
		if (*format == '-')
			flags.minus = 1;
		if (*format == '0')
			flags.zero = 1;
		format++;
	}
	while (*format >= '0' && *format <= '9')
	{
		flags.width = flags.width * 10 + *format - '0';
		format++;
	}
	if (*format == '.')
	{
		flags.dot = 0;
		format++;
	}
	while (*format >= '0' && *format <= '9')
	{
		flags.dot = flags.dot * 10 + *format - '0';
		format++;
	}
	return (flags);
}

void	ft_printer(char *format, t_list flags, va_list args)
{
	if (*format == 'i')
		ft_print_int(flags, args);
}

int	ft_manager(char *format, va_list args)
{
	int	count;
	t_list	flags;

	flags = ft_flags();
	count = 0;

	while (*format)
	{
		if (*format == '%')
		{
			flags = ft_parser(format, flags, args);
			while(ft_is_identifier(*format) || *format == '%')
				format++;
			ft_printer(format, flags, args);
			//count += flags.count;
		}
		else
		//{
			format++;
			//count++;
		//}
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
	ft_printf("%10i\n", 0);
	printf("%10i\n", 0);
}
