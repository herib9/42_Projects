/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leiamart <leiamart@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 19:32:27 by leiamart          #+#    #+#             */
/*   Updated: 2025/10/15 19:32:29 by leiamart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*parse_var_name(char *c)
{
	int		i;
	char	*a;

	i = 0;
	a = ft_strdup(c);
	while (a[i] && a[i] != '+' && a[i] != '=')
		i++;
	a[i] = '\0';
	return (a);
}

int	how_many_args(t_lexer *lexer)
{
	int	i;

	i = 0;
	while (lexer && (lexer->tkn == 0 || lexer->tkn == SQ || lexer->tkn == RI1
			|| lexer->tkn == RO1 || lexer->tkn == RO2 || lexer->tkn == RI2))
	{
		if (lexer->tkn == RI1 || lexer->tkn == RO1 || lexer->tkn == RO2
			|| lexer->tkn == RI2)
			lexer = lexer->next->next;
		else
		{
			i++;
			lexer = lexer->next;
		}
	}
	return (i);
}

int	length_str_array(char **a)
{
	int	i;

	i = 0;
	while (a && a[i])
		i++;
	return (i);
}
