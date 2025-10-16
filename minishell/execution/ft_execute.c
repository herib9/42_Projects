/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execute.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leiamart <leiamart@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 19:32:52 by leiamart          #+#    #+#             */
/*   Updated: 2025/10/15 19:32:54 by leiamart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

pid_t	run_s_cmd(t_command *command, int *z, int *i, t_minishell *ms)
{
	pid_t	p;

	if (command->next && pipe(i) == -1)
	{
		perror("Error: pipe\n");
		exit(1);
	}
	p = fork();
	if (p == -1)
	{
		perror("Error: child process.\n");
		exit(1);
	}
	if (p == 0)
		pipex_child_process(command, *z, i, ms);
	else
	{
		pipex_father_process(ms, z, i);
		if (command->core && !ft_strncmp(command->argv[0], "exit", 5)
			&& (*z == -1))
			exit(ms->code);
	}
	return (p);
}

void	run_all_cmd(t_minishell *ms)
{
	int			p[2];
	int			i;
	int			z;
	t_command	*command;
	pid_t		pids[MC];

	i = 0;
	command = ms->exe;
	z = -1;
	if (command->core && !command->next && (z == -1))
	{
		wich_builtin_run(ms, command, z);
		return ;
	}
	while (command)
	{
		pids[i] = run_s_cmd(command, &z, p, ms);
		command = command->next;
		i++;
	}
	manage_pipex_process(pids, ms);
}

void	run_cmd_or_exit(t_minishell *ms, t_command *command, char *c)
{
	int	i;

	i = 0;
	if (!c)
	{
		ft_putstr_fd("command not found: ", 2);
		ft_putstr_fd(command->argv[0], 2);
		ft_putstr_fd("\n", 2);
		while (command->argv[i])
			free(command->argv[i++]);
		free(command->argv);
		exit(127);
	}
	execve(c, command->argv, ms->var);
	perror("Error executing.\n");
	while (command->argv && command->argv[i])
		free(command->argv[i++]);
	free(command->argv);
	free(c);
	exit(126);
}

void	running_cmd(t_minishell *ms, t_command *command)
{
	int		i;
	char	*a;
	char	**z;

	i = 0;
	z = ms->var;
	if (!command->argv || !command->argv[0])
	{
		ft_putstr_fd("Error: empty command\n", 2);
		exit(127);
	}
	if (command->argv[0][0] == '\0')
	{
		ft_putstr_fd("minishell: command '' not found\n", 2);
		exit(127);
	}
	while (z[i] && ft_strnstr(z[i], "PATH", 4) == 0)
		i++;
	if (!ft_strchr(command->argv[0], '/') && !(z[i]))
	{
		ft_putstr_fd("No PATH found\n", 2);
		exit(127);
	}
	a = get_exe_path((z[i]), command->argv);
	run_cmd_or_exit(ms, command, a);
}
