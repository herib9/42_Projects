# Colores
GREEN	= \033[38;5;82m
YELLOW	= \033[38;5;33m
BLUE	= \033[38;5;33m
RED		= \033[38;5;196m
RESET	= \033[0m


NAME	= aAnimal
CC		= c++
CFLAGS	= -Wall -Wextra -Werror -std=c++98
RM		= rm -f

OBJ_DIR = .obj/
# Archivos
SRCS =	main.cpp \
		AAnimal.cpp \
		Dog.cpp \
		Cat.cpp \
		Brain.cpp

OBJS = $(addprefix $(OBJ_DIR), $(SRCS:.cpp=.o))

all: $(NAME)

#Regla principal
$(NAME) : $(OBJS)
	@echo "$(BLUE)Compiling...$(RESET)"
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
	@echo "$(GREEN)$(NAME) SUCCESSFULLY COMPILED$(RESET)"

# Compila los .o dentro de una carpeta oculta
$(OBJ_DIR)%.o: %.cpp | $(OBJ_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@

# Crea la carpeta oculta
$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

clean:
	@echo "$(RED)Cleaning object files...$(RESET)"
	@rm -rf $(OBJ_DIR)

fclean: clean
	@echo "$(RED)...Complete cleaning$(RESET)"
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re