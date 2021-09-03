/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   low_hex_helper.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrubin <nrubin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/01 14:37:10 by nrubin            #+#    #+#             */
/*   Updated: 2021/09/03 13:57:13 by nrubin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

// Handles exceptional flag cases.
void	ft_low_hex_exceptions(t_list *flags, int n)
{
	char	*ret;
	int		i;

	if (flags->width < 0)
	{
		flags->width = flags->width * -1;
		flags->minus = 1;
	}
	if (flags->dot > -1 && flags->zero == 1)
		flags->zero = 0;
	if (flags->zero == 1 && flags->minus == 1)
		flags->zero = 0;
	if (flags->dot == 0 && n == 0)
	{
		i = flags->width;
		ret = (char *)malloc(sizeof(*ret) * (i + 1));
		ret[i] = '\0';
		while (i--)
			ret[i] = ' ';
		ft_putstr(ret);
		free(ret);
	}
}

// Adds '0' padding to 'str' when length of 'str' is smaller than 'flags.dot'.
char	*ft_low_hex_with_precision(char *str, t_list flags)
{
	int		diff;
	char	*ret;
	int		i;
	int		len;
	char	*tmp;

	tmp = str;
	i = 0;
	len = ft_strlen(str);
	diff = flags.dot - len;
	ret = (char *)malloc(sizeof(*ret) * (diff + len + 1));
	while (i < diff)
		ret[i++] = '0';
	while (i < diff + len)
		ret[i++] = *(tmp++);
	ret[i] = '\0';
	free(str);
	return (ret);
}

// Adds padding to 'str' when length of 'str'is smaller than 'flags.width' and
// the result is right aligned.
char	*ft_low_hex_right_width(char *str, t_list flags)
{
	int		diff;
	char	*ret;
	int		i;
	int		len;
	char	*tmp;

	tmp = str;
	i = 0;
	len = ft_strlen(str);
	diff = flags.width - len;
	ret = (char *)malloc(sizeof(*ret) * (diff + len + 1));
	if (flags.zero == 1)
		while (i < diff)
			ret[i++] = '0';
	else
		while (i < diff)
			ret[i++] = ' ';
	while (i < diff + len)
		ret[i++] = *(tmp++);
	ret[i] = '\0';
	free(str);
	return (ret);
}

// Adds padding to 'str' when length of 'str'is smaller than 'flags.width' and
// the result is left aligned.
char	*ft_low_hex_left_width(char *str, t_list flags)
{
	int		diff;
	char	*ret;
	int		i;
	int		len;
	char	*tmp;

	tmp = str;
	i = 0;
	len = ft_strlen(str);
	diff = flags.width - len;
	ret = (char *)malloc(sizeof(*ret) * (diff + len + 1));
	while (i < len)
		ret[i++] = *(tmp++);
	while (i < diff + len)
		ret[i++] = ' ';
	ret[i] = '\0';
	free(str);
	return (ret);
}

// Main int printing function.
int	ft_print_low_hex(t_list flags, va_list args)
{
	int		n;
	char	*str;
	int		len;

	n = va_arg(args, int);
	ft_low_hex_exceptions(&flags, n);
	if (flags.dot == 0 && n == 0)
		return (flags.width);
	str = ft_to_low_hex(n);
	if (flags.dot > -1 && ft_strlen(str) < flags.dot)
		str = ft_low_hex_with_precision(str, flags);
	if (flags.width > 0 && flags.minus == 0 && ft_strlen(str) < flags.width)
		str = ft_low_hex_right_width(str, flags);
	if (flags.width > 0 && flags.minus == 1 && ft_strlen(str) < flags.width)
		str = ft_low_hex_left_width(str, flags);
	ft_putstr(str);
	len = ft_strlen(str);
	free(str);
	return (len);
}
