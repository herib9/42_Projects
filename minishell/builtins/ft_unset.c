/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leiamart <leiamart@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 19:36:23 by leiamart          #+#    #+#             */
/*   Updated: 2025/10/15 19:36:25 by leiamart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	unset_builtin(t_minishell *ms, t_command *command)
{
	int	i;

	i = 1;
	while (command->argv[i])
	{
		if (!validate_env_syntax(command->argv[i]))
		{
			printf("minishell: unset: %s: \
				       	not valid identifier\n", command->argv[i]);
			ms->code = 1;
		}
		else
			ms->var = delete_env(ms->var, command->argv[i]);
		i++;
	}
	return (0);
}
