/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing_lexer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leiamart <leiamart@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 19:35:02 by leiamart          #+#    #+#             */
/*   Updated: 2025/10/15 19:35:04 by leiamart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	printing_lexer_error(char *c)
{
	char	*a;

	a = "minishell: lexer error ";
	a = ft_strjoin(a, c);
	ft_putstr_fd(a, 2);
	free(a);
}

void	lexer_pipe_parse(void)
{
	ft_putstr_fd("minishell: lexer error unexpected token `|'\n", 2);
}

void	parse_lexer(t_minishell *ms)
{
	if (!parsing_pipe(ms))
	{
		ms->code = 2;
		return ;
	}
	if (!parsing_redirection(ms))
	{
		ms->code = 2;
		return ;
	}
}
