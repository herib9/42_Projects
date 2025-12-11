# colors
GREEN = \033[0;92m
YELLOW = \033[0;33m
BLUE = \033[0;94m
RESET = \033[0m

NAME = philo

# compilator & flags
CC = cc
CFLAGS = -Wall -Wextra -Werror -pthread

# header
INCDIR = include

# main project source files
SRCS =	main.c\
		utils.c\
		init.c\
		print_status.c\
		threads_rout.c\
		threads_mon.c\

# object files
OBJS = $(SRCS:.c=.o)

all: $(NAME)

# main rule of executable
$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
	@echo "$(GREEN)✅ $(NAME) SUCCESSFULLY COMPLETED!$(RESET)"

# compile files .c to .o
%.o: %.c
	@echo "$(BLUE) Compiling...$(RESET)"
	@$(CC) $(CFLAGS) -I$(INCDIR) -c $< -o $@

# cleaning objects
clean:
	@echo "$(BLUE) Cleaning object files...$(RESET)"
	@$(RM) $(OBJS)

# cleaning all
fclean: clean
	@echo "$(BLUE) Complete cleaning $(RESET)"
	@$(RM) $(NAME)

# recompile
re: fclean all

.PHONY: all clean fclean re