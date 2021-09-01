#include "../includes/libftprintf.h"

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

// Correctly positions the '-' symbol when 'n' is negative and there is a
// precison.
void	ft_sort(char *ret)
{
	*ret = '-';
	ret++;
	while (*ret != '-')
		ret++;
	*ret = '0';
}
