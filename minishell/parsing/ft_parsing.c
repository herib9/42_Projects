/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leiamart <leiamart@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 19:34:52 by leiamart          #+#    #+#             */
/*   Updated: 2025/10/15 19:34:53 by leiamart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	identify_dollar(t_minishell *ms)
{
	t_lexer	*aux;
	int		i;

	aux = ms->lexer;
	i = 0;
	while (aux)
	{
		if ((ft_strchr(aux->lxr, '$') != 0) && (aux->tkn != 1))
		{
			aux->up = true;
			i = 1;
		}
		aux = aux->next;
	}
	return (i);
}

void	variables_expand(t_minishell *ms)
{
	t_lexer	*aux;

	aux = ms->lexer;
	while (aux)
	{
		if (aux->up == true)
			var_in_token(ms, aux);
		aux = aux->next;
	}
}

void	manage_dollar_token(t_lexer *lexer, char *c, char *a)
{
	char	*z;
	int		i;

	i = c - lexer->lxr;
	if (i == 0)
		change_at_begin(&lexer->lxr, a, c);
	else
	{
		z = insert_between(lexer->lxr, c, a);
		free(lexer->lxr);
		lexer->lxr = z;
	}
}

char	*insert_between(char *c, char *d, char *x)
{
	char	*a;
	char	*b;
	char	*aux;
	char	*z;
	int		i;

	i = d - c;
	a = ft_substr(c, 0, i);
	b = ft_strdup(d + 2);
	aux = ft_strjoin(a, x);
	z = ft_strjoin(aux, b);
	free(a);
	free(b);
	free(aux);
	return (z);
}

t_var	*start_var_struct(void)
{
	t_var	*var;

	var = protect_memory(sizeof (t_var));
	var->begin = -1;
	var->limit = -1;
	var->env = NULL;
	var->status = NULL;
	return (var);
}
