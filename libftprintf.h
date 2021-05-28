#ifndef LIBFTPRINTF_H

# define LIBFTPRINTF_H

# include <stdlib.h>
# include <string.h>
# include <stdio.h>
# include <unistd.h>
# include <sys/uio.h>
# include <sys/types.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stdarg.h>

typedef struct s_list
{
	int	width;
	int	minus;
	int	zero;
	int	dot;
	int	count;
}				t_list;

char	*ft_strdup(const char *s1);
size_t	ft_strlen(const char *s);
int		ft_is_identifier(char c);
int	ft_is_conversion(char c);
void	ft_integer_printer(char *format, t_list flags, va_list args);
void	ft_skip(char *str);

# endif
