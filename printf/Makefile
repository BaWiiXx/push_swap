CC=cc
NAME=libftprintf.a
HEADER=ft_printf.h
SRCS=ft_printf.c ft_putchar.c ft_putnbr.c ft_putnbr_base.c ft_putnbr_unsigned.c ft_putstr.c ft_strlen.c ft_putnbr_basep.c
CFLAGS = -Wall -Wextra -Werror -g
OBJS= $(SRCS:.c=.o)

all:$(NAME)

$(NAME): $(OBJS)
	ar -rc $(NAME) $(OBJS)
	
%.o : %.c $(HEADER)
	$(CC) $(CFLAGS) $< -c -o $@

fclean: clean
	rm -f $(NAME)

clean:
	rm -f $(OBJS)

re: fclean all

.PHONY: all fclean clean re so
