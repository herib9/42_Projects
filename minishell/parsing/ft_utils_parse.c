/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_parse.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leiamart <leiamart@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 19:36:48 by leiamart          #+#    #+#             */
/*   Updated: 2025/10/15 19:36:50 by leiamart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	modified_strchr(const char *a, int x)
{
	int	i;

	i = 0;
	while (a[i])
	{
		if (a[i] == (char)x)
			return (i + 1);
		i++;
	}
	if ((char)x == '\0')
		return (-1);
	return (-1);
}

int	get_var_name_len(char *c)
{
	int	i;

	i = 0;
	while (c[i] && (ft_isalnum(c[i]) || c[i] == '_'))
		i++;
	return (i);
}

void	free_var_exp(t_var *var)
{
	if (var)
	{
		if (var->env)
			free(var->env);
		if (var->status)
			free(var->status);
		free(var);
		var = NULL;
	}
}

void	change_at_begin(char **c, char *a, char *d)
{
	char	*z;

	if (ft_strlen(*c) > 2)
	{
		z = ft_strjoin(a, d + 2);
		free(*c);
		*c = z;
	}
	else
	{
		free(*c);
		*c = ft_strdup(a);
	}
}

void	manage_status(t_minishell *ms, t_lexer *lexer)
{
	char	*a;
	char	*c;
	int		i;

	i = -1;
	while (lexer->lxr[++i] && ft_strchr(lexer->lxr, '$')
		&& lexer->lxr[modified_strchr(lexer->lxr, '$')] != ' '
		&& lexer->lxr[modified_strchr(lexer->lxr, '$')] != '\"')
	{
		c = ft_strnstr(lexer->lxr, "$?", ft_strlen(lexer->lxr));
		if (!c)
			return ;
		a = ft_itoa(ms->prev_code);
		if (!a)
			return ;
		manage_dollar_token(lexer, c, a);
		free(a);
	}
}
