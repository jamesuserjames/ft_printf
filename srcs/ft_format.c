

#include "../ft_printf.h"

int	ft_format(char c, va_list args)
{
	if (c == 'c')
		return (ft_putchar_ret(va_arg(args, int)));
	if (c == 's')
		return (ft_putstr_ret(va_arg(args, char *)));
	if (c == 'p')
		return (ft_putptr_ret(va_arg(args, void *)));
	if (c == 'd' || c == 'i')
		return (ft_putnbr_ret(va_arg(args, int)));
	if (c == 'u')
		return (ft_putunsigned_ret(va_arg(args, unsigned int)));
	if (c == 'x' || c == 'X')
		return (ft_puthex_ret(va_arg(args, unsigned int), c));
	if (c == '%')
		return (ft_putchar_ret('%'));
	return (-1);
}

/*
DESCRIPTION:
Dispatch a format character to the correct printing helper.
Supported: c, s, p, d, i, u, x, X, %.

RETURN:
Number of bytes printed, or -1 on write error.

TODO:
Use if statements (or else if) and va_arg(args, TYPE).
Types: c=int, s=char *, p=void *, d/i=int, u/x/X=unsigned int.
A literal percent sign consumes no variadic argument.
Follow your subject's rules for unsupported formats.
*/