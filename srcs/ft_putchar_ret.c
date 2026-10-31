

#include "../ft_printf.h"

int	ft_putchar_ret(char c)
{
	return (write(1, &c, 1));
}

#include <stdio.h>
int main(void)
{
	int	count;

	count = ft_putchar_ret('A');
	printf("\nreturn: %d\n\n", count);

	count = ft_putchar_ret('0');
	printf("\nreturn: %d\n\n", count);

	ft_putchar_ret('0');
	printf("\nreturn: %d\n\n", count);

	return 0;
}

/*
DESCRIPTION:
Print one character to standard output (file descriptor 1).

RETURN:
1 on success, -1 if write fails.

TODO:
Use write(1, &c, 1) and return its result.
*/