#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stddef.h>
# include <stdio.h>

int ft_printf(const char *format, ...);
int ft_format(char c, va_list args);
int ft_putchar_ret(char c);
int ft_putstr_ret(char *str);
int ft_putnbr_ret(int n);
int ft_putunsigned_ret(unsigned int n);
int ft_puthex_ret(unsigned int n, char format);
int ft_putptr_ret(void *ptr);

#endif
