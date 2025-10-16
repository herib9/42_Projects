/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing_pipe_and_red.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leiamart <leiamart@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 19:35:17 by leiamart          #+#    #+#             */
/*   Updated: 2025/10/15 19:35:19 by leiamart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	parse_token_redirection(t_minishell *ms, int *i)
{
	if (ms->line[*i] == '<')
	{
		if (ms->line[*i +1] == '<')
		{
			insert_token_end(&ms->lexer, "<<", 7);
			*i += 2;
			return ;
		}
		insert_token_end(&ms->lexer, "<", 6);
		*i += 1;
	}
	else if (ms->line[*i] == '>')
	{
		if (ms->line[*i +1] == '>')
		{
			insert_token_end(&ms->lexer, ">>", 5);
			*i += 2;
			return ;
		}
		insert_token_end(&ms->lexer, ">", 4);
		*i += 1;
	}
}

int	parsing_pipe(t_minishell *ms)
{
	t_lexer	*aux;

	aux = ms->lexer;
	if (!aux)
		return (1);
	if (aux->tkn == PI)
	{
		lexer_pipe_parse();
		return (cleaning_token_list(&ms->lexer), 0);
	}
	while (aux)
	{
		if (aux->tkn == PI && aux->next && aux->next->tkn == PI)
		{
			lexer_pipe_parse();
			return (cleaning_token_list(&ms->lexer), 0);
		}
		if (aux->next == NULL && aux->tkn == PI)
		{
			lexer_pipe_parse();
			return (cleaning_token_list(&ms->lexer), 0);
		}
		aux = aux->next;
	}
	return (1);
}

int	parsing_redirection(t_minishell *ms)
{
	t_lexer	*aux;

	aux = ms->lexer;
	if (!aux)
		return (1);
	while (aux)
	{
		if (aux->tkn > 3 && aux->tkn < 8)
		{
			if (!aux->next || aux->next->tkn > 2)
			{
				ft_putstr_fd("minishell: lexer error redirection\n", 2);
				return (cleaning_token_list(&ms->lexer), 0);
			}
		}
		aux = aux->next;
	}
	return (1);
}
