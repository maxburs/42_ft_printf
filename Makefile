NAME = libftprintf.a

SRCS = \
	ft_printf.c\
	conv.c\
	build_conv.c\
	print_arg.c

OBJS = $(SRCS:.c=.o)

CFLAGS = -Wall -Wextra -Werror

DEBUG_FLAGS = -g

DEBUG =

all: $(NAME)

$(NAME): $(OBJS) ./libft/libft.a
	cp ./libft/libft.a $@
	ar -rc $@ $(OBJS)
	ranlib $@

%.o: %.c
	gcc $(CFLAGS) -c -I . -I ./libft -o $@ $<

./libft/libft.a: ./libft/*/*.c
	cd libft && $(MAKE) $(DEBUG)

debug: DEBUG += debug
debug: CFLAGS += $(DEBUG_FLAGS)
debug: all

clean:
	rm -f $(OBJS)
	cd libft && $(MAKE) fclean
fclean: clean
	rm -f $(NAME)
re: fclean all

.PHONY: clean fclean re
