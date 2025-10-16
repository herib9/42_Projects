/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_executor.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leiamart <leiamart@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 19:33:03 by leiamart          #+#    #+#             */
/*   Updated: 2025/10/15 19:33:05 by leiamart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	manage_tkn_shell(t_minishell *ms)
{
	t_lexer	*aux;

	aux = ms->lexer;
	insert_cmd_end(&ms->exe);
	while (aux)
		parsing_token(ms, &aux);
	if (!valid_cmds(ms) || count_cmd(ms->exe) > MC)
		return (0);
	return (1);
}

void	pipex_child_process(t_command *c, int i, int p[2], t_minishell *ms)
{
	if (apply_red(ms, c) == 1)
		exit (1);
	signal(SIGQUIT, SIG_IGN);
	if (i != -1)
		dup2(i, STDIN_FILENO);
	if (c->next && !c->outputf)
		dup2(p[1], STDOUT_FILENO);
	if (i != -1)
		close(i);
	if (c->next)
	{
		close(p[0]);
		close(p[1]);
	}
	if (c->core)
	{
		wich_builtin_run(ms, c, i);
		exit(ms->code);
	}
	else
		running_cmd(ms, c);
	perror("Error executing\n");
	exit (126);
}

void	pipex_father_process(t_minishell *ms, int *i, int p[2])
{
	if (*i != -1)
		close(*i);
	if (ms->exe->next)
	{
		close(p[1]);
		*i = p[0];
	}
	else
		*i = -1;
	g_signal_flag = 1;
}

void	manage_pipex_process(pid_t *pids, t_minishell *ms)
{
	int			x;
	int			i;
	t_command	*command;

	i = 0;
	command = ms->exe;
	while (command)
	{
		waitpid(pids[i], &x, 0);
		i++;
		if (!command->next)
			parse_exit_signal(x, ms);
		command = command->next;
	}
}
