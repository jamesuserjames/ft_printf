

#include "../ft_printf.h"

int ft_format(char c, va_list args)
{
    
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