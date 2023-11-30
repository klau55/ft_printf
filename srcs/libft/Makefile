# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nkarpilo <nkarpilo@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/06 18:41:22 by nkarpilo          #+#    #+#              #
#    Updated: 2023/11/30 15:56:49 by nkarpilo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #



SRCS =	 ft_isalnum.c ft_isalpha.c ft_isdigit.c ft_isascii.c \
ft_isprint.c ft_toupper.c ft_tolower.c ft_bzero.c ft_strlen.c \
ft_memset.c ft_memcpy.c ft_memmove.c ft_memchr.c ft_memcmp.c \
ft_strchr.c ft_strrchr.c ft_strncmp.c ft_strlcat.c ft_strlcpy.c \
ft_strdup.c ft_calloc.c ft_atoi.c ft_striteri.c ft_strmapi.c \
ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c ft_putchar_fd.c\
ft_substr.c ft_strnstr.c ft_putstr_fd.c ft_putnbr_fd.c \
ft_putendl_fd.c


OBJ = $(SRCS:.c=.o)

NAME = libft.a
CC = cc
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ)
	ar -rcs $(NAME) $(OBJ)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

clean:
	rm -f $(OBJ) 

fclean: clean
	rm -f $(NAME)

re: fclean $(NAME)

.PHONY: all clean fclean re
