#include "libftprintf.h"

size_t	ft_strlen(const char *s)
{
	size_t	size;

	size = 0;
	while (s[size])
		size++;
	return (size);
}

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

int	ft_is_identifier(char c)
{
	if (c == '-' || c == '.' || (c >= '0' && c <= '9'))
		return (1);
	else
		return (0);
}

int	ft_is_conversion(char c)
{
	if (c == 'c' || c == 's' || c == 'p' || c == 'd' || c == 'i' || c == 'u' || c == 'x' || c == 'X')
		return (1);
	else
		return (0);
}

void	ft_skip(char *str)
{
	if (ft_is_identifier(*str))
		str++;
}

int	ft_count_digits(int n)
{
	int	i;

	i = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

// Workaround for the line number limit.

void	ft_if_neg(int *size, long *nbr)
{
	(*size)++;
	*nbr *= -1;
}

// Allocates (with malloc(3)) and returns a string representing the integer
// received as an argument. It handles negative numbers.

char	*ft_itoa(int n)
{
	int		size;
	char	*ret;
	long	nbr;

	nbr = n;
	size = 0;
	if (nbr < 0)
		ft_if_neg(&size, &nbr);
	size = size + ft_count_digits(nbr);
	ret = (char *)malloc(sizeof(*ret) * (size + 1));
	if (!ret)
		return (NULL);
	ret[size] = '\0';
	size--;
	while (size >= 0)
	{
		ret[size] = nbr % 10 + '0';
		size--;
		nbr = nbr / 10;
	}
	if (n < 0)
		ret[0] = '-';
	return (ret);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putchar_n(char c, int *count)
{
	write(1, &c, 1);
	*count += 1;
}

void	ft_putstr(char *str)
{
	while(*str)
		ft_putchar(*(str++));
}
