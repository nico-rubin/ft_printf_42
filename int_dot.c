
// Adds '0' padding to 'str' when length of 'str' is smaller than 'flags.dot'.
#include "libftprintf.h"

char *ft_str_with_precision(int n, char *str, t_list flags)
{
	int diff;
	char *ret;
	int i;

	i = 0;
	diff = flags.dot - ft_strlen(str);
	ret = (char *)malloc(sizeof(*ret) * (diff + ft_strlen(str) + 1));
	while (i++ < flags.dot)
		ret[i] = '0';
	while (i++ < ft_strlen(str++))
		ret[i] = *str;
	free(str);
	str = ret;
	free (ret);
	return (str);
}

void	ft_print_int(t_list flags, va_list args)
{
	int	n;
	int i;
	char *str;

	n = va_arg(args, int);
	str = ft_itoa(n);

	int j;

	if (flags.dot > -1)
	{
		if (ft_strlen(str) < flags.dot)
			printf("%s\n", ft_str_with_precision(n, str, flags));
	}
}
