NAME = libftprintf.a

SRCS = ft_printf.c ft_hex.c ft_ptr.c ft_uint.c \
ft_char_and_str.c ft_num.c

OBJS = $(SRCS:.c=.o)
LIBFT_DIR = libft
CC = cc
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJS)
	$(MAKE) -C $(LIBFT_DIR)
	@cp $(LIBFT_DIR)/libft.a $@
	@ar -rcs $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(MAKE) clean -C $(LIBFT_DIR)
	rm -rf $(OBJS)

fclean: clean
	$(MAKE) fclean -C $(LIBFT_DIR)
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
