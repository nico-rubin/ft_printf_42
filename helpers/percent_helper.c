/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   percent_helper.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrubin <nrubin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/01 14:37:16 by nrubin            #+#    #+#             */
/*   Updated: 2021/09/02 17:04:32 by nrubin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

// Handles exceptional flag cases.
void	ft_percent_exceptions(t_list *flags)
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

// Adds padding to 'str' when length of 'str'is smaller than 'flags.width' and
// the result is right aligned.
char	*ft_percent_right_width(char *str, t_list flags)
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
char	*ft_percent_left_width(char *str, t_list flags)
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
int	ft_print_percent(t_list flags)
{
	char	*str;
	int		len;

	str = ft_strdup("%");
	ft_percent_exceptions(&flags);
	if (flags.width > 0 && flags.minus == 0)
		str = ft_percent_right_width(str, flags);
	if (flags.width > 0 && flags.minus == 1)
		str = ft_percent_left_width(str, flags);
	ft_putstr(str);
	len = ft_strlen(str);
	free(str);
	return (len);
}
