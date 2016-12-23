NAME = libftprintf.a

SRCS = ft_printf.c

OBJS = $(SRCS:.c=.o)

CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJS) ./libft/libft.a
	ar rc $@ $^

%.o: %.c
	gcc $(CFLAGS) -c -I . -o $@ $<
	ranlib $@

./libft/libft.a: ./libft/*.c
	cd libft && $(MAKE)

clean:
	rm -f $(OBJS)
	cd libft && $(MAKE) fclean
fclean: clean
	rm -f $(NAME)
re: fclean all

.PHONY: clean fclean re
