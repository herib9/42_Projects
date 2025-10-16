NAME = minishell

RED		= \033[0;91m
BLUE	= \033[0;94m

CC = gcc
CFLAGS = -Wall -Wextra -Werror -I.

# Directorios
BUILTINS_DIR = builtins
PARSING_DIR = parsing
EXECUTION_DIR = execution
ENV_DIR = enviroment
SIGNALS_DIR = signals
SHELL_DIR = shell
UTILS_DIR = utils

OBJ_DIR = obj

BUILTINS_SRC = ft_cd.c ft_echo.c ft_env.c ft_exit.c ft_export.c \
				ft_pwd.c ft_unset.c if_builtin.c ft_error_cd_pwd.c

PARSING_SRC = ft_parsing.c ft_parsing_lexer.c ft_parsing_tokens.c \
				ft_parsing_pipe_and_red.c ft_parse_quotes.c ft_parse_redir.c \
				ft_cmd_parsing.c ft_utils_parse.c single_or_double_quotes.c

EXECUTION_SRC = ft_execute.c ft_executor.c ft_exe_utils.c \
				ft_path_exe.c ft_redirections.c ft_heredoc.c

ENV_SRC = ft_env_parsing.c ft_env_utils.c ft_manage_env.c

SIGNALS_SRC = ft_signal.c

SHELL_SRC = ft_minishell.c

UTILS_SRC = ft_cleaning.c ft_free.c ft_helpers.c ft_mem_utils.c \
			ft_more_utils.c ft_split.c ft_utils.c ft_utils_one.c ft_utils_two.c

MAIN_SRC = main_minishell.c

# Rutas completas de archivos fuente
SOURCES =	$(addprefix $(BUILTINS_DIR)/, $(BUILTINS_SRC)) \
			$(addprefix $(PARSING_DIR)/, $(PARSING_SRC)) \
			$(addprefix $(EXECUTION_DIR)/, $(EXECUTION_SRC)) \
			$(addprefix $(ENV_DIR)/, $(ENV_SRC)) \
			$(addprefix $(SIGNALS_DIR)/, $(SIGNALS_SRC)) \
			$(addprefix $(SHELL_DIR)/, $(SHELL_SRC)) \
			$(addprefix $(UTILS_DIR)/, $(UTILS_SRC)) \
			$(MAIN_SRC)

OBJECTS = $(SOURCES:.c=.o)

all: $(NAME)

$(NAME): $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) -o $(NAME) -lreadline

	@echo "${RED} █   █${BLUE} █${RED} █  █${BLUE} █${RED} █████ ${BLUE}█   █${RED} █████${BLUE} █    ${RED} █"
	@echo "${RED} ██ ██${BLUE} █${RED} █  █${BLUE} █${RED} █     ${BLUE}█   █${RED} █    ${BLUE} █    ${RED} █"
	@echo "${RED} █ █ █${BLUE} █${RED} ██ █${BLUE} █${RED} █████ ${BLUE}█████${RED} ████ ${BLUE} █    ${RED} █"
	@echo "${RED} █   █${BLUE} █${RED} █ ██${BLUE} █${RED}     █ ${BLUE}█   █${RED} █    ${BLUE} █    ${RED} █"
	@echo "${RED} █   █${BLUE} █${RED} █  █${BLUE} █${RED} █████ ${BLUE}█   █${RED} █████${BLUE} █████${RED} █████"
	
	@echo "${RED} Leiamart ${BLUE} Hmolina"

%.o: %.c minishell.h
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "Compilando: $<"

clean:
	rm -f $(OBJECTS)
	@echo "Archivos objeto eliminados"

fclean: clean
	rm -f $(NAME)
	@echo "Ejecutable eliminado"

re: fclean all

.PHONY: all clean fclean re
