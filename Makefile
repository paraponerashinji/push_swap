NAME= push_swap
CC= cc
CFLAGS = -Wall -Wextra -Werror
SRCS= main.c
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
