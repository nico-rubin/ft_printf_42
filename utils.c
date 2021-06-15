#include "includes/libftprintf.h"

int	ft_strlen(const char *s)
{
	int	size;

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
	if (c == '-' || c == '.' || (c >= '0' && c <= '9') || c == '*')
		return (1);
	else
		return (0);
}

int	ft_is_conversion(char c)
{
	if (c == 'c' || c == 's' || c == 'p' || c == 'd' || c == 'i' || c == 'u'
		|| c == 'x' || c == 'X')
		return (1);
	else
		return (0);
}

void	ft_skip(char *str)
{
	if (ft_is_identifier(*str))
		str++;
}

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

void	ft_putstr(char *str)
{
	while (*str)
		ft_putchar(*(str++));
}

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
	ret = (char *)malloc(sizeof(*ret) * (ft_strlen(stock) + 1));
	ret = ft_strdup(stock);
	return (ret);
}

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
	ret = (char *)malloc(sizeof(*ret) * (ft_strlen(stock) + 1));
	ret = ft_strdup(stock);
	return (ret);
}

char	*ft_to_pointer(unsigned long p)
{
	int		remainder;
	char	stock[50];
	char	*ret;
	int		i;

	i = 0;
	while (p)
	{
		remainder = p % 16;
		p = p / 16;
		if (remainder < 10)
			remainder = remainder + '0';
		else
			remainder = (remainder - 10) + 'a';
		stock[i++] = remainder;
	}
	stock[i++] = 'x';
	stock[i++] = '0';
	stock[i++] = '\0';
	ft_flip(stock);
	ret = (char *)malloc(sizeof(*ret) * (ft_strlen(stock) + 1));
	ret = ft_strdup(stock);
	return (ret);
}

char	*ft_utoa(unsigned int n)
{
	long		size;
	char		*ret;

	size = ft_count_digits(n);
	ret = (char *)malloc(sizeof(*ret) * (size + 1));
	if (!ret)
		return (NULL);
	ret[size] = '\0';
	size--;
	while (size >= 0)
	{
		ret[size] = n % 10 + '0';
		size--;
		n = n / 10;
	}
	return (ret);
}

int	ft_atoi(const char *str)
{
	int	res;
	int	sign;

	sign = 1;
	res = 0;
	while (*str == 32 || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		res = res * 10 + *str - '0';
		str++;
	}
	return (res * sign);
}
