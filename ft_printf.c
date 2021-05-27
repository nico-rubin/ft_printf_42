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

t_list	ft_parser(char *format, t_list flags)
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
	while (*format == '.')
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

int	ft_manager(char *format, t_list flags, va_list args)
{

}

int	ft_printf(const char *str, ...)
{
	int	count;
	va_list args;
	t_list flags;
	char *format;

	flags = ft_flags();
	format = ft_strdup(str);
	flags = ft_parser(format, flags);
	count = ft_manager()
	printf("width: %d\nminus: %d\nzero: %d\ndot: %d\n", flags.width, flags.minus, flags.zero, flags.dot);
	va_end(args);
	return (count);
}

int	main(void)
{
	ft_printf("%-02147483647.i\n", 100);
}
