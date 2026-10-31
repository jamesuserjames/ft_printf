

#include "../ft_printf.h"

int	ft_putunsigned_ret(unsigned int n)
{
	char	c;
	int		count;

	count = 0;
	if (n >= 10)
	{
		count = ft_putunsigned_ret(n / 10);
		if (count == -1)
			return (-1);
	}
	c = (n % 10) + '0';
	if (write(1, &c, 1) != 1)
		return (-1);
	return (count + 1);
}

int main(void)
{
	ft_putunsigned_ret(42);
	ft_putunsigned_ret(0);
	ft_putunsigned_ret(4294967295U);
	return 0;
}

/*
DESCRIPTION:
Print an unsigned decimal integer (%%u).

RETURN:
Number of characters written, or -1 on write error.

TODO:
Print each base-10 digit in order. Handle 0 and UINT_MAX.
You can use recursion, or a small local character buffer.
*/