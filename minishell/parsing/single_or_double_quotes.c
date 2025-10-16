/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   single_or_double_quotes.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leiamart <leiamart@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 19:37:35 by leiamart          #+#    #+#             */
/*   Updated: 2025/10/15 19:37:37 by leiamart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	manage_double_q(t_minishell *ms, int *i)
{
	char	*c;
	int		x;
	int		p;

	x = *i;
	p = 0;
	while (ms->line[x++])
	{
		if (ms->line[x] == 34)
		{
			p = 1;
			c = ft_substr(ms->line, *i, (x - *i) + 1);
			insert_token_end(&ms->lexer, c, 2);
			if (ms->line[x + 1] != '<' && ms->line[x + 1] != '>'
				&& ms->line[x + 1] != '|' && ms->line[x + 1] != ' '
				&& ms->line[x + 1] != '\0')
				last_tkn(&ms->lexer);
			free(c);
			break ;
		}
	}
	*i = x + 1;
	if (p == 0)
		return (printing_lexer_error("`\"'\n"), 0);
	return (1);
}

int	manage_single_q(t_minishell *ms, int *i)
{
	char	*c;
	int		x;
	int		p;

	x = *i;
	p = 0;
	while (ms->line[x++])
	{
		if (ms->line[x] == 39)
		{
			p = 1;
			c = ft_substr(ms->line, *i, (x - *i) + 1);
			insert_token_end(&ms->lexer, c, 1);
			if (ms->line[x + 1] != '<' && ms->line[x + 1] != '>'
				&& ms->line[x + 1] != '|' && ms->line[x + 1] != ' '
				&& ms->line[x + 1] != '\0')
				last_tkn(&ms->lexer);
			free(c);
			break ;
		}
	}
	*i = x + 1;
	if (p == 0)
		return (printing_lexer_error("`\''\n"), 0);
	return (1);
}

int	single_or_double_quotes(t_minishell *ms, int *i)
{
	if (ms->line[*i] == 34)
	{
		if (!manage_double_q(ms, i))
		{
			ms->code = 1;
			cleaning_token_list(&ms->lexer);
			return (0);
		}
	}
	else if (ms->line[*i] == 39)
	{
		if (! manage_single_q(ms, i))
		{
			ms->code = 1;
			cleaning_token_list(&ms->lexer);
			return (0);
		}
	}
	return (1);
}
