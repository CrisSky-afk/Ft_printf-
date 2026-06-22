NAME = libftprintf.a
TEST = test_printf

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRCS = ft_printf.c ft_function.c ft_functions.c
OBJS = $(SRCS:.c=.o)

TEST_MAIN = main.c

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

$(TEST): $(NAME) $(TEST_MAIN)
	$(CC) $(CFLAGS) $(TEST_MAIN) -L. -lftprintf -o $(TEST)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME) $(TEST)

re: fclean all

test: $(TEST)
	./$(TEST)

.PHONY: all clean fclean re test