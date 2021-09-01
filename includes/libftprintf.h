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
int		ft_strlen(const char *s);
int		ft_is_identifier(char c);
int		ft_is_conversion(char c);
void	ft_integer_printer(char *format, t_list flags, va_list args);
void	ft_skip(char *str);
char	*ft_itoa(int n);
void	ft_if_neg(long *size, long *nbr);
long	ft_count_digits(long n);
int		ft_print_int(t_list flags, va_list args);
int		ft_print_char(t_list flags, va_list args);
int		ft_print_str(t_list flags, va_list args);
int		ft_print_low_hex(t_list flags, va_list args);
int		ft_print_up_hex(t_list flags, va_list args);
void	ft_putchar_n(char c, int *count);
void	ft_putchar(char c);
void	ft_putstr(char *str);
char	*ft_char_to_str(char c);
char	*ft_to_low_hex(int n);
char	*ft_to_up_hex(int n);
void	ft_flip(char *str);
char	*ft_to_pointer(unsigned long p);
int		ft_print_pointer(t_list flags, va_list args);
char	*ft_utoa(unsigned int n);
int		ft_print_unsigned(t_list flags, va_list args);
void	ft_unsigned_exceptions(t_list *flags, unsigned int n);
int		ft_atoi(const char *str);
int		ft_print_percent(t_list flags);
void	ft_sort(char *ret);
char	*ft_parser(char *format, t_list *flags, va_list args);
int		ft_printf(const char *str, ...);
int		ft_zero_zero(void);

#endif
