// Adds '0' padding to 'str' when length of 'str' is smaller than 'flags.dot'.
#include "libftprintf.h"

void	ft_sort(char *ret)
{
	*ret = '-';
	ret++;
	while (*ret != '-')
		ret++;
	*ret = '0';
}

char *ft_str_with_precision(int n, char *str, t_list flags)
{
	int diff;
	char *ret;
	int i;
	int len;

	i = 0;
	len = ft_strlen(str);
	diff = flags.dot - len;
	if (n < 0)
		diff++;
	ret = (char *)malloc(sizeof(*ret) * (diff + len + 1));
	while (i < diff)
		ret[i++] = '0';
	while (i < diff + len)
		ret[i++] = *(str++);
	ret[i] = '\0';
	if (n < 0)
		ft_sort(ret);
	return (ret);
}

void	ft_print_int(t_list flags, va_list args)
{
	int	n;
	int i;
	char *str;
	char *tmp;

	n = va_arg(args, int);
	str = ft_itoa(n);

	int j;

	if (flags.dot > -1 && ft_strlen(str) <= flags.dot)
	{
		tmp = ft_str_with_precision(n, str, flags);
		free(str);
		str = tmp;
		free(tmp);
	}

	if (flags.width > 0)
	{
		if (flags.width > ft_strlen(str))
		{
			i = flags.width - ft_strlen(str);
			if (flags.minus == 0)
			{
				while (i--)
						printf(" ");
				printf("%s", str);
			}
			else
			{
				printf("%s", str);
				while (i--)
				{
					printf(" ");
				}
			}
		}
		else
			printf("%s", str);
	}

	else
		printf("%s", str);
}
/*
	// precision
	// The precision specifies the minimum number of digits to be printed. If the number
	// of digits in the argument is less than precision, the output value is padded on the
	// left with zeros. The value isn't truncated when the number of digits exceeds precision.
	int j;

	if (flags.width == 0 && flags.dot > -1)
	{
		j = flags.dot - ft_strlen(str);
		if (ft_strlen(str) < flags.dot)
		{
			while (j--)
				printf("0");
			printf("%i\n", n);
		}
		else
			printf("%i\n", n);
	}
int k;
int y;
int z;

if (flags.width > 0 && flags.dot > -1)
{
	if (flags.width > flags.dot)
	{
		if (flags.dot > ft_strlen(str))
		{
			k = flags.width - flags.dot;
			while (k--)
				printf(" ");
			y = flags.dot - ft_strlen(str);
			while (y--)
				printf("0");
			printf("%i", n);
		}
		if (flags.dot <= ft_strlen(str))
		{
			k = flags.width - ft_strlen(str);
			while (k--)
				printf(" ");
			printf("%i", n);
		}
	}

	if (flags.width <= flags.dot)
	{
		if (flags.dot > ft_strlen(str))
		{
			k = flags.dot - ft_strlen(str);
			while (k--)
				printf("0");
			printf("%i", n);
		}
		if (flags.dot <= ft_strlen(str))
			printf("%i", n);
	}
}
}
// IF flags.width AND flags.precison EXIST

	// IF flags.width > flags.precison

		// IF flags.precision > ft_strlen(str)

			// PRINT flags.width

			// PRINT flags.precison

			// PRINT str

		// IF flags.precison <= ft_strlen(str)

			// PRINT flags.width

			// PRINT str

	// IF flags.width <= flags.precison

		// IF flags.precison > ft_strlen(str)

			// PRINT flags.precison

			// PRINT str

		// IF flags.precison <= ft_stlren(str)

			// PRINT str
*/
