GREEN = \033[0;32m
YELLOW = \033[0;33m
BLUE = \033[0;34m
RESET = \033[0m


NAME = Weapon
CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98
RM = rm -f

SRC_DIR = src/
OBJ_DIR = obj/

SRCS =	$(SRC_DIR)main.cpp \
		$(SRC_DIR)Weapon.cpp \
		$(SRC_DIR)HumanA.cpp \
		$(SRC_DIR)HumanB.cpp

OBJS = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME) : $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
	@echo "$(GREEN) $(NAME) SUCCESSFULLY COMPILED!$(RESET)"

%.o: %.cpp
	@echo "$(YELLOW) Compiling $<...$(RESET)"
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@echo "$(BLUE) Cleaning object files...$(RESET)"
	@$(RM) $(OBJS)

fclean: clean
	@echo "$(GREEN) Complete cleaning...$(RESET)"
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re