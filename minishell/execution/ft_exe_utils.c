/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exe_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmolina <<hmolina@student.42.fr>>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 19:33:11 by leiamart          #+#    #+#             */
/*   Updated: 2025/10/16 15:29:02 by hmolina          ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "minishell.h"

char	*manage_env_expansion(int *i, char *a, char **c, int x)
{
	int		b;
	char	*k;
	char	*z;

	(*i)++;
	if (a[*i] == '?')
	{
		(*i)++;
		return (ft_itoa(x));
	}
	b = *i;
	while (a[*i] && (a[*i] == '_' || ft_isalnum(a[*i])))
		(*i)++;
	if (b == *i)
		return (ft_strdup("$"));
	z = ft_substr_two(a, b, (*i) - b + 1);
	k = giveme_value_env(c, z);
	free(z);
	if (!k)
		return (ft_strdup(""));
	return (k);
}

char	*get_literal_segment(int *i, char *c)
{
	int	x;

	x = *i;
	while (c[*i] && c[*i] != '$')
		(*i)++;
	if (c[*i] == '$')
	{
		if (!c[*i + 1])
			(*i)++;
		else if (c[*i + 1] && !(ft_isalpha(c[*i + 1])
				|| c[*i + 1] == '_' || c[*i + 1] == '?'))
			c[*i] = '\0';
	}
	return (ft_substr_two(c, x, (*i) - x + 1));
}
