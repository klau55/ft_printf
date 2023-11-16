# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nkarpilo <nkarpilo@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/06 18:41:22 by nkarpilo          #+#    #+#              #
#    Updated: 2023/11/13 14:21:44 by nkarpilo         ###   ########.fr        #
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
SRCS_BONUS =	ft_lstnew_bonus.c ft_lstadd_front_bonus.c ft_lstsize_bonus.c \
ft_lstlast_bonus.c ft_lstadd_back_bonus.c ft_lstdelone_bonus.c \
ft_lstclear_bonus.c ft_lstiter_bonus.c ft_lstmap_bonus.c

OBJ = $(SRCS:.c=.o)
OBJ_BONUS = $(SRCS_BONUS:.c=.o)

NAME = libft.a
CC = cc
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

clean:
	rm -f $(OBJ) $(OBJ_BONUS)
	@$(RM) -f .bonus

fclean: clean
	rm -f $(NAME)

re: 
	fclean $(NAME)
bonus: .bonus

.bonus: $(OBJ_BONUS)
	ar -rcs $(NAME) $(OBJ_BONUS)
	@ touch .bonus

.PHONY: all clean fclean re bonus
