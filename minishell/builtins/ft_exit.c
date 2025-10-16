/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leiamart <leiamart@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 19:33:23 by leiamart          #+#    #+#             */
/*   Updated: 2025/10/15 19:33:25 by leiamart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	when_exit_free(t_minishell *ms)
{
	cleaning_stateshell(ms);
	cleaning_resources(ms->var, NULL, ms);
}

void	exit_builtin(t_minishell *ms, t_command *command, int i)
{
	int	x;

	x = 0;
	if (command->argv[1])
	{
		if (!ft_is_num(command->argv[1]))
		{
			printf("exit\n");
			printf("minishell: exit: %s: num required\n", command->argv[1]);
			when_exit_free(ms);
			exit(2);
		}
		x = (ft_atoi(command->argv[1]) % 256);
		if (command->argv[2])
		{
			printf("minishell: exit: too many arguments\n");
			ms->prev_code = 1;
			return ;
		}
	}
	if (i == -1)
		printf("exit\n");
	when_exit_free(ms);
	exit((unsigned char)x);
}
