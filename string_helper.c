#include "libftprintf.h"

#include "libftprintf.h"

// Handles exceptional flag cases.
void	ft_str_exceptions(t_list *flags, char *str)
{
	if (flags->dot > -1 && flags->zero == 1)
		flags->zero = 0;

	if (flags->zero == 1 && flags->minus == 1)
		flags->minus = 0;

	/*if (flags->dot == 0)
	{
		char *ret;
		int i;
		i = flags->width;
		ret = (char *)malloc(sizeof(*ret) * (i + 1));
		ret[i] = '\0';
		while (i--)
			ret[i] = ' ';
		ft_putstr(ret);
		free(ret);
	}
	*/
}

// Adds '0' padding to 'str' when length of 'str' is smaller than 'flags.dot'.
char *ft_str_with_precision(char *str, t_list flags)
{
	char *ret;
	int i;
	int len;

	i = 0;
	len = flags.dot;
	ret = (char *)malloc(sizeof(*ret) * (len + 1));
	ret[len] = '\0';
	while (len--)
		ret[len] = str[len];
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
int		ft_print_str(t_list flags, va_list args)
{
	char *s;
	int i;
	char *str;

	str = ft_strdup(va_arg(args, char *));
	ft_str_exceptions(&flags, str);

	if (flags.dot > -1)
		str = ft_str_with_precision(str, flags);
	if (flags.width > 0 && flags.minus == 0 && ft_strlen(str) <= flags.width)
		str = ft_str_right_width(str, flags);
	if (flags.width > 0 && flags.minus == 1 && ft_strlen(str) <= flags.width)
		str = ft_str_left_width(str, flags);
	ft_putstr(str);
	return (ft_strlen(str));
}
