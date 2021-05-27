#include <stdarg.h>
# include <stdlib.h>
# include <string.h>
# include <stdio.h>
# include <unistd.h>
# include <sys/uio.h>
# include <sys/types.h>
# include <fcntl.h>
# include <stdlib.h>

size_t	ft_strlen(const char *s)
{
	size_t	size;

	size = 0;
	while (s[size])
		size++;
	return (size);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *s)
{
	if (!s)
		return ;
	write(1, s, ft_strlen(s));
}

void	ft_putnbr(int n)
{
	unsigned int	unsigned_n;

	if (n < 0)
	{
		unsigned_n = (-1 * n);
		ft_putchar('-');
	}
	else
		unsigned_n = (unsigned int)n;
	if (unsigned_n >= 10)
	{
		ft_putnbr(unsigned_n / 10);
		ft_putnbr(unsigned_n % 10);
	}
	else
		ft_putchar(unsigned_n + '0');
}

int	min_printf(const char *str, ...)
{
	va_list args;
	char *p_string;
	int p_integer;
	char p_char;

	va_start(args, str);
	while (*str)
	{
			if (*str == '%' && *(str+1) == 's')
			{
				p_string = va_arg(args, char *);
				ft_putstr(p_string);
				str++;
			}

			else if (*str == '%' && *(str+1) == 'c')
			{
				p_char = va_arg(args, int);
				ft_putchar(p_char);
				str++;
			}

			else if (*str == '%' && *(str+1) == 'i')
			{
				p_integer = va_arg(args, int);
				ft_putnbr(p_integer);
				str++;
			}

			else if (*str == '%' && *(str+1) == '%')
			{
				ft_putchar('%');
				str++;
			}

			else
			{
				ft_putchar(*str);
			}

			str++;
	}

	return (0);
}

int	main(void)
{
	min_printf("%%Hello %s%c you are %i.\n", "Nicolas", ',', 25);
	return (0);
}
