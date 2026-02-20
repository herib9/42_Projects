/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_tokens.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manuelfe <manuelfe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/13 18:59:31 by manuelfe          #+#    #+#             */
/*   Updated: 2026/02/13 18:59:33 by manuelfe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	num_tokens(char **tok)
{
	int	num_tokens;

	num_tokens = 0;
	while (tok && tok[num_tokens] != NULL)
		num_tokens++;
	return (num_tokens);
}

void	free_tokens(char **tk)
{
	int	i;

	i = 0;
	while (tk[i])
	{
		free(tk[i]);
		i++;
	}
	free(tk);
}

void	ft_free_list(t_list *list)
{
	t_list	*tmp;

	while (list)
	{
		tmp = list->next;
		free(list->content);
		free(list);
		list = tmp;
	}
	list = NULL;
}
