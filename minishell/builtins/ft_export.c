/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leiamart <leiamart@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 19:33:31 by leiamart          #+#    #+#             */
/*   Updated: 2025/10/15 19:33:33 by leiamart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	locate_env(char **c, char *a)
{
	int	i;

	i = 0;
	while (c && c[i])
	{
		if (!ft_strncmp(c[i], a, ft_strlen(a))
			&& (c[i][ft_strlen(a)] == '='
			|| c[i][ft_strlen(a)] == '\0'))
			return (i);
		i++;
	}
	return (-1);
}

void	display_export_env(char **c)
{
	int		i;
	char	*x;
	char	**a;

	if (!c)
		return ;
	a = save_env(c);
	if (!a)
		return ;
	order_str(a);
	i = 0;
	while (a[i])
	{
		x = ft_strchr(a[i], '=');
		if (!x)
			printf("declare -x %s\n", a[i]);
		else
		{
			*x = '\0';
			printf("declare -x %s=\"%s\"\n", a[i], x + 1);
			*x = '=';
		}
		i++;
	}
	cleaning_matrix(a);
}

int	export_builtin(t_minishell *ms, t_command *command)
{
	int	i;

	i = 1;
	if (!command->argv[1])
	{
		display_export_env(ms->var);
		return (0);
	}
	while (command->argv[i])
	{
		if (!validate_env_syntax(command->argv[i]))
		{
			printf("minishell: export: %s: not a \
valid identifier\n", command->argv[i]);
			ms->code = 1;
		}
		else
		{
			ms->var = manage_env_export(ms->var, command->argv[i],
					validate_env_syntax(command->argv[i]));
		}
		i++;
	}
	return (0);
}
