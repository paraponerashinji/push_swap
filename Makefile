NAME= push_swap
CC= cc
CFLAGS = -Wall -Wextra -Werror -g
SRCS= main.c src/check_args.c src/init_stack.c src/moves.c src/sorting.c src/utilities.c src/small_sort.c
OBJS= $(SRCS:.c=.o)
LIBS=  libftprintf.a libft.a
$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBS)
%.o:%.c
	$(CC) $(CFLAGS) -c $< -o $@
clean:
	rm -f $(OBJS)
fclean: clean
	rm -f $(NAME)
all: $(NAME)
re: fclean all
.PHONY: clean fclean all re
