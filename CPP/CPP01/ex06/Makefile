# Colores
GREEN	= \033[38;5;82m
YELLOW	= \033[38;5;33m
BLUE	= \033[38;5;33m
RED		= \033[38;5;196m
RESET	= \033[0m


NAME	= HarlFilter
CC		= c++
CFLAGS	= -Wall -Wextra -Werror -std=c++98
RM 		= rm -f

# Archivos
SRC 	=	main.cpp \
			Harl.cpp

OBJ_DIR	= .obj

OBJ		= $(SRC:%.cpp=$(OBJ_DIR)/%.o)
# OBJ		= $(addprefix $(OBJ_DIR)/, $(SRC:.cpp=.o))

all: $(NAME)

#Regla principal
$(NAME) : $(OBJ)
	@echo "$(BLUE)Compiling...$(RESET)"
	@$(CC) $(CFLAGS) $(OBJ) -o $(NAME)
	@echo "$(GREEN)$(NAME) SUCCESSFULLY COMPILED$(RESET)"

# Compila los .o dentro de una carpeta oculta
$(OBJ_DIR)/%.o: %.cpp | $(OBJ_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@

# Crea la carpeta oculta
$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

clean:
	@echo "$(RED)Cleaning object files...$(RESET)"
	@$(RM) -r $(OBJ_DIR)

fclean: clean
	@echo "$(RED)...Complete cleaning$(RESET)"
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re