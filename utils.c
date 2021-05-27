#include "libftprintf.h"

size_t	ft_strlen(const char *s)
{
	size_t	size;

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
	if (c == '-' || c == '.' || (c >= '0' && c <= '9'))
		return (1);
	else
		return (0);
}
