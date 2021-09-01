#include "../includes/libftprintf.h"

long	ft_count_digits(long n)
{
	long	i;

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

void	ft_if_neg(long *size, long *nbr)
{
	(*size)++;
	*nbr *= -1;
}

// Allocates (with malloc(3)) and returns a string representing the integer
// received as an argument. It handles negative numbers.

char	*ft_itoa(int n)
{
	long		size;
	char		*ret;
	long		nbr;

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