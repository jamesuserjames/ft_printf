

#include "ft_printf.h"

static int	ft_process(const char *format, va_list args)
{
	int	i;
	int	count;
	int	ret;

	i = 0;
	count = 0;
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1])
			ret = ft_format(format[++i], args);
		else
			ret = ft_putchar_ret(format[i]);
		if (ret == -1)
			return (-1);
		count += ret;
		i++;
	}
	return (count);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		count;

	va_start(args, format);
	count = ft_process(format, args);
	va_end(args);
	return (count);
}

#include <stdio.h>
#include <limits.h>

int	main(void)
{
	int		n;
	int		ret;
	int		ret2;
	char	*str;
	void	*ptr;

	n = 42;
	str = "hello world";
	ptr = &n;

	ft_printf("char: %c\n", 'A');
	printf("char: %c\n", 'A');

	ft_printf("string: %s\n", str);
	printf("string: %s\n", str);

	ft_printf("pointer: %p\n", ptr);
	printf("pointer: %p\n", ptr);

	ft_printf("numbers: %d %i\n", INT_MIN, INT_MAX);
	printf("numbers: %d %i\n", INT_MIN, INT_MAX);

	ft_printf("unsigned: %u\n", UINT_MAX);
	printf("unsigned: %u\n", UINT_MAX);

	ft_printf("hex: %x %X\n", 255, 255);
	printf("hex: %x %X\n", 255, 255);

	ft_printf("percent: %%\n");
	printf("percent: %%\n");

	ret = ft_printf("test %s %d\n", "number", n);
	ret2 = printf("test %s %d\n", "number", n);

	printf("return ft_printf: %d\n", ret);
	printf("return printf: %d\n", ret2);
	return (0);
}

/*
make
cc -Wall -Wextra -Werror libftprintf.a -o test.out
./test.out

make fclean
make
cc -Wall -Wextra -Werror libftprintf.a -o test.out
./test.out
*/