#include "libftprintf.h"

void	ft_print_int(t_list flags, va_list args)
{
	int	n;
	int i;
	char *str;

	n = va_arg(args, int);
	str = ft_itoa(n);

	// width
	if (flags.width > 0)
	{
		i = flags.width - ft_strlen(str);
		if (flags.minus == 0)
		{
			while (i--)
					printf(" ");
			printf("%i\n", n);
		}
		else
		{
			printf("%i", n);
			while (i--)
			{
				printf(" ");
			}
			printf("\n");
		}
	}
}