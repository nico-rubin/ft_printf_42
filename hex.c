#include "libftprintf.h"

void	ft_flip(char **str)
{
	char tmp;
	int i;
	int len;
	int half;

	i = 0;
	len = ft_strlen(str) / 2;
	half = len / 2;
	while (len > half)
	{
		tmp = str[len - 1];
		str[len - 1] = str[i];
		str[i] = tmp;
		len--;
		i++;
	}
}

char *ft_to_hex(int n)
{
	int i;
	int tmp;
	char hexadecimal[50];
	char *ret;

	i = 0;
	while (n != 0)
	{
		tmp = n % 16;
		if (tmp < 10)
			tmp = tmp + 'A';
		else
			tmp = tmp + 55;
		hexadecimal[i++] = tmp;
		n = n / 16;
	}
	hexadecimal[i] = '\0';
	ret = ft_strdup(hexadecimal);
	ft_flip(&ret);
	return (ret);
}

int	main(void)
{
	ft_to_hex(-7562);
}
