/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unsigned_helper.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrubin <nrubin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/01 14:37:55 by nrubin            #+#    #+#             */
/*   Updated: 2021/09/02 13:29:51 by nrubin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

// Handles exceptional flag cases.
void	ft_unsigned_exceptions(t_list *flags, unsigned int n)
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
char	*ft_unsigned_with_precision(char *str, t_list flags)
{
	int		diff;
	char	*ret;
	int		i;
	int		len;

	i = 0;
	len = ft_strlen(str);
	diff = flags.dot - len;
	ret = (char *)malloc(sizeof(*ret) * (diff + len + 1));
	while (i < diff)
		ret[i++] = '0';
	while (i < diff + len)
		ret[i++] = *(str++);
	ret[i] = '\0';
	return (ret);
}

// Adds padding to 'str' when length of 'str'is smaller than 'flags.width' and
// the result is right aligned.
char	*ft_unsigned_right_width(char *str, t_list flags)
{
	int		diff;
	char	*ret;
	int		i;
	int		len;

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
		ret[i++] = *(str++);
	ret[i] = '\0';
	return (ret);
}

// Adds padding to 'str' when length of 'str'is smaller than 'flags.width' and
// the result is left aligned.
char	*ft_unsigned_left_width(char *str, t_list flags)
{
	int		diff;
	char	*ret;
	int		i;
	int		len;

	i = 0;
	len = ft_strlen(str);
	diff = flags.width - len;
	ret = (char *)malloc(sizeof(*ret) * (diff + len + 1));
	while (i < len)
		ret[i++] = *(str++);
	while (i < diff + len)
		ret[i++] = ' ';
	ret[i] = '\0';
	return (ret);
}

// Main int printing function.
int	ft_print_unsigned(t_list flags, va_list args)
{
	unsigned int	n;
	char			*str;

	n = (unsigned int)va_arg(args, int);
	str = ft_utoa(n);
	ft_unsigned_exceptions(&flags, n);
	if (flags.dot == 0 && n == 0)
		return (flags.width);
	if (flags.dot > -1 && ft_strlen(str) < flags.dot)
		str = ft_unsigned_with_precision(str, flags);
	if (flags.width > 0 && flags.minus == 0 && ft_strlen(str) < flags.width)
		str = ft_unsigned_right_width(str, flags);
	if (flags.width > 0 && flags.minus == 1 && ft_strlen(str) < flags.width)
		str = ft_unsigned_left_width(str, flags);
	ft_putstr(str);
	return (ft_strlen(str));
}
