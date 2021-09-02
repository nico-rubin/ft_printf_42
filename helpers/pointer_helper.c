/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pointer_helper.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrubin <nrubin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/01 14:37:45 by nrubin            #+#    #+#             */
/*   Updated: 2021/09/02 18:20:05 by nrubin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

// Handles exceptional flag cases.
void	ft_pointer_exceptions(t_list *flags)
{
	if (flags->width < 0)
	{
		flags->width = flags->width * -1;
		flags->minus = 1;
	}
	if (flags->dot > -1 && flags->zero == 1)
		flags->zero = 0;
	if (flags->zero == 1 && flags->minus == 1)
		flags->zero = 0;
}

// Adds '0' padding to 'str' when length of 'str' is smaller than 'flags.dot'.
char	*ft_pointer_with_precision(char *str, t_list flags)
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
char	*ft_pointer_right_width(char *str, t_list flags)
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
char	*ft_pointer_left_width(char *str, t_list flags)
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
int	ft_print_pointer(t_list flags, va_list args)
{
	void	*p;
	char	*str;
	int		len;

	p = va_arg(args, void *);
	if (p == NULL)
		str = ft_strdup("0x0");
	else
		str = ft_to_pointer((unsigned long)p);
	ft_pointer_exceptions(&flags);
	if (flags.dot > -1 && ft_strlen(str) < flags.dot)
		str = ft_pointer_with_precision(str, flags);
	if (flags.width > 0 && flags.minus == 0 && ft_strlen(str) < flags.width)
		str = ft_pointer_right_width(str, flags);
	if (flags.width > 0 && flags.minus == 1 && ft_strlen(str) < flags.width)
		str = ft_pointer_left_width(str, flags);
	ft_putstr(str);
	len = ft_strlen(str);
	free(str);
	return (len);
}
