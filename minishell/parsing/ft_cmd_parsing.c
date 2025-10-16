/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cmd_parsing.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leiamart <leiamart@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 19:31:53 by leiamart          #+#    #+#             */
/*   Updated: 2025/10/15 19:31:55 by leiamart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	valid_cmds(t_minishell *ms)
{
	t_command	*command;

	if (!ms || !ms->exe)
		return (0);
	command = ms->exe;
	while (command)
	{
		if (command->argv && command->argv[0])
			return (1);
		command = command->next;
	}
	return (0);
}

int	count_cmd(t_command *c)
{
	int	i;

	i = 0;
	while (c != NULL)
	{
		c = c->next;
		i++;
	}
	return (i);
}

void	insert_token_end(t_lexer **lexer, char *c, int i)
{
	t_lexer	*aux;
	t_lexer	*a;

	if (!lexer || !c)
		return ;
	a = protect_memory(sizeof(t_lexer));
	a->lxr = ft_strdup(c);
	a->tkn = i;
	a->next = NULL;
	a->merge = false;
	a->up = false;
	if (!*lexer)
	{
		*lexer = a;
		return ;
	}
	aux = *lexer;
	while (aux->next)
		aux = aux->next;
	aux->next = a;
}

void	insert_cmd_end(t_command **c)
{
	t_command	*a;
	t_command	*aux;

	a = protect_memory(sizeof(t_command));
	a->argv = NULL;
	a->inputf = NULL;
	a->outputf = NULL;
	a->split = NULL;
	a->add = false;
	a->here = false;
	a->core = false;
	a->value = 0;
	a->next = NULL;
	if (!*c)
	{
		*c = a;
		return ;
	}
	aux = *c;
	while (aux->next)
		aux = aux->next;
	aux->next = a;
}

void	build_cmd_args(t_minishell *ms, t_lexer *lexer, t_lexer **nt)
{
	int			i;
	t_command	*aux;

	i = 0;
	aux = ms->exe;
	while (aux->next)
		aux = aux->next;
	if (!aux->argv)
		aux->argv = ft_calloc((how_many_args(lexer) + 2), sizeof(char *));
	else
		while (aux->argv[i])
			i++;
	while (lexer && lexer->tkn == WORD)
	{
		if (lexer->lxr)
			aux->argv[i++] = ft_strdup(lexer->lxr);
		*nt = lexer->next;
		if (lexer->next && lexer->next->tkn == WORD)
			lexer = lexer->next;
		else
			break ;
	}
	if (parsin_builtin(aux->argv[0]))
		aux->core = 1;
}
