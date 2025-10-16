/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_manage_env.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leiamart <leiamart@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 19:34:05 by leiamart          #+#    #+#             */
/*   Updated: 2025/10/15 19:34:07 by leiamart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*locate_operator(char *c)
{
	int	i;

	i = 0;
	while (c[i])
	{
		if (c[i] == '+' && c[i + 1] == '=')
			return (c + i);
		i++;
	}
	return (NULL);
}

char	*manage_concatenated_env(char *a, char *z, char *s)
{
	char	*v;
	char	*aux;
	int		x;
	int		i;

	x = s - a;
	aux = ft_strjoin(z, s + 2);
	v = malloc(x + 1 + ft_strlen(aux) + 1);
	if (!v)
		return (NULL);
	i = 0;
	while (i < x)
	{
		v[i] = a[i];
		i++;
	}
	v[x] = '=';
	ft_strlcpy(v + x + 1, aux, ft_strlen(aux) + 1);
	free(aux);
	return (v);
}

char	**merge_env_value(char **a, char *c, int i)
{
	char	*s;
	char	*aux;
	char	*z;

	aux = locate_operator(c);
	if (!aux)
		return (a);
	s = ft_strchr(a[i], '=');
	if (!s)
		z = ft_strdup("");
	else
		z = ft_strdup(s + 1);
	free(a[i]);
	a[i] = manage_concatenated_env(c, z, aux);
	free(z);
	return (a);
}
