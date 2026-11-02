

#include "../ft_printf.h"

static int	ft_print_digits(long n)
{
	int		count;
	char	c;

	count = 0;
	if (n >= 10)
	{
		count = ft_print_digits(n / 10);
		if (count == -1)
			return (-1);
	}
	c = (n % 10) + '0';
	if (write(1, &c, 1) != 1)
		return (-1);
	return (count + 1);
}

int ft_putnbr_ret(int n)
{
	long	l;
	int		count;
	int		ret;

	l = n;
	count = 0;
	if (l < 0)
	{
		if (write(1, "-", 1) != 1)
			return (-1);
		count = 1;
		l = -l;
	}
	ret = ft_print_digits(l);
	if (ret == -1)
		return (-1);
	return (count + ret);
}

// #include <stdio.h>
// int main(void)
// {
// 	int	count;

// 	count = ft_putnbr_ret(42);
// 	printf("\nreturn: %d\n\n", count);

// 	count = ft_putnbr_ret(0);
// 	printf("\nreturn: %d\n\n", count);

// 	count = ft_putnbr_ret(-123);
// 	printf("\nreturn: %d\n\n", count);

// 	count = ft_putnbr_ret(-2147483648);
// 	printf("\nreturn: %d\n\n", count);
// 	return 0;
// }

/*
DESCRIPTION:
Print a signed decimal integer (%%d / %%i).

RETURN:
Number of characters written, or -1 on write error.
*/