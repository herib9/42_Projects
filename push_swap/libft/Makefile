NAME = libft.a

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRCS = $(wildcard *.c)

OBJS = $(SRCS:.c=.o)

RM = rm -f

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

bonus: all

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus
