# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: marieke <marieke@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/21 16:50:33 by maraasve          #+#    #+#              #
#    Updated: 2024/03/05 17:04:52 by marieke          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror -g
AR = ar -rcs

SRC =  input_check.c main.c parser.c position.c push.c reverse_rotate.c \
		rotate.c sort.c stack.c swap.c utils.c cost.c move.c
LIBFT_DIR = libft
LIBFT_NAME = libft.a
OBJ_DIR = obj
OBJ = $(addprefix $(OBJ_DIR)/,$(SRC:.c=.o))

all: $(NAME)

$(NAME): $(LIBFT_NAME) $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) -L$(LIBFT_DIR) -lft

$(LIBFT_NAME):
	@make -C $(LIBFT_DIR)

$(OBJ_DIR)/%.o: %.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

clean:
	@make -C $(LIBFT_DIR) clean
	@$(RM) -rf $(OBJ_DIR)

fclean: clean
	@make -C $(LIBFT_DIR) fclean
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re