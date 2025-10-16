/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_redirections.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leiamart <leiamart@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 19:35:56 by leiamart          #+#    #+#             */
/*   Updated: 2025/10/15 19:35:59 by leiamart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	manage_redirection(t_minishell *ms, t_lexer *lxr, t_lexer **n_lxr)
{
	t_command	*aux;

	aux = ms->exe;
	while (aux->next)
		aux = aux->next;
	if (lxr->next && lxr->next->tkn == WORD)
	{
		if (lxr->tkn == RI1)
			manage_in(aux, lxr);
		else if (lxr->tkn == RO1)
			manage_out(aux, lxr);
		else if (lxr->tkn == RO2)
			parse_redirection(aux, lxr);
		else if (lxr->tkn == RI2)
			set_heredoc_delimiter(aux, lxr);
		if (aux->core == 1)
			ms->code = 1;
		else
			ms->code = 0;
		*n_lxr = lxr->next->next;
	}
	else
		*n_lxr = lxr->next;
}

int	apply_red(t_minishell *ms, t_command *command)
{
	if (command->here && redirection_heredoc(ms, command))
		return (1);
	if (!command->here && command->inputf && in_redirection(command->inputf))
		return (1);
	if (command->outputf && out_redirection(command->outputf, command->add))
		return (1);
	return (0);
}
