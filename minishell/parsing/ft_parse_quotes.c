/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_quotes.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leiamart <leiamart@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 19:34:34 by leiamart          #+#    #+#             */
/*   Updated: 2025/10/15 19:34:36 by leiamart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	last_tkn(t_lexer **lexer)
{
	t_lexer	*aux;

	aux = *lexer;
	while (aux->next)
		aux = aux->next;
	aux->merge = true;
}

void	just_one_tkn(t_minishell *ms)
{
	t_lexer	*a;
	t_lexer	*p;
	char	*c;

	a = ms->lexer;
	while (a && a->next)
	{
		p = a->next;
		if (a->merge == true && a->tkn < 4)
		{
			c = ft_strjoin(a->lxr, p->lxr);
			free(a->lxr);
			a->lxr = c;
			a->merge = p->merge;
			a->next = p->next;
			free(p->lxr);
			free(p);
		}
		else
			a = a->next;
	}
}

char	*delete_q(char *c)
{
	int		i;
	int		x;
	char	*a;
	char	z;

	a = protect_memory(ft_strlen(c) + 1);
	i = 0;
	x = 0;
	while (c[i])
	{
		if (c[i] == '\'' || c[i] == '\"')
		{
			z = c[i++];
			while (c[i] && c[i] != z)
				a[x++] = c[i++];
			if (c[i] == z)
				i++;
		}
		else
			a[x++] = c[i++];
	}
	a[x] = '\0';
	return (a);
}

void	delete_token_q(t_minishell *ms)
{
	t_lexer	*aux;
	char	*a;

	aux = ms->lexer;
	while (aux)
	{
		if (aux->tkn == SQ || aux->tkn == DQ || aux->tkn == WORD)
		{
			a = delete_q(aux->lxr);
			if (a)
			{
				free(aux->lxr);
				aux->lxr = a;
				aux->tkn = WORD;
			}
		}
		aux = aux->next;
	}
	just_one_tkn(ms);
}
