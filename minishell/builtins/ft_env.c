/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leiamart <leiamart@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 19:32:09 by leiamart          #+#    #+#             */
/*   Updated: 2025/10/15 19:32:11 by leiamart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**update_env_if_exist(char **c, char *a, int i)
{
	free(c[i]);
	c[i] = ft_strdup(a);
	return (c);
}

int	validate_env_syntax(char *c)
{
	int	i;

	if (!c || (!ft_isalpha(c[0]) && c[0] != '_'))
		return (0);
	i = 1;
	while (c[i] && c[i] != '=')
	{
		if (c[i] != '_' && !ft_isalnum(c[i]) && c[i] != '+')
			return (0);
		if (c[i - 1] && ft_isalnum(c[i - 1])
			&& c[i] == '+' && c[i + 1] == '=')
			return (2);
		i++;
	}
	return (1);
}

char	**manage_env_export(char **c, char *s, int x)
{
	char	*v;
	char	**a;
	int		i;

	v = parse_var_name(s);
	i = locate_env(c, v);
	free(v);
	if (i != -1 && x == 1)
		return (update_env_if_exist(c, s, i));
	if (i != -1 && x == 2)
		return (merge_env_value(c, s, i));
	a = copy_env_var_end(c, s);
	if (!a)
		return (NULL);
	cleaning_matrix(c);
	return (a);
}

void	order_str(char **c)
{
	int		i;
	int		x;

	i = 0;
	x = 0;
	while (c[x])
	{
		i = 0;
		while (c[i + 1])
		{
			if (ft_strcmp(c[i], c[i + 1]) > 0)
				ft_swap(&c[i], &c[i + 1]);
			i++;
		}
		x++;
	}
}

int	manage_builtins(t_minishell *ms)
{
	int	i;

	i = 0;
	manage_env_export(ms->var, "_=/usr/bin/env", 1);
	while (ms->var[i])
	{
		if (ft_strchr(ms->var[i], '='))
			printf("%s\n", ms->var[i]);
		i++;
	}
	return (0);
}
