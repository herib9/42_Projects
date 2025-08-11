# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hmolina <<hmolina@student.42.fr>>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/04 10:27:54 by hmolina           #+#    #+#              #
#    Updated: 2025/08/11 19:38:25 by hmolina          ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

# compilador y flags
CC = cc
CFLAGS = -Wall -Wextra -Werror

# archivos fuente proyecto principal
SRCS = $(shell find . -type f -maxdepth 1 -name "*.c")

# archivos objeto
OBJS = $(SRCS:.c=.o)

# directorios
LIBFT_DIR = libft

# librerias compiladas
LIBFT = $(LIBFT_DIR)/libft.a

# headers
INCLUDES = -Iinclude -I $(LIBFT_DIR)

all: $(NAME)

# compilar libft
$(LIBFT):
	@make -C $(LIBFT_DIR)

# regla principal del ejecutable
$(NAME): $(LIBFT) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

# compilar archivos .c a .o
%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

# limpiar objetos
clean:
	$(RM) $(OBJS)
	@make -C $(LIBFT_DIR) clean

# limpiar todo
fclean: clean
	$(RM) $(NAME)
	make -C $(LIBFT_DIR) fclean

# recompilar
re: fclean all

.PHONY: all clean fclean re
