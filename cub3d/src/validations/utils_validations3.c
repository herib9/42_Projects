/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_validations3.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manuelfe <manuelfe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/13 19:00:04 by manuelfe          #+#    #+#             */
/*   Updated: 2026/02/13 19:00:05 by manuelfe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	list_to_map(t_game *game)
{
	if (!game->list)
		return (1);
	game->map = ft_calloc(1, sizeof(t_map));
	if (!game->map)
	{
		ft_printf("Error\nThe file was not found\n");
		return (1);
	}
	game->map->init_position = ft_calloc(1, sizeof(t_pos));
	if (!game->map->init_position)
	{
		ft_printf("Error\nmemory failure when loading initial position\n");
		return (1);
	}
	ft_create_size_map(game->list, game->map);
	game->list = NULL;
	if (!game->map->map)
	{
		ft_printf("Error\nFail to load map\n");
		return (1);
	}
	return (validate_map(game->map));
}

int	is_map(char *line)
{
	int	i;

	i = 0;
	while (line && line[i] != '\0')
	{
		if (is_char_valid(line[i]) == -1)
			return (1);
		i++;
	}
	return (0);
}

int	init_flood_fill(t_map *map)
{
	int		valido;
	char	**cpy_map;

	cpy_map = ft_copy_map(map->map, map->h, map->w);
	if (!cpy_map)
		return (-1);
	valido = flood_fill(cpy_map, (t_pos){map->init_position->x,
			map->init_position->y}, map->h, map->w);
	free_cpy_map(cpy_map);
	if (valido == 1)
	{
		ft_printf("Error\nMaps with walls open\n");
		return (-1);
	}
	return (valido);
}
