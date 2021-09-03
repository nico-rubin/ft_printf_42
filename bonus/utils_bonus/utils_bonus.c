/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrubin <nrubin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/01 14:38:16 by nrubin            #+#    #+#             */
/*   Updated: 2021/09/03 15:10:25 by nrubin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes_bonus/ft_printf_bonus.h"

// Counts lenght of string.
int	ft_strlen(const char *s)
{
	int	size;

	size = 0;
	while (s[size])
		size++;
	return (size);
}

// Duplicates string.
char	*ft_strdup(const char *s1)
{
	char	*ret;
	size_t	len;

	len = ft_strlen(s1);
	ret = (char *)malloc(sizeof(*ret) * (len + 1));
	if (!ret)
		return (NULL);
	ret[len] = '\0';
	while (len--)
		ret[len] = s1[len];
	return (ret);
}

// Checks if char is a flag.
int	ft_is_identifier(char c)
{
	if (c == '-' || c == '.' || (c >= '0' && c <= '9') || c == '*')
		return (1);
	else
		return (0);
}

// Checks if char is a format specifier.
int	ft_is_conversion(char c)
{
	if (c == 'c' || c == 's' || c == 'p' || c == 'd' || c == 'i' || c == 'u'
		|| c == 'x' || c == 'X')
		return (1);
	else
		return (0);
}

// Skips char if it is a flag.
void	ft_skip(char *str)
{
	if (ft_is_identifier(*str))
		str++;
}
