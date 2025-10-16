/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_path_exe.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leiamart <leiamart@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 19:35:33 by leiamart          #+#    #+#             */
/*   Updated: 2025/10/15 19:35:35 by leiamart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free_path_list(char **c, int i)
{
	while (c[i])
		free(c[i++]);
	free(c);
}

char	*find_exe_on_path(char **c, char *a)
{
	int		i;
	char	*d;
	char	*aux;

	i = 0;
	while (c[i])
	{
		aux = ft_strjoin(c[i], "/");
		d = ft_strjoin(aux, a);
		free(aux);
		if (access(d, F_OK | X_OK) == 0)
		{
			free_path_list(c, i);
			return (d);
		}
		free(d);
		i++;
	}
	i = 0;
	free_path_list(c, i);
	return (NULL);
}

char	*get_exe_path(char *a, char **c)
{
	char	**b;

	if (ft_strchr(c[0], '/'))
	{
		if (access(c[0], F_OK | X_OK) == 0)
			return (ft_strdup(c[0]));
		return (NULL);
	}
	if (!a)
		return (NULL);
	b = ft_split(a + 5, ':');
	return (find_exe_on_path(b, c[0]));
}
