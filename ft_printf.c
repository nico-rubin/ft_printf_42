#include "libftprintf.h"

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

void	ft_int_print(t_list flags, va_list args)
{
	int	n;

	n = va_arg(args, int);
}

void	ft_printer(char *format, t_list flags, va_list args)
{
	format++;
	while (ft_is_identifier(*format))
		format++;
	if (*format == 'i')
		ft_int_print(flags, args);
}

t_list	ft_manager(char *format, t_list flags, va_list args)
{
	while (*format)
	{
		if (*format == '%' && *(format+1) != '%')
			flags = ft_parser(format, flags, args);
	}
	return (flags);
}

int	ft_printf(const char *str, ...)
{
	va_list args;
	t_list flags;
	char *format;

	flags = ft_flags();
	format = ft_strdup(str);

	va_start(args, str);
	flags = ft_manager(format, flags, args);
	va_end(args);
	free(format);
	return (flags.count);
}

int	main(void)
{
	ft_printf("%i\n", 100);
}
