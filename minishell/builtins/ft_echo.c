/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leiamart <leiamart@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 19:32:01 by leiamart          #+#    #+#             */
/*   Updated: 2025/10/15 19:32:03 by leiamart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	parsing_echo(char *c)
{
	int	i;

	if (c[0] != '-')
		return (0);
	i = 1;
	while (c[i])
	{
		if (c[i] != 'n')
			return (0);
		i++;
	}
	return (i > 1);
}

int	running_echo(t_command *command)
{
	int	i;
	int	x;

	if (!command->argv[1])
	{
		printf("\n");
		return (0);
	}
	i = 1;
	x = 1;
	while (command->argv[i] && parsing_echo(command->argv[i]))
	{
		x = 0;
		i++;
	}
	while (command->argv[i])
	{
		printf("%s", command->argv[i]);
		if (command->argv[i + 1])
			printf(" ");
		i++;
	}
	if (x)
		printf("\n");
	return (0);
}

int	echo_builtin(t_command *command)
{
	int	fd;
	int	i;

	if (command->value == 1)
		return (1);
	fd = dup(STDOUT_FILENO);
	if (command->outputf)
		out_redirection(command->outputf, command->add);
	i = running_echo(command);
	dup2(fd, STDOUT_FILENO);
	return (i);
}
