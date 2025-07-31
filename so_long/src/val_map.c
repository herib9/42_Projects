/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   val_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmolina <<hmolina@student.42.fr>>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 18:23:39 by hmolina           #+#    #+#             */
/*   Updated: 2025/07/31 23:50:15 by hmolina          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	count_map_height(char **map)
{
	int	height;

	height = 0;
	while (map[height] != NULL)
		height++;
	return (height);
}

int	is_rectangular(char **map, int height, int width)
{
	int	i;
	int	actual_width;

	i = 0;
	while (i < height)
	{
		actual_width = ft_strlen(map[i]);
		if (actual_width != width)
			return (0);
		i++;
	}
	return (1);
}

int	validate_map(char **map)
{
	int	height;
	int	width;

	if (!map)
		return (ft_printf("Error\nMap is empty\n"), 0);
	height = count_map_height(map);
	if (height == 0)
		return (ft_printf("Error\nMap has no lines\n"), 0);
	width = ft_strlen(map[0]);
	if (width == 0)
		return (ft_printf("Error\nMap width is zero\n"), 0);
	if (!is_rectangular(map, height, width))
		return (ft_printf("Error\nMap is not rectangular\n"), 0);
	return (1);
}

int	check_walls(t_game *g)
{
	int	y;
	int	x;

	y = 0;
	while (y < g->map_height)
	{
		if (g->map[y][0] != '1' || g->map[g->map_width - 1] != '1')
			return (ft_printf("Error, Walls opened at width%i\n", y), 1);
		y++;
	}
	x = 0;
	while (x < g->map_width)
	{
		if (g->map[0][x] != '1' || g->map[g->map_height - 1][x] != '1')
			return (ft_printf("Error, Walls openes at height%i\n", x), 1);
		x++;
	}
	return (0);
}

void	check_elements(t_game *g)
{
	int	y;
	int	x;

	game->player = 0;
	game->exit = 0;
	game->coin = 0;
	y = 0;
	while (y < game->map_height)
	{
		x = 0;
		while (x < game->map_width)
		{
			if (game->map[y][x] == 'P')
				game->player++;
			else if (game->map[y][x] == 'E')
				game->exit++;
			else if (game->map[y][x] == 'C')
				game->coin++;
			x++;
		}
		y++;
	}
}

/*void	init(t_items *game)
{
	game->player = 0;
}*/