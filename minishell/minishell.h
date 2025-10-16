/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leiamart <leiamart@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 19:37:25 by leiamart          #+#    #+#             */
/*   Updated: 2025/10/15 19:37:26 by leiamart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# define RED    "\033[0;31m"
# define BLUE   "\033[0;34m"

# include <dirent.h>
# include <errno.h>
# include <stddef.h>
# include <limits.h>
# include <sys/types.h>
# include <string.h>
# include <stdarg.h>
# include <stdlib.h>
# include <sys/wait.h>
# include <unistd.h>
# include <stdio.h>
# include <stdbool.h>
# include <fcntl.h>
# include <signal.h>
# include <readline/readline.h>
# include <readline/history.h>

# define WORD 0
# define SQ 1
# define DQ 2
# define PI 3
# define RO1 4
# define RO2 5
# define RI1 6
# define RI2 7
# define MC 999

typedef struct s_var
{
	int		begin;
	int		limit;
	char	*env;
	char	*status;
}	t_var;

typedef struct s_lexer
{
	char			*lxr;
	int				tkn;
	bool			merge;
	bool			up;
	struct s_lexer	*next;
}	t_lexer;

typedef struct s_command
{
	char				**argv;
	char				*inputf;
	char				*split;
	char				*outputf;
	bool				add;
	bool				here;
	bool				core;
	int					value;
	struct s_command	*next;
}	t_command;

typedef struct s_minishell
{
	char		*line;
	char		**var;
	int			code;
	int			prev_code;
	t_lexer		*lexer;
	t_command	*exe;
}	t_minishell;

//Builtins//
//ft_cd.c//

void		env_home_cd(t_minishell *ms, char *c, char *a);
int			manage_home(t_minishell *ms);
int			cd_builtin(t_minishell *ms, t_command *command);
//ft_echo.c//

int			parsing_echo(char *c);
int			running_echo(t_command *command);
int			echo_builtin(t_command *command);

//ft_exit.c//

void		when_exit_free(t_minishell *ms);
void		exit_builtin(t_minishell *ms, t_command *command, int i);

//ft_export.c//

int			locate_env(char **c, char *a);
void		display_export_env(char **c);
int			export_builtin(t_minishell *ms, t_command *command);

//ft_error_cd_pwd.c//

int			parsing_error_cd_pwd(t_minishell *ms, char *z, char *c);
int			parsing_error_cd_home(t_minishell *ms, char *c, char *z);

//ft_pwd.c//

int			switch_directory_oldpwd(t_minishell *ms, char *c);
int			backtrack_pwd(t_minishell *ms);
int			refresh_pwd(t_minishell *ms, char *z, char *a);
int			pwd_builtin(void);

//ft_unset.c//

int			unset_builtin(t_minishell *ms, t_command *command);

//if_builtin.c//

int			parsin_builtin(char *c);
void		wich_builtin_run(t_minishell *ms, t_command *command, int i);

//Execute//
//ft_exe_utils.c//

char		*manage_env_expansion(int *i, char *a, char **c, int x);
char		*get_literal_segment(int *i, char *c);

//ft_execute.c//

pid_t		run_s_cmd(t_command *command, int *z, int *i, t_minishell *ms);
void		run_all_cmd(t_minishell *ms);
void		run_cmd_or_exit(t_minishell *ms, t_command *command, char *c);
void		running_cmd(t_minishell *ms, t_command *command);

//ft_executor.c//

int			manage_tkn_shell(t_minishell *ms);
void		pipex_child_process(t_command *c, int i, int p[2], t_minishell *ms);
void		pipex_father_process(t_minishell *ms, int *i, int p[2]);
void		manage_pipex_process(pid_t *pids, t_minishell *ms);

//ft_heredoc.c//

char		*heredoc_line(char *c, char **h, int x);
void		set_heredoc_delimiter(t_command *command, t_lexer *lexer);
int			redirection_heredoc(t_minishell *ms, t_command *command);

//ft_minishell.c//

int			shell_in(t_minishell *ms);
void		run_shell(t_minishell *ms);

//ft_path_exe.c//

void		free_path_list(char **c, int i);
char		*find_exe_on_path(char **c, char *a);
char		*get_exe_path(char *a, char **c);

//ft_redirections.c//

void		manage_redirection(t_minishell *ms, t_lexer *lxr, t_lexer **n_lxr);
int			apply_red(t_minishell *ms, t_command *command);

//Parsing//
//ft_cleaning.c//

void		cleaning_resources(char **c, t_lexer *lexer, t_minishell *ms);
void		cleaning_stateshell(t_minishell *ms);

//ft_cmd_parsing.c//

int			valid_cmds(t_minishell *ms);
int			count_cmd(t_command *c);
void		insert_token_end(t_lexer **lexer, char *c, int i);
void		insert_cmd_end(t_command **c);
void		build_cmd_args(t_minishell *ms, t_lexer *lexer, t_lexer **nt);

//ft_free.c//

void		cleaning_matrix(char **c);
void		free_out_and_in_files(t_command *command);
void		cleaning_token_list(t_lexer **lexer);
void		cleaning_arg(t_command *command);
void		cleaning_cmd_list(t_command **exe);

//ft_helpers.c//

void		printing_exit_error(char *c);
void		*protect_memory(size_t i);
void		printing_lexer(t_lexer *lexer);
char		**save_env(char **env);
void		printing_list_command(t_command *exe);

//ft_parse_quotes.c//

void		last_tkn(t_lexer **lexer);
void		just_one_tkn(t_minishell *ms);
char		*delete_q(char *c);
void		delete_token_q(t_minishell *ms);

//ft_parse_redir.c//

void		manage_in(t_command *command, t_lexer *lexer);
void		manage_out(t_command *command, t_lexer *lexer);
int			in_redirection(char *c);
int			out_redirection(char *c, int x);
void		parse_redirection(t_command *command, t_lexer *lexer);

//ft_parsing.c//

int			identify_dollar(t_minishell *ms);
void		variables_expand(t_minishell *ms);
void		manage_dollar_token(t_lexer *lexer, char *c, char *a);
char		*insert_between(char *c, char *d, char *x);
t_var		*start_var_struct(void);

//ft_parsing_lexer.c//

void		printing_lexer_error(char *c);
void		lexer_pipe_parse(void);
void		parse_lexer(t_minishell *ms);

//ft_parsing_pipe_and_red.c//

void		parse_token_redirection(t_minishell *ms, int *i);
int			parsing_pipe(t_minishell *ms);
int			parsing_redirection(t_minishell *ms);

//ft_parsing_tokens.c//

void		extract_wtoken(t_minishell *ms, int *i);
void		shell_lex_input(t_minishell *ms);
void		parsing_token(t_minishell *ms, t_lexer **aux);
void		var_in_token(t_minishell *ms, t_lexer *lexer);
void		put_expand_value_token(t_var *var, t_lexer *lexer);

//ft_utils_parse.c//

int			modified_strchr(const char *a, int x);
int			get_var_name_len(char *c);
void		free_var_exp(t_var *var);
void		change_at_begin(char **c, char *a, char *d);
void		manage_status(t_minishell *ms, t_lexer *lexer);

//single_or_double_quotes.c//

int			manage_double_q(t_minishell *ms, int *i);
int			manage_single_q(t_minishell *ms, int *i);
int			single_or_double_quotes(t_minishell *ms, int *i);

//Env//
//ft_env.c//

char		**update_env_if_exist(char **c, char *a, int i);
int			validate_env_syntax(char *c);
char		**manage_env_export(char **c, char *s, int x);
void		order_str(char **c);
int			manage_builtins(t_minishell *ms);

//ft_env_parsing.c//

char		*strip_plus_equal(char *c);
char		**copy_env_var_end(char **c, char *s);
char		*giveme_value_env(char **c, char *a);
void		expand_all_tokens(t_minishell *ms);
char		**delete_env(char **c, char *b);

//ft_env_utils.c//

int			find_env_index(char **c, char *a);
char		*parse_var_name(char *c);
int			how_many_args(t_lexer *lexer);
int			length_str_array(char **a);
void		printing_display_export(char **a);

//ft_manage_env.c//

char		*locate_operator(char *c);
char		*manage_concatenated_env(char *a, char *z, char *s);
char		**merge_env_value(char **a, char *c, int i);

//Utils_Libf//
//ft_mem_utils.c//

void		*ft_memset(void *v, int c, size_t x);
void		ft_bzero(void *s, size_t n);
void		*ft_calloc(size_t c, size_t i);

//ft_more_utils.c//

size_t		ft_strlcpy(char *dst, const char *src, size_t dstsize);
char		*ft_itoa(int n);
int			ft_atoi(const char *c);
int			ft_strncmp(const char *s1, const char *s2, size_t i);

//ft_split.c//

char		**ft_split(char const *a, char c);
char		*ft_substr(char const *s, unsigned int b, size_t l);

//ft_utils.c//

void		ft_swap(char **a, char **b);
int			ft_strcmp(char *s1, char *s2);
int			ft_strcmp_two(const char *s1, const char *s2);
char		*ft_substr_two(const char *c, int i, int x);
int			ft_is_num(char *c);

//ft_utils_one.c//

char		*ft_strdup(const char *s1);
int			ft_isalpha(int c);
int			ft_isalnum(int c);
char		*ft_strchr(const char *s, int c);
char		*ft_strnstr(const char *s, const char *w, size_t c);

//ft_utils_two.c//

size_t		ft_strlen(const char *c);
void		ft_putstr_fd(char *c, int i);
void		ft_putchar_fd(char c, int i);
void		ft_putendl_fd(char *c, int i);
char		*ft_strjoin(char const *s1, char const *s2);

//ft_signals.c//

void		parse_exit_signal(int i, t_minishell *ms);
void		manage_signal(int i);
void		init_signals(void);
void		manage_sigquit(void);
extern int	g_signal_flag;

//main.c//

t_minishell	*struct_minishell(char **c);
int			main(int ac, char **av, char **c);

#endif
