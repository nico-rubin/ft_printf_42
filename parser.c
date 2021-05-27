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
	if (*format == '-' || *format == '0')
	{
		if (*format == '-')
			flags.minus = 1;
		else if (*format == '0')
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

int	main(void)
{
	char *str = "%H"
}
