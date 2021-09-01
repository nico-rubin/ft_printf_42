#include "../includes/libftprintf.h"

char	*width(char *format, t_list *flags)
{
	while (*format >= '0' && *format <= '9')
	{
		flags->width = flags->width * 10 + *format - '0';
		format++;
	}
	return (format);
}

char	*flag_width(char *format, t_list *flags, va_list args)
{
	flags->width = va_arg(args, int);
	format++;
	return (format);
}

char	*dot(char *format, t_list *flags)
{
	while (*format >= '0' && *format <= '9')
	{
		flags->dot = flags->dot * 10 + *format - '0';
		format++;
	}
	return (format);
}

char	*flag_dot(char *format, t_list *flags, va_list args)
{
	flags->dot = va_arg(args, int);
	format++;
	return (format);
}

// Parses through formt string to fill flags structure with information.
char	*ft_parser(char *format, t_list *flags, va_list args)
{
	while (*format == '-' || *format == '0')
	{
		if (*format == '-')
			flags->minus = 1;
		if (*format == '0')
			flags->zero = 1;
		format++;
	}
	if (*format == '*')
		format = flag_width(format, flags, args);
	if (*format >= '0' && *format <= '9')
		format = width(format, flags);
	if (*format == '.' || *format == '*')
	{
		if (*format == '.')
			flags->dot = 0;
		format++;
	}
	if (*format == '*')
		format = flag_dot(format, flags, args);
	if (*format >= '0' && *format <= '9')
		format = dot(format, flags);
	return (format);
}
