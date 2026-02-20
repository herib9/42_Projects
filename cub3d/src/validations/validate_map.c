/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manuelfe <manuelfe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/13 19:00:10 by manuelfe          #+#    #+#             */
/*   Updated: 2026/02/13 19:00:12 by manuelfe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	save_map(char *line, char *trim, t_list **list)
{
	t_list	*new_node;
	t_list	*p;
	int		len;

	len = 0;
	p = *list;
	if (ft_strlen(trim) == 0 && p != NULL)
	{
		ft_free_list(p);
		*list = NULL;
		return (-1);
	}
	else if (ft_strlen(trim) == 0 && p == NULL)
		return (0);
	len = ft_strlen(line);
	if (len > 0 && line[len - 1] == '\n')
		line[len - 1] = '\0';
	new_node = ft_lstnew(ft_strdup(line));
	ft_lstadd_back(list, new_node);
	return (0);
}

int	ft_create_size_map(t_list *list_lines, t_map *map)
{
	t_list	*p;
	int		h;
	int		w;
	int		max_w;

	h = ft_lstsize(list_lines);
	if (h == 0)
		return (-1);
	p = list_lines;
	max_w = 0;
	while (p)
	{
		w = ft_strlen(p->content);
		if (max_w < w)
			max_w = w;
		p = p->next;
	}
	map->h = h;
	map->w = max_w;
	map->map = ft_line_to_map(list_lines, h, max_w);
	if (!map->map)
		return (-1);
	return (0);
}

char	**ft_line_to_map(t_list *list, int h, int w)
{
	int		k;
	char	**map;
	t_list	*p;

	map = allocate_map_lines(h, w);
	if (!map)
		return (NULL);
	k = 0;
	p = list;
	while (p)
	{
		copy_line_from_node(p, map[k], w);
		p = p->next;
		k++;
	}
	ft_free_list(list);
	return (map);
}

int	validate_wall(char **map)
{
	int		i;
	char	*line;
	int		error;

	error = 0;
	i = 0;
	while (map[i] && error == 0)
	{
		line = clean_line(map[i]);
		if (line[0] != '1' || line[ft_strlen(line) - 1] != '1')
		{
			ft_printf("Error\nThe walls are incorrect\n");
			return (-1);
		}
		free(line);
		i++;
	}
	return (error);
}

int	validate_map(t_map *map)
{
	int		i;
	int		j;
	int		p_c;

	i = 0;
	p_c = 0;
	while (i < map->h)
	{
		j = 0;
		while (j < map->w)
		{
			if (is_player_char(map->map[i][j], map, (t_pos){j, i}, &p_c) == -1)
				return (-1);
			j++;
		}
		i++;
	}
	if (p_c == 0 || p_c > 1)
	{
		ft_printf("Error\nError number of player in the game\n");
		return (-1);
	}
	if (init_flood_fill(map) == -1 || validate_wall(map->map) == -1)
		return (-1);
	return (0);
}
