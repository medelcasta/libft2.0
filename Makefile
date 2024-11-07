# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amedel-r <amedel-r@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/20 14:34:30 by pabmart2          #+#    #+#              #
#    Updated: 2024/11/07 21:37:35 by amedel-r         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = libft.a
SRC = \
	ft_atoi.c \
	ft_isalpha.c \
	ft_itoa.c \
	ft_memcmp.c \
	ft_putchar_fd.c \
	ft_split.c \
	ft_strjoin.c \
	ft_strmapi.c \
	ft_strtrim.c \
	ft_bzero.c \
	ft_isascii.c \
	ft_memcpy.c \
	ft_putendl_fd.c \
	ft_strchr.c \
	ft_strlcat.c \
	ft_strncmp.c \
	ft_substr.c \
	ft_calloc.c \
	ft_isdigit.c \
	ft_memmove.c \
	ft_putnbr_fd.c \
	ft_strdup.c \
	ft_strlcpy.c \
	ft_strnstr.c \
	ft_tolower.c \
	ft_isalnum.c \
	ft_isprint.c \
	ft_memchr.c \
	ft_memset.c \
	ft_putstr_fd.c \
	ft_striteri.c \
	ft_strlen.c \
	ft_strrchr.c \
	ft_toupper.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

clean:
	@rm -f $(OBJ) $(BONUS_OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean
	$(MAKE) all

$(NAME) : $(OBJ)
	@ar rcs $(NAME) $(OBJ)
	@echo "\033[32m\n¡$(NAME) compiled! \
	ᕦ(\033[36m⌐■\033[32m_\033[36m■\033[32m)ᕤ\n"

$(OBJ): %.o: %.c
	echo "Compiling $<"
	@$(CC) $(CFLAGS) -c $< -o $@

.PHONY: all clean fclean re bonus

############################# 	BONUS	#############################

BONUS_SRC = \
	ft_lstadd_back_bonus.c \
	ft_lstadd_front_bonus.c \
	ft_lstdelone_bonus.c \
	ft_lstlast_bonus.c \
	ft_lstnew_bonus.c \
	ft_lstsize_bonus.c \
	ft_lstclear_bonus.c \
	ft_lstiter_bonus.c \
	ft_lstmap_bonus.c

BONUS_OBJ = $(BONUS_SRC:.c=.o)

bonus : $(BONUS_OBJ) $(OBJ)
	@ar rcs $(NAME) $(BONUS_OBJ)
	@echo "\033[32m\n¡$(NAME) compiled with bonus functions! \
	ᕦ(\033[36m⌐■\033[32m_\033[36m■\033[32m)ᕤ\n"

$(BONUS_OBJ): %.o: %.c
	echo "Compiling $<"
	@$(CC) $(CFLAGS) -c $< -o $@
