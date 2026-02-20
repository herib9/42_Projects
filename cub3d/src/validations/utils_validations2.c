/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_validations2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manuelfe <manuelfe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/13 18:59:57 by manuelfe          #+#    #+#             */
/*   Updated: 2026/02/13 18:59:58 by manuelfe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	**allocate_map_lines(int h, int w)
{
	int		k;
	char	**map;

	map = malloc(sizeof(char *) * (h + 1));
	if (!map)
		return (NULL);
	k = 0;
	while (k < h)
	{
		map[k] = malloc(sizeof(char) * (w + 1));
		if (!map[k])
		{
			while (k > 0)
				free(map[--k]);
			free(map);
			return (NULL);
		}
		k++;
	}
	map[h] = NULL;
	return (map);
}

void	copy_line_from_node(t_list *node, char *dest, int w)
{
	int	i;

	i = 0;
	while (node->content && (node->content[i] != '\0'))
	{
		dest[i] = node->content[i];
		i++;
	}
	while (i < w)
	{
		dest[i] = ' ';
		i++;
	}
	dest[i] = '\0';
}

int	check_file_extension(char *file)
{
	int	len;

	if (!file)
		return (-1);
	len = ft_strlen(file);
	if (len < 5)
		return (-1);
	if (ft_strncmp(file + len - 4, ".cub", 4) != 0)
		return (-1);
	return (0);
}

int	is_valid_number(char *s)
{
	int	i;

	i = 0;
	if (!s || s[0] == '\0')
		return (-1);
	while (s[i])
	{
		if (!ft_isdigit(s[i]))
			return (-1);
		i++;
	}
	return (0);
}
