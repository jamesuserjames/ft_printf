NAME = libftprintf.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
AR = ar
ARFLAGS = rcs

SRCS = ft_printf.c \
       srcs/ft_format.c \
       srcs/ft_putchar_ret.c \
       srcs/ft_putstr_ret.c \
       srcs/ft_putnbr_ret.c \
       srcs/ft_putunsigned_ret.c \
       srcs/ft_puthex_ret.c \
       srcs/ft_putptr_ret.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $(ARFLAGS) $(NAME) $(OBJS)

%.o: %.c ft_printf.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re