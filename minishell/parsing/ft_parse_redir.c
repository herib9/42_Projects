/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_redir.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leiamart <leiamart@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 19:34:41 by leiamart          #+#    #+#             */
/*   Updated: 2025/10/15 19:34:42 by leiamart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	manage_in(t_command *command, t_lexer *lexer)
{
	if (command->inputf)
		free(command->inputf);
	command->inputf = ft_strdup(lexer->next->lxr);
	if (!command->inputf)
		return ;
	if (access(command->inputf, R_OK) == -1)
	{
		command->value = 1;
		ft_putstr_fd("minishell: ", 2);
		ft_putstr_fd(command->inputf, 2);
		ft_putendl_fd(": No such file or directory", 2);
	}
}

void	manage_out(t_command *command, t_lexer *lexer)
{
	int	i;

	if (command->outputf)
		free(command->outputf);
	command->outputf = ft_strdup(lexer->next->lxr);
	if (!command->outputf)
		return ;
	command->add = false;
	i = open(command->outputf, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (i == -1)
	{
		command->value = 1;
		ft_putstr_fd("minishell: ", 2);
		ft_putstr_fd(command->outputf, 2);
		ft_putendl_fd(": Permission denied", 2);
	}
	else
	{
		if (close(i) == -1)
		{
			command->value = 1;
			ft_putstr_fd("minishell: Error: close file\n", 2);
		}
	}
}

int	in_redirection(char *c)
{
	int	i;

	i = open(c, O_RDONLY);
	if (i == -1)
	{
		return (1);
	}
	if (dup2(i, STDIN_FILENO) == -1)
	{
		perror("Error duplicating input file\n");
		close(i);
		return (1);
	}
	close(i);
	return (0);
}

int	out_redirection(char *c, int x)
{
	int	i;

	if (x == 1)
		i = open(c, O_CREAT | O_WRONLY | O_APPEND, 0644);
	else
		i = open(c, O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (i == -1)
	{
		return (1);
	}
	if (dup2(i, STDOUT_FILENO) == -1)
	{
		perror("Error duplicating output file\n");
		close(i);
		return (1);
	}
	close(i);
	return (0);
}

void	parse_redirection(t_command *command, t_lexer *lexer)
{
	int	i;

	if (command->outputf)
		free(command->outputf);
	command->outputf = ft_strdup(lexer->next->lxr);
	if (!command->outputf)
		return ;
	command->add = true;
	i = open(command->outputf, O_WRONLY | O_CREAT | O_APPEND, 0644);
	if (i == -1)
	{
		command->value = 1;
		ft_putstr_fd("minishell: ", 2);
		ft_putstr_fd(command->outputf, 2);
		ft_putendl_fd(": Permission denied", 2);
	}
	else
	{
		if (close(i) == -1)
		{
			command->value = 1;
			ft_putstr_fd("minishell: Error closing file\n", 2);
		}
	}
}
