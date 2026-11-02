# ft_printf — build-it-yourself practice

This is a **scaffold, not a solution**. Every function has a TODO placeholder.
The files compile, but tests will fail until you implement the functions.

## Files

- `ft_putchar_ret.c`: print one character; return bytes written.
- `ft_putstr_ret.c`: print a string, including NULL handling.
- `ft_putnbr_ret.c`: signed decimal, including INT_MIN.
- `ft_putunsigned_ret.c`: unsigned decimal.
- `ft_puthex_ret.c`: lowercase/uppercase hexadecimal.
- `ft_putptr_ret.c`: pointer address.
- `ft_format.c`: dispatch `%c %s %p %d %i %u %x %X %%`.
- `ft_printf.c`: parse format, handle va_list, count output.
- `ft_printf.h`: all prototypes and includes.
- `Makefile`: builds `libftprintf.a`.
- `tests/`: independent learning tests, NOT files to submit.

## Suggested learning order

    1. `ft_putchar_ret`
    2. `ft_putstr_ret`
    3. `ft_putnbr_ret`
    4. `ft_putunsigned_ret`
    5. `ft_puthex_ret`
    6. `ft_putptr_ret`
7. `ft_format`
8. `ft_printf`

## How to run

```sh
./run_tests.sh char
./run_tests.sh str
./run_tests.sh nbr
./run_tests.sh unsigned
./run_tests.sh hex
./run_tests.sh ptr
./run_tests.sh all
./run_tests.sh printf   # after completing dispatcher + main
make
make clean
make fclean
make re
```

Each helper test compiles the helper stubs but runs only the selected tests.
`printf` mode builds the complete library first. Tests compare output and counts;
they are not an exhaustive automatic correctness checker.

## Evaluation checklist

- [ ] Explain `write(1, ..., ...)` and its return value.
- [ ] Explain why printf helpers return `int` instead of `void`.
- [ ] Explain how `va_start`, `va_arg`, and `va_end` work.
- [ ] Explain why `%c` reads an `int` from `va_arg`.
- [ ] Explain how the main loop handles `%%`.
- [ ] Test zero, negatives, INT_MIN, UINT_MAX, hex case, and pointers.
- [ ] Handle write errors and (ideally) short writes.
- [ ] Verify your subject's NULL-pointer and malformed-format rules.
- [ ] Run norminette on submission files (tests are not Norm-compliant).
- [ ] Verify `make`, `make clean`, `make fclean`, and `make re`.
- [ ] Verify archive is named `libftprintf.a`.

**Note:** The TODO bodies are intentionally not finished. The test sources
are deliberately compact and may use forbidden functions; keep them outside
your submission. Read your current Codam subject for the exact rules.
