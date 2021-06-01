#include "libftprintf.h"

// Correctly positions the '-' symbol when 'n' is negative there is a precison.
void	ft_sort(char *ret)
{
	*ret = '-';
	ret++;
	while (*ret != '-')
		ret++;
	*ret = '0';
}

// Adds '0' padding to 'str' when length of 'str' is smaller than 'flags.dot'.
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

// Adds padding to 'str' when length of 'str'is smaller than 'flags.width' and
// the result is right aligned.
char	*ft_str_right_width(char *str, t_list flags)
{
	int diff;
	char *ret;
	int	i;
	int len;

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
char	*ft_str_left_width(char *str, t_list flags)
{
	int	diff;
	char	*ret;
	int	i;
	int	len;

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
int		ft_print_int(t_list flags, va_list args)
{
	int	n;
	int i;
	char *str;

	n = va_arg(args, int);
	str = ft_itoa(n);

	// RULES
	if (flags.dot > -1 && flags.zero == 1)
		flags.zero = 0;

	if (flags.zero == 1 && flags.minus == 1)
		flags.minus = 0;

	//if (flags.dot == 0 && n == 0)
	//	str = "";

	// PRECISION <= LENGTH
	if (flags.dot > -1 && ft_strlen(str) <= flags.dot)
		str = ft_str_with_precision(n, str, flags);

	// WIDTH <= LENGTH && RIGHT ALIGN
	if (flags.width > 0 && flags.minus == 0 && ft_strlen(str) <= flags.width)
		str = ft_str_right_width(str, flags);

	// WIDTH <= LENGHT && LEFT ALIGN
	if (flags.width > 0 && flags.minus == 1 && ft_strlen(str) <= flags.width)
		str = ft_str_left_width(str, flags);

	ft_putstr(str);
	return (ft_strlen(str));
}
