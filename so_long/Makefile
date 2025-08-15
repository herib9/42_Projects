# Colores
GREEN = \033[0;32m
YELLOW = \033[0;33m
RED = \033[0;31m
BLUE = \033[0;34m
RESET = \033[0m

NAME = so_long

# compilador y flags
CC = cc
CFLAGS = -Wall -Wextra -Werror

# archivos fuente proyecto principal
SRCS = $(shell find src -maxdepth 1 -type f -name "*.c")

# archivos objeto
OBJS = $(SRCS:.c=.o)

# directorios
LIBFT_DIR = libs/libft
MINILIBX_DIR = libs/minilibx

# librerias compiladas
LIBFT = $(LIBFT_DIR)/libft.a
MINILIBX = $(MINILIBX_DIR)/libmlx.a

# headers
INCLUDES = -Iinclude -I $(LIBFT_DIR) -I $(MINILIBX_DIR)/include

# librerias del sistema para MINILIBX
MINILIBX_LIBS = -lX11 -lXext

RM = rm -f

# regla principal: construir ejecutables
all: $(NAME)
	@echo "$(GREEN)✅ $(NAME) SUCCESSFULLY COMPILED!$(RESET)"

# compilar MLX42
$(MINILIBX):
	@echo "$(YELLOW) Compiling MinilibX...$(RESET)"
	@make -C $(MINILIBX_DIR) > /dev/null 2>&1

# compilar libft
$(LIBFT):
	@echo "$(YELLOW) Compiling libft...$(RESET)"
	@make -C $(LIBFT_DIR) > /dev/null 2>&1

# regla principal del ejecutable
$(NAME): $(MINILIBX) $(LIBFT) $(OBJS)
	@echo "$(BLUE) Linking $(NAME)...$(RESET)"
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(MINILIBX) $(MINILIBX_LIBS) -o $(NAME)

# compilar archivos .c a .o
%.o: %.c
	@echo "$(YELLOW) Compiling $<...$(RESET)"
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

# limpiar objetos
clean:
	@echo "$(BLUE) Cleaning object files...$(RESET)"
	$(RM) $(OBJS)
	@make -C $(LIBFT_DIR) clean > /dev/null 2>&1
	@make -C $(MINILIBX_DIR) clean > /dev/null 2>&1

# limpiar todo
fclean:
	@echo "$(BLUE) Complete cleaning...$(RESET)"
	$(RM) $(OBJS)
	$(RM) $(NAME)
	@make -C $(LIBFT_DIR) fclean > /dev/null 2>&1
	@make -C $(MINILIBX_DIR) clean > /dev/null 2>&1

# recompilar
re: fclean all

.PHONY: all clean fclean re