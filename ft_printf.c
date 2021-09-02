/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrubin <nrubin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/01 14:36:44 by nrubin            #+#    #+#             */
/*   Updated: 2021/09/02 14:12:43 by nrubin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libftprintf.h"

// Initializes flag structure.
t_list	ft_flags(void)
{
	t_list	flags;

	flags.width = 0;
	flags.minus = 0;
	flags.zero = 0;
	flags.dot = -1;
	flags.free = 0;
	return (flags);
}

// Calls the correct printf function depending on conversion type.
int	ft_printer(char *format, t_list flags, va_list args)
{
	if (*format == 'i' || *format == 'd')
		return (ft_print_int(flags, args));
	if (*format == 'c')
		return (ft_print_char(flags, args));
	if (*format == 's')
		return (ft_print_str(flags, args));
	if (*format == 'x')
		return (ft_print_low_hex(flags, args));
	if (*format == 'X')
		return (ft_print_up_hex(flags, args));
	if (*format == 'p')
		return (ft_print_pointer(flags, args));
	if (*format == 'u')
		return (ft_print_unsigned(flags, args));
	if (*format == '%')
		return (ft_print_percent(flags));
	else
		return (0);
}

// Advances through format string until a format identifier is found.
int	ft_manager(char *format, va_list args)
{
	int		count;
	t_list	flags;

	flags = ft_flags();
	count = 0;
	while (*format)
	{
		if (*format == '%' && *(format + 1) == '%')
		{
			ft_putchar_n(*format, &count);
			format++;
		}
		else if (*format == '%')
		{
			format++;
			format = ft_parser(format, &flags, args);
			count += ft_printer(format, flags, args);
			flags = ft_flags();
		}
		else
			ft_putchar_n(*format, &count);
		format++;
	}
	return (count);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		count;
	char	*format;

	format = ft_strdup(str);
	count = 0;
	va_start(args, str);
	count = ft_manager(format, args);
	va_end(args);
	free(format);
	return (count);
}
