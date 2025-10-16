/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minishell.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leiamart <leiamart@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 19:34:13 by leiamart          #+#    #+#             */
/*   Updated: 2025/10/15 19:34:15 by leiamart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	shell_in(t_minishell *ms)
{
	ms->prev_code = ms->code;
	init_signals();
	ms->line = readline("minishell> ");
	if (!ms->line)
	{
		ft_putstr_fd("exit\n", 1);
		return (0);
	}
	if (g_signal_flag)
	{
		ms->prev_code = g_signal_flag;
	}
	else
		ms->code = 0;
	if (ft_strncmp(ms->line, "", 1))
		add_history(ms->line);
	return (1);
}

void	run_shell(t_minishell *ms)
{
	while (1)
	{
		if (!shell_in(ms))
			break ;
		shell_lex_input(ms);
		parse_lexer(ms);
		if (identify_dollar(ms))
			expand_all_tokens(ms);
		delete_token_q(ms);
		if (ms->lexer && manage_tkn_shell(ms))
		{
			run_all_cmd(ms);
		}
		cleaning_stateshell(ms);
	}
	cleaning_stateshell(ms);
}
