NAME = libftprintf.a

SRCS = \
	ft_printf.c\
	conv.c\
	build_conv.c

OBJS = $(SRCS:.c=.o)

CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJS) ./libft/libft.a
	cp ./libft/libft.a $@
	ar -rc $@ $(OBJS)
	ranlib $@

%.o: %.c
	gcc $(CFLAGS) -c -I . -I ./libft -o $@ $<

./libft/libft.a: ./libft/*.c
	cd libft && $(MAKE)

clean:
	rm -f $(OBJS)
	cd libft && $(MAKE) fclean
fclean: clean
	rm -f $(NAME)
re: fclean all

.PHONY: clean fclean re
