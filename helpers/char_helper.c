#include "../includes/libftprintf.h"

// Handles exceptional flag cases.
void	ft_char_exceptions(t_list *flags)
{
	if (flags->dot > -1 && flags->zero == 1)
		flags->zero = 0;

	if (flags->zero == 1 && flags->minus == 1)
		flags->minus = 0;
}

// Adds padding to 'str' when length of 'str'is smaller than 'flags.width' and
// the result is right aligned.
char	*ft_char_right_width(char *str, t_list flags)
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
char	*ft_char_left_width(char *str, t_list flags)
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
int		ft_print_char(t_list flags, va_list args)
{
	char c;
	char *str;

	c = va_arg(args, int);
	str = ft_char_to_str(c);
	ft_char_exceptions(&flags);

	if (flags.width > 0 && flags.minus == 0 && ft_strlen(str) <= flags.width)
		str = ft_char_right_width(str, flags);
	if (flags.width > 0 && flags.minus == 1 && ft_strlen(str) <= flags.width)
		str = ft_char_left_width(str, flags);
	ft_putstr(str);
	return (ft_strlen(str));
}