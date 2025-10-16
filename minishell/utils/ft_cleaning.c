/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cleaning.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leiamart <leiamart@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 19:31:46 by leiamart          #+#    #+#             */
/*   Updated: 2025/10/15 19:31:48 by leiamart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	cleaning_resources(char **c, t_lexer *lexer, t_minishell *ms)
{
	if (c)
		cleaning_matrix(c);
	if (lexer)
		cleaning_token_list(&lexer);
	if (ms)
	{
		free(ms);
		ms = NULL;
	}
}

void	cleaning_stateshell(t_minishell *ms)
{
	if (ms->line)
	{
		free(ms->line);
		ms->line = NULL;
	}
	if (ms->lexer)
	{
		cleaning_token_list(&ms->lexer);
		ms->lexer = NULL;
	}
	if (ms->exe)
	{
		cleaning_cmd_list(&ms->exe);
		ms->exe = NULL;
	}
}
