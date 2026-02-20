GREEN = \033[0;32m
YELLOW = \033[0;33m
BLUE = \033[0;34m
RESET = \033[0m

NAME = cub3D

CC = gcc
CFLAGS = -Wall -Wextra -Werror

SRCS =	src/main.c \
		src/validations/validate_map.c \
		src/validations/utils_validations.c \
		src/validations/utils_validations2.c \
		src/validations/utils_validations3.c \
		src/validations/flood_fill.c \
		src/parsing/colors.c \
		src/parsing/textures.c \
		src/save_file/save_file.c \
		src/utils/clean_game.c \
		src/init/init.c \
		src/utils/utils_tokens.c \
		src/print_map/print_map.c \
		src/print_map/print_line.c \
		src/moves/keyboard.c \
		src/moves/movements.c \
		src/dda/mini_dda.c \
		src/print_3d/print_3d.c \
		src/print_3d/draw_wall_slice.c \
		src/print_3d/print_background.c \
		src/init/window.c

OBJS = $(SRCS:.c=.o)

LIBFT_DIR = libs/libft
LIBFT = $(LIBFT_DIR)/libft.a

MLX42_DIR = libs/MLX42
MLX42_BUILD = $(MLX42_DIR)/build
MLX42_LIB = $(MLX42_BUILD)/libmlx42.a

INCLUDES = -Iinclude -I$(LIBFT_DIR) -I$(MLX42_DIR)/include

#BREW_PREFIX = $(shell brew --prefix)
#GLFW_PATH = $(BREW_PREFIX)/opt/glfw

MLX42_LIBS = -lglfw -ldl -pthread -lm #-L$(GLFW_PATH)/lib
#INCLUDES += -I$(GLFW_PATH)/include

RM = rm -f

all: $(NAME)
	@echo "$(GREEN)✅ $(NAME) SUCCESSFULLY COMPILED!$(RESET)"

$(MLX42_LIB):
	@echo "$(YELLOW) Compiling MLX42...$(RESET)"
	@cmake $(MLX42_DIR) -B $(MLX42_BUILD) > /dev/null 2>&1
	@make -C $(MLX42_BUILD) -j4 > /dev/null 2>&1

$(LIBFT):
	@echo "$(YELLOW) Compiling libft...$(RESET)"
	@make -C $(LIBFT_DIR) > /dev/null 2>&1

$(NAME): $(MLX42_LIB) $(LIBFT) $(OBJS)
	@echo "$(BLUE) Linking $(NAME)...$(RESET)"
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(MLX42_LIB) $(MLX42_LIBS) -o $(NAME)

%.o: %.c
	@echo "$(YELLOW) Compiling $<...$(RESET)"
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	@echo "$(BLUE) Cleaning object files...$(RESET)"
	@$(RM) $(OBJS)
	@make -C $(LIBFT_DIR) clean > /dev/null 2>&1

fclean: clean
	@echo "$(BLUE)🧹 Complete cleaning...$(RESET)"
	@$(RM) $(NAME)
	@if [ -d "$(MLX42_BUILD)" ]; then $(RM) -r $(MLX42_BUILD); fi
	@make -C $(LIBFT_DIR) fclean > /dev/null 2>&1

re: fclean all

.PHONY: all clean fclean re
