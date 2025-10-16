/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   if_builtin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leiamart <leiamart@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 19:37:07 by leiamart          #+#    #+#             */
/*   Updated: 2025/10/15 19:37:09 by leiamart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	parsin_builtin(char *c)
{
	if (!ft_strcmp(c, "echo"))
		return (1);
	if (!ft_strcmp(c, "cd"))
		return (1);
	else if (!ft_strcmp(c, "pwd"))
		return (1);
	else if (!ft_strcmp(c, "export"))
		return (1);
	else if (!ft_strcmp(c, "unset"))
		return (1);
	else if (!ft_strcmp(c, "env"))
		return (1);
	else if (!ft_strcmp(c, "exit"))
		return (1);
	else
		return (0);
}

void	wich_builtin_run(t_minishell *ms, t_command *command, int i)
{
	if (!command->argv[0])
		command->argv[0] = ft_strdup("");
	if (!ft_strncmp(command->argv[0], "echo", 5))
		ms->code = echo_builtin(command);
	else if (!ft_strncmp(command->argv[0], "cd", 3))
		ms->code = cd_builtin(ms, command);
	else if (!ft_strncmp(command->argv[0], "pwd", 4))
		ms->code = pwd_builtin();
	else if (!ft_strncmp(command->argv[0], "export", 7))
		ms->code = export_builtin(ms, command);
	else if (!ft_strncmp(command->argv[0], "unset", 6))
		ms->code = unset_builtin(ms, command);
	else if (!ft_strncmp(command->argv[0], "env", 4))
		ms->code = manage_builtins(ms);
	else if (!ft_strncmp(command->argv[0], "exit", 5))
		exit_builtin(ms, command, i);
	else
		return ;
}
