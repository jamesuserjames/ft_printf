

#include "ft_printf.h"

int ft_printf(const char *format, ...)
{
    
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