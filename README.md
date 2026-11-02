*This project has been created as part of the 42 curriculum by .*

# ft_printf

## Description

A C library recreating the mandatory behavior of `printf` for the following supported specifiers:

- `%c` — Prints a single character.
- `%s` — Prints a string.
- `%p` — Prints a pointer address.
- `%d` / `%i` — Prints a signed integer.
- `%u` — Prints an unsigned integer.
- `%x` — Prints a lowercase hexadecimal number.
- `%X` — Prints an uppercase hexadecimal number.
- `%%` — Prints a percent sign.

## Instructions

### 1. Compile the library

Run:

```bash
make
```

This creates `libftprintf.a`.

### 2. Compile the test program

```bash
cc -Wall -Wextra -Werror main.c libftprintf.a -o test.out
```

### 3. Run the tests

```bash
./test.out
```

### 4. Clean up

Remove object files:

```bash
make clean
```

Remove object files and the library:

```bash
make fclean
```

Recompile everything:

```bash
make re
```

## Algorithm and Data Structures

The `ft_printf()` function uses `va_list` to handle variable arguments.

It loops through the format string and prints normal characters directly. When it encounters `%`, it calls `ft_format()` to determine the correct conversion.

Each printing function returns the number of characters written, or `-1` if writing fails.

Integers are printed recursively, starting with the most significant digit.

No dynamic memory allocation or output buffer is needed.

## Resources

- `man 3 printf`
- `man 3 stdarg`
- `man 2 write`
- Official ft_printf subject (version 12.1)

### AI Usage

AI was used to review the Makefile and header, improve the README, and help create test cases.

## Testing

The `main.c` file compares `ft_printf()` with the original `printf()`.

Tests include all mandatory conversions, integer limits, pointers, strings, hexadecimal values, and return values.

The individual source files also contain test functions used during development.
