# colores
GREEN = \033[0;32m
YELLOW = \033[0;33m
BLUE = \033[0;34m
RESET = \033[0m

NAME = push_swap

# compilador y flags
CC = cc
CFLAGS = -Wall -Wextra -Werror

# archivos fuente proyecto principal
SRCS = $(shell find src -type f -maxdepth 1 -name "*.c")

# archivos objeto
OBJS = $(SRCS:.c=.o)

# directorios
LIBFT_DIR = libft

# librerias compiladas
LIBFT = $(LIBFT_DIR)/libft.a

# headers
INCLUDES = -Iinclude -I $(LIBFT_DIR)

all: $(NAME)
	@echo "$(GREEN)✅ $(NAME) SUCCESSFULLY COMPILED!$(RESET)"

# compilar libft
$(LIBFT):
	@echo "$(YELLOW) Compiling libft...$(RESET)"
	@make -C $(LIBFT_DIR) > /dev/null 2>&1

# regla principal del ejecutable
$(NAME): $(LIBFT) $(OBJS)
	@echo "$(YELLOW) Linking $(NAME)...$(RESET)"
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

# compilar archivos .c a .o
%.o: %.c
	@echo "$(YELLOW) Compiling $<...$(RESET)"
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

# limpiar objetos
clean:
	@echo "$(BLUE) Cleaning object files...$(RESET)"
	@$(RM) $(OBJS)
	@make -C $(LIBFT_DIR) clean > /dev/null 2>&1

# limpiar todo
fclean: clean
	@echo "$(BLUE) Complete cleaning...$(RESET)"
	@$(RM) $(NAME)
	@make -C $(LIBFT_DIR) fclean > /dev/null 2>&1

# recompilar
re: fclean all

.PHONY: all clean fclean re
