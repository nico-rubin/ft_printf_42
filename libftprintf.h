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
char	*ft_itoa(int n);
void	ft_if_neg(int *size, long *nbr);
int	ft_count_digits(int n);
int	ft_print_int(t_list flags, va_list args);
int		ft_print_char(t_list flags, va_list args);
void	ft_putchar_n(char c, int *count);
void	ft_putchar(char c);
void	ft_putstr(char *str);
char	*ft_char_to_str(char c);

# endif
