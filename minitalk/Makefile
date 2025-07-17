NAME = minitalk
# Nombres de los ejecutables
CLIENT = client
SERVER = server

CC = cc
CFLAGS = -Wall -Wextra -Werror

# Archivos fuente específicos para cada programa
CLIENT_SRCS = client.c utils.c
SERVER_SRCS = server.c utils.c

# Archivos objeto
CLIENT_OBJS = $(CLIENT_SRCS:.c=.o)
SERVER_OBJS = $(SERVER_SRCS:.c=.o)

RM = rm -f

# Regla principal: construir ambos ejecutables
all: $(CLIENT) $(SERVER)

# Construir el cliente
$(CLIENT):	$(CLIENT_OBJS)
	$(CC)	$(CFLAGS)	$(CLIENT_OBJS)	-o	$(CLIENT)

# Construir el servidor
$(SERVER):	$(SERVER_OBJS)
	$(CC)	$(CFLAGS)	$(SERVER_OBJS)	-o	$(SERVER)

# Regla patrón para compilar archivos .c a .o
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Limpiar archivos objeto
clean:
	$(RM) $(CLIENT_OBJS) $(SERVER_OBJS)

# Limpiar todo (objetos + ejecutables)
fclean:	clean
	$(RM) $(CLIENT) $(SERVER)

# Recompilar desde cero
re: fclean all

.PHONY: all clean fclean re