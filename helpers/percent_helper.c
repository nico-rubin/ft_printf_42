#include "../includes/libftprintf.h"

// Handles exceptional flag cases.
void	ft_percent_exceptions(t_list *flags)
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

// Adds padding to 'str' when length of 'str'is smaller than 'flags.width' and
// the result is left aligned.
char	*ft_percent_width(t_list flags)
{
	char	*ret;
	int	i;
	int	len;

	i = 0;
	len = flags.width;
	ret = (char *)malloc(sizeof(*ret) * (len + 1));
	while (i < len)
		if (flags.zero == 1)
			ret[i++] = '0';
		else
			ret[i++] = ' ';
	ret[i] = '\0';
	return (ret);
}

// Main int printing function.
int		ft_print_percent(t_list flags)
{
	char *str = NULL;

	if (flags.width > 0)
		str = ft_percent_width(flags);
	ft_putstr(str);
	return (ft_strlen(str));
}
