NAME = so_long

# compilador y flags
CC = cc
CFLAGS = -Wall -Wextra -Werror

# archivos fuente proyecto principal
SRCS = $(shell find src -type f -maxdepth 1 -name "*.c")

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

# compilar MLX42
$(MINILIBX):
	@make -C $(MINILIBX_DIR)

# compilar libft
$(LIBFT):
	@make -C $(LIBFT_DIR)

# regla principal del ejecutable
$(NAME): $(MINILIBX) $(LIBFT) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(MINILIBX) $(MINILIBX_LIBS) -o $(NAME)

# compilar archivos .c a .o
%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

# limpiar objetos
clean:
	$(RM) $(OBJS)
	@make -C $(LIBFT_DIR) clean
	@make -C $(MINILIBX_DIR) clean

# limpiar todo
fclean: clean
	$(RM) $(NAME)
	@make -C $(LIBFT_DIR) fclean
	@make -C $(MINILIBX_DIR) clean || true

# recompilar
re: fclean all

.PHONY: all clean fclean re