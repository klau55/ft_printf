NAME = libftprintf.a

SRCS = ft_printf.c ft_hex.c ft_ptr.c

OBJS = $(SRCS:.c=.o)

CC = clang
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf

all: $(NAME)

$(NAME): $(OBJS)
	@ar -rcs $(NAME) $(OBJS)

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@$(RM) $(OBJS)
fclean: clean
	@$(RM) $(NAME)

re: fclean all

.PHONY: all, clean, fclean, re