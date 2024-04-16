NAME = push_swap

SRCS =  butterfly.c parsing.c push_swap.c error.c\
		normalisation.c small_stack.c sort1.c
OBJS=$(SRCS:.c=.o)

RM=rm -f

CC= clang

CFLAGS= -Wall -Wextra -I./MLX/includes/mlx.h -I./libft/libft.h \
									-I./ft_printf/printf.h -g

all: $(NAME)

$(NAME) : $(OBJS)
	make --directory ./libft 
	$(CC) $(OBJS) $(CFLAGS) $(MLXFLAGS) ./libft/libft.a -o $@
	@if [ $$? -eq 0 ]; then \
		echo "\033[32;1mCompilation successful!\033[0m"; \
	fi

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ 

clean: 
	$(RM) $(OBJS)
fclean: clean
	$(RM) $(NAME)

re: fclean $(NAME)

run: all
	./$(NAME)

.PHONY: all clean fclean re
