

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

/*
DESCRIPTION:
Read the format string and print plain text or formatted arguments.

RETURN:
Total number of bytes printed, or -1 on write error.

TODO:
1. Initialize va_list using va_start.
2. Walk through format with an index.
3. For '%' followed by a conversion, call ft_format.
4. Otherwise print the literal character with ft_putchar_ret.
5. Check each helper's result BEFORE adding it to the count.
6. Always call va_end after va_start, even on write errors.
7. Return the total or -1.
NOTE: Follow your subject's behavior for trailing '%' and NULL format.
*/