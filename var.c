#include <stdio.h>
#include <stdarg.h>

void	sum(int num, ...)
{
	va_list args;
	int sum;
	int i;

	sum = 0;
	i = 0;

	va_start(args, num);

	while (i < num)
	{
		sum += va_arg(args, int);
		i++;
	}

	va_end(args);

	printf("Sum: %i\n", sum);
}


void	min(int num, ...)
{
	va_list args;
	int min;
	int tmp;
	int i;

	i = 0;

	va_start(args, num);
	while (i < num)
	{
		if (i == 0)
			min = va_arg(args, int);
		else
			tmp = va_arg(args, int);

		if (tmp < min)
			min = tmp;

		i++;
	}

	va_end(args);

	printf("Min: %i\n", min);
}


void	max(int num, ...)
{
	va_list args;
	int	max;
	int	i;
	int tmp;

	i = 0;

	va_start(args, num);
	while (i < num)
	{
		if (i == 0)
			max = va_arg(args, int);
		else
			tmp = va_arg(args, int);
		if (tmp > max)
			max = tmp;

		i++;
	}

	va_end(args);

	printf("Max: %i\n", max);
}


int	main(void)
{
	max(5, 4, 5, 7, 1, 3);
}
