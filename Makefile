NAME = libftprintf.a

SRCS = \
	conv.c \
	format.c \
	format_cont.c \
	ft_printf.c \
	inference.c \
	$(addprefix parse/,\
		parse.c \
		parse_char.c \
		parse_char_wide.c \
		parse_int.c \
		parse_ptr.c \
		parse_str.c \
		parse_str_wide.c \
	) \

OBJS = $(SRCS:.c=.o)

CFLAGS = -Wall -Wextra
ifndef WNOERROR
	CFLAGS += -Werror
endif
ifdef WNOERROR
	MAKE_ARGS += WNOERROR=1
endif
ifdef DEBUG
	CFLAGS += -g
	MAKE_ARGS += DEBUG=1
	SRCS += debug.c
endif
ifndef UNICODE
	SRCS += wide_mask_hack.c
endif
ifdef UNICODE
	SRCS += wide_mask_unicode.c
endif

all: $(NAME)

$(NAME): $(OBJS) ./libft/libft.a
	cp ./libft/libft.a $@
	ar -rc $@ $(OBJS)
	ranlib $@

%.o: %.c
	gcc $(CFLAGS) -c -I . -I ./libft -o $@ $<

./libft/libft.a: force
	cd libft && $(MAKE) $(MAKE_ARGS)

force:
	@true

clean:
	rm -f $(OBJS)
	cd libft && $(MAKE) fclean
fclean: clean
	rm -f $(NAME)
re: fclean all

.PHONY: all clean fclean re
