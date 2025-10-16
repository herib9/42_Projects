/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_minishell.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leiamart <leiamart@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 19:37:14 by leiamart          #+#    #+#             */
/*   Updated: 2025/10/15 19:37:16 by leiamart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_minishell	*struct_minishell(char **c)
{
	t_minishell	*ms;

	ms = protect_memory(sizeof(t_minishell));
	ms->line = NULL;
	ms->var = c;
	ms->code = 0;
	ms->prev_code = 0;
	ms->lexer = NULL;
	ms->exe = NULL;
	return (ms);
}

int	main(int ac, char **av, char **c)
{
	t_minishell	*ms;

	(void)ac;
	(void)av;
	if (!*c)
		return (ft_putendl_fd("minishell: enviroment can't be empty", 2), 1);
	ms = struct_minishell(save_env(c));
	run_shell(ms);
	cleaning_resources(ms->var, NULL, ms);
	return (0);
}
