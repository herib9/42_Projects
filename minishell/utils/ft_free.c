/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leiamart <leiamart@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 19:33:40 by leiamart          #+#    #+#             */
/*   Updated: 2025/10/15 19:33:42 by leiamart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	cleaning_matrix(char **c)
{
	int	i;

	if (!c)
		return ;
	i = 0;
	while (c[i])
	{
		if (c[i])
			free(c[i]);
		i++;
	}
	free(c);
	c = NULL;
}

void	free_out_and_in_files(t_command *command)
{
	if (command->inputf)
		free(command->inputf);
	if (command->outputf)
		free(command->outputf);
	if (command->split)
		free(command->split);
}

void	cleaning_token_list(t_lexer **lexer)
{
	t_lexer	*aux;

	while (*lexer)
	{
		aux = (*lexer)->next;
		if ((*lexer)->lxr)
			free((*lexer)->lxr);
		free(*lexer);
		*lexer = aux;
	}
	*lexer = NULL;
}

void	cleaning_arg(t_command *command)
{
	int	i;

	i = 0;
	if (!command->argv)
		return ;
	while (command->argv[i])
	{
		free(command->argv[i]);
		command->argv[i] = NULL;
		i++;
	}
	free(command->argv);
	command->argv = NULL;
}

void	cleaning_cmd_list(t_command **exe)
{
	t_command	*aux;
	t_command	*next;

	aux = *exe;
	while (aux)
	{
		next = aux->next;
		cleaning_arg(aux);
		free_out_and_in_files(aux);
		free(aux);
		aux = next;
	}
	*exe = NULL;
}
