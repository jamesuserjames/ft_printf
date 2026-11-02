

#include "../ft_printf.h"

static int	ft_print_address(unsigned long n)
{
	char	c;
	int		count;

	count = 0;
	if (n >= 16)
	{
		count = ft_print_address(n / 16);
		if (count == -1)
			return (-1);
	}
	c = "0123456789abcdef"[n % 16];
	if (write(1, &c, 1) != 1)
		return (-1);
	return (count + 1);
}

int	ft_putptr_ret(void *ptr)
{
	unsigned long	address;
	int				count;
	int				ret;

	if (ptr == NULL)
	{
		if (write(1, "(nil)", 5) != 5)
			return (-1);
		return (5);
	}
	address = (unsigned long)ptr;
	count = write(1, "0x", 2);
	if (count != 2)
		return (-1);
	ret = ft_print_address(address);
	if (ret == -1)
		return (-1);
	return (count + ret);
}

// int	main(void)
// {
// 	int	n;
// 	int	ret;

// 	n = 42;
// 	printf("Test 1: Integer address\n");
// 	printf("Expected: %p\nActual:   ", (void *)&n);
// 	fflush(stdout);
// 	ret = ft_putptr_ret(&n);
// 	printf("\nReturn: %d\n\n", ret);

// 	printf("Test 2: NULL\nExpected: (nil)\nActual:   ");
// 	fflush(stdout);
// 	ret = ft_putptr_ret(NULL);
// 	printf("\nReturn: %d (expected: 5)\n\n", ret);

// 	printf("Test 3: Small address\nExpected: 0x1\nActual:   ");
// 	fflush(stdout);
// 	ret = ft_putptr_ret((void *)1);
// 	printf("\nReturn: %d (expected: 3)\n\n", ret);

// 	printf("Test 4: Hex address\nExpected: 0xff\nActual:   ");
// 	fflush(stdout);
// 	ret = ft_putptr_ret((void *)255);
// 	printf("\nReturn: %d (expected: 4)\n\n", ret);

// 	printf("Test 5: Large address\nExpected: 0xabcdef123456\nActual:   ");
// 	fflush(stdout);
// 	ret = ft_putptr_ret((void *)0xabcdef123456UL);
// 	printf("\nReturn: %d (expected: 14)\n", ret);
// 	return (0);
// }

/*
DESCRIPTION:
Print a pointer address (%%p), typically as 0x followed by lowercase hex.

RETURN:
Number of characters written, or -1 on write error.
*/