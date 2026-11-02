

#include "../ft_printf.h"

int	ft_putstr_ret(char *str)
{
	int		i;
	
	i = 0;
	if (!str)
		str = "(null)";
	while (str[i])
		i++;
	return (write(1, str, i));
}

// #include <stdio.h>
// int main(void)
// {
// 	int	count;

// 	count = ft_putstr_ret("Hello");
// 	printf("\nreturn: %d\n\n", count);

// 	count = ft_putstr_ret("");
// 	printf("\nreturn: %d\n\n", count);

// 	count = ft_putstr_ret("42");
// 	printf("\nreturn: %d\n\n", count);

// 	count = ft_putstr_ret(NULL);
// 	printf("\nreturn: %d\n\n", count);

// 	return 0;
// }

/*
DESCRIPTION:
Print a NUL-terminated string to standard output.
If str is NULL, print "(null)".

RETURN:
Number of bytes written, or -1 on write error.
*/