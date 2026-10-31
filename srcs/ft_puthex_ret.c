

#include "../ft_printf.h"

int ft_puthex_ret(unsigned int n, char format)
{
	char	*base;
	char	c;
	int		count;
	
	count = 0;
	if (format >= 'a' && format <= 'z')
		base = "0123456789abcdefg";
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

int	main(void)
{
	int	ret;
	
	printf("Test 1: 255 lowercase\n");
	printf("Expected: ff\n");
	printf("Actual:   ");
	fflush(stdout);
	ret = ft_puthex_ret(255, 'x');
	printf("\nReturn: %d (expected: 2)\n\n", ret);
	printf("Test 2: 255 uppercase\n");
	printf("Expected: FF\n");
	printf("Actual:   ");
	fflush(stdout);
	ret = ft_puthex_ret(255, 'X');
	printf("\nReturn: %d (expected: 2)\n\n", ret);
	printf("Test 3: Zero\n");
	printf("Expected: 0\n");
	printf("Actual:   ");
	fflush(stdout);
	ret = ft_puthex_ret(0, 'x');
	printf("\nReturn: %d (expected: 1)\n\n", ret);
	printf("Test 4: UINT_MAX\n");
	printf("Expected: ffffffff\n");
	printf("Actual:   ");
	fflush(stdout);
	ret = ft_puthex_ret(4294967295U, 'x');
	printf("\nReturn: %d (expected: 8)\n\n", ret);
	printf("Test 5: 16 lowercase\n");
	printf("Expected: 10\n");
	printf("Actual:   ");
	fflush(stdout);
	ret = ft_puthex_ret(16, 'x');
	printf("\nReturn: %d (expected: 2)\n\n", ret);
	return (0);
}

/*
EXSPEXTED OUTPUT:

Test 1: 255 lowercase
Expected: ff
Actual:   ff
Return: 2 (expected: 2)

Test 2: 255 uppercase
Expected: FF
Actual:   FF
Return: 2 (expected: 2)

Test 3: Zero
Expected: 0
Actual:   0
Return: 1 (expected: 1)

Test 4: UINT_MAX
Expected: ffffffff
Actual:   ffffffff
Return: 8 (expected: 8)

Test 5: 16 lowercase
Expected: 10
Actual:   10
Return: 2 (expected: 2)

DESCRIPTION:
Print an unsigned integer in hexadecimal.
format == 'x' -> 0123456789abcdef
format == 'X' -> 0123456789ABCDEF

RETURN:
Number of characters written, or -1 on write error.

TODO:
1. Choose the alphabet based on format.
2. Convert n to base 16, including zero.
3. Return the number of printed characters.
*/