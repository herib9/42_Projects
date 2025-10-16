/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env_parsing.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leiamart <leiamart@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 19:32:19 by leiamart          #+#    #+#             */
/*   Updated: 2025/10/15 19:32:20 by leiamart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*strip_plus_equal(char *c)
{
	char	*a;
	char	*z;
	int		x;
	int		i;

	a = locate_operator(c);
	if (!a)
		return (ft_strdup(c));
	x = a - c;
	z = malloc(ft_strlen(c));
	if (!z)
		return (NULL);
	i = 0;
	while (i < x)
	{
		z[i] = c[i];
		i++;
	}
	z[x] = '=';
	ft_strlcpy(z + x + 1, a + 2, ft_strlen(a + 2) + 1);
	return (z);
}

char	**copy_env_var_end(char **c, char *s)
{
	int		x;
	int		i;
	char	**a;

	x = length_str_array(c);
	a = malloc(sizeof(char *) * (x + 2));
	if (!a)
		return (NULL);
	i = 0;
	while (i < x)
	{
		a[i] = ft_strdup(c[i]);
		i++;
	}
	a[i] = strip_plus_equal(s);
	a[i + 1] = NULL;
	return (a);
}

char	*giveme_value_env(char **c, char *a)
{
	int		i;

	i = 0;
	while (c[i])
	{
		if (!ft_strncmp(c[i], a, ft_strlen(a))
			&& c[i][ft_strlen(a)] == '=')
			return (ft_strdup(&c[i][ft_strlen(a) + 1]));
		i++;
	}
	return (NULL);
}

void	expand_all_tokens(t_minishell *ms)
{
	t_lexer	*aux;

	aux = ms->lexer;
	while (aux)
	{
		if (aux->up == true)
			var_in_token(ms, aux);
		aux = aux->next;
	}
}

char	**delete_env(char **c, char *b)
{
	int		n;
	int		t;
	int		i;
	int		x;
	char	**a;

	n = locate_env(c, b);
	if (n == -1)
		return (c);
	t = length_str_array(c);
	a = malloc(sizeof(char *) * t);
	if (!a)
		return (NULL);
	i = 0;
	x = 0;
	while (c[i])
	{
		if (i != n)
			a[x++] = ft_strdup(c[i]);
		i++;
	}
	a[x] = NULL;
	cleaning_matrix(c);
	return (a);
}
