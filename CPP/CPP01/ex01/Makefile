GREEN = \033[0;32m
YELLOW = \033[0;33m
BLUE = \033[0;34m
RESET = \033[0m


NAME = horde
CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98
RM = rm -f

SRC_DIR = src/
OBJ_DIR = obj/

SRCS =	$(SRC_DIR)main.cpp \
		$(SRC_DIR)Zombie.cpp \
		$(SRC_DIR)zombieHorde.cpp

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