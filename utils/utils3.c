/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrubin <nrubin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/01 14:38:23 by nrubin            #+#    #+#             */
/*   Updated: 2021/09/03 13:58:33 by nrubin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

// Writes a string.
void	ft_putstr(char *str)
{
	while (*str)
		ft_putchar(*(str++));
}

// Converts a char into a null ended string containing the single char.
char	*ft_char_to_str(char c)
{
	char	*ret;

	ret = (char *)malloc(sizeof(*ret) * (2));
	if (!ret)
		return (NULL);
	ret[0] = c;
	ret[1] = '\0';
	return (ret);
}

// Flips a string around.
void	ft_flip(char *str)
{
	char	tmp;
	int		i;
	int		len;
	int		k;

	i = 0;
	len = ft_strlen(str);
	k = len / 2;
	while (len > k)
	{
		tmp = str[i];
		str[i] = str[len - 1];
		str[len - 1] = tmp;
		i++;
		len--;
	}
}

// Converts an integer to lowercase hexadecimal.
char	*ft_to_low_hex(int n)
{
	unsigned int	nbr;
	int				remainder;
	char			stock[50];
	char			*ret;
	int				i;

	nbr = (unsigned int)n;
	i = 0;
	if (nbr == 0)
		return (ft_strdup("0"));
	while (nbr)
	{
		remainder = nbr % 16;
		nbr = nbr / 16;
		if (remainder < 10)
			remainder = remainder + '0';
		else
			remainder = (remainder - 10) + 'a';
		stock[i++] = remainder;
	}
	stock[i] = '\0';
	ft_flip(stock);
	ret = ft_strdup(stock);
	return (ret);
}

// Converts an integer to uppercase hexadecimal.
char	*ft_to_up_hex(int n)
{
	unsigned int	nbr;
	int				remainder;
	char			stock[50];
	char			*ret;
	int				i;

	nbr = (unsigned int)n;
	i = 0;
	if (nbr == 0)
		return (ft_strdup("0"));
	while (nbr)
	{
		remainder = nbr % 16;
		nbr = nbr / 16;
		if (remainder < 10)
			remainder = remainder + '0';
		else
			remainder = (remainder - 10) + 'A';
		stock[i++] = remainder;
	}
	stock[i] = '\0';
	ft_flip(stock);
	ret = ft_strdup(stock);
	return (ret);
}
