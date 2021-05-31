#include "libftprintf.h"

void	ft_print_int(t_list flags, va_list args)
{
	int	n;
	int i;
	char *str;

	n = va_arg(args, int);
	str = ft_itoa(n);

	// width
	// The width argument is a non-negative decimal integer that controls the minimum number of 
	// characters that are output. If the number of characters in the output value is less than
	// the specified width, blanks are added to the left or the right of the values—depending
	// on whether the left-alignment flag (-) is specified—until the minimum width is reached.
	// The width specification never causes a value to be truncated. 
	// If the number of characters in the output value is greater than the specified width, 
	// or if width isn't provided, all characters of the value are output, 
	// subject to the precision specification.

	if (flags.width > 0 && flags.dot == -1)
	{
		if (flags.width > ft_strlen(str))
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
		else
			printf("%i\n", n);
	}

	// precision
	// The precision specifies the minimum number of digits to be printed. If the number
	// of digits in the argument is less than precision, the output value is padded on the
	// left with zeros. The value isn't truncated when the number of digits exceeds precision.
	int j;

	if (flags.width == 0 && flags.dot > -1)
	{
		j = flags.dot - ft_strlen(str);
		if (ft_strlen(str) < flags.dot)
		{
			while (j--)
				printf("0");
			printf("%i\n", n);
		}
		else
			printf("%i\n", n);
	}
int k;
int y; 
int z;

if (flags.width > 0 && flags.dot > -1)
{
	if (flags.width > flags.dot)
	{
		if (flags.dot > ft_strlen(str))
		{
			k = flags.width - flags.dot;
			while (k--)
				printf(" ");
			y = flags.dot - ft_strlen(str);
			while (y--)
				printf("0");
			printf("%i", n);
		}
		if (flags.dot <= ft_strlen(str))
		{
			k = flags.width - ft_strlen(str);
			while (k--)
				printf(" ");
			printf("%i", n);
		}
	}

	if (flags.width <= flags.dot)
	{
		if (flags.dot > ft_strlen(str))
		{
			k = flags.dot - ft_strlen(str);
			while (k--)
				printf("0");
			printf("%i", n);
		}
		if (flags.dot <= ft_strlen(str))
			printf("%i", n);
	}
}
}
// IF flags.width AND flags.precison EXIST

	// IF flags.width > flags.precison

		// IF flags.precision > ft_strlen(str)

			// PRINT flags.width

			// PRINT flags.precison

			// PRINT str

		// IF flags.precison <= ft_strlen(str)

			// PRINT flags.width

			// PRINT str
	
	// IF flags.width <= flags.precison

		// IF flags.precison > ft_strlen(str)

			// PRINT flags.precison

			// PRINT str

		// IF flags.precison <= ft_stlren(str)

			// PRINT str

