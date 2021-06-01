#include "libftprintf.h"


// Initializes flag structure.
t_list ft_flags(void)
{
	t_list flags;
	flags.width = 0;
	flags.minus = 0;
	flags.zero = 0;
	flags.dot = -1;
	//flags.count = 0;

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

// Calls the correct depending or conversion type.
int		ft_printer(char *format, t_list flags, va_list args)
{
	if (*format == 'i')
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
			flags = ft_parser(format, flags, args);
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
	int i;

	i = ft_printf("%%%-5.3i Hello%% %i", 12, 10);
	printf("\n%i\n", i);
	i = printf("%%%-5.3i Hello%% %i", 12, 10);
	printf("\n%i\n", i);
/*
	ft_printf("%.4i", -12);
	printf("\n%.4i\n\n", -12);


	// str < width && width > dot && dot > str
	ft_printf("%-5.2i", -12);
	printf("\n%-5.2i\n\n", -12);

	// str < width && width < dot && dot > str
	ft_printf("%4.5i", -120);
	printf("\n%4.5i\n\n", -120);

	// str > width && width > dot && dot > str
	ft_printf("%1.4i", 120);
	printf("\n%1.4i\n\n", 120);

	// str > width && width < dot && dot > str
	ft_printf("%3.5i", 1200);
	printf("\n%3.5i\n\n", 1200);

	// str < width && width < dot && dot > str
	ft_printf("%5.3i", 12000);
	printf("\n%5.3i\n\n", 12000);

	 ft_printf("%50.30i", -10);
	 printf("\n%50.30i\n\n", -10);
*/
}
