

#include "../ft_printf.h"

int ft_puthex_ret(unsigned int n, char format)
{
	char	*base;
	char	c;
	int		count;
	
	count = 0;
	if (format >= 'a' && format <= 'z')
		base = "0123456789abcdef";
	else if (format >= 'A' && format <= 'Z')
		base = "0123456789ABCDEF";
	if (n >= 16)
	{
		count = ft_puthex_ret(n / 16, format);
		if (count == -1)
			return (-1);
	}
	c = base[n % 16];
	if (write(1, &c, 1) != 1)
		return (-1);
	return (count + 1);
}

// int	main(void)
// {
// 	int	ret;
	
// 	ret = ft_puthex_ret(255, 'x');
// 	printf("\nReturn: %d (expected: 2)\n\n", ret);
// 	ret = ft_puthex_ret(255, 'X');
// 	printf("\nReturn: %d (expected: 2)\n\n", ret);
// 	ret = ft_puthex_ret(4294967295U, 'x');
// 	printf("\nReturn: %d (expected: 8)\n\n", ret);
// 	return (0);
// }

/*
DESCRIPTION:
Print an unsigned integer in hexadecimal.
format == 'x' = 0123456789abcdef
format == 'X' = 0123456789ABCDEF

RETURN:
Number of characters written, or -1 on write error.
*/