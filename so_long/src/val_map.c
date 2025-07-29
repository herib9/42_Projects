/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   val_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmolina <<hmolina@student.42.fr>>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 18:23:39 by hmolina           #+#    #+#             */
/*   Updated: 2025/07/30 00:42:02 by hmolina          ###   ########lyon.fr   */
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
}

int	validate_map(char **map)
{
	int	height;
	int	width;

	if (!map)
	{
		ft_printf("%s, Error\nMap is empty\n");
		return (0);
	}
}

int	check_walls(t_game *game)
{
	int	y;
	int	x;

	y = 0;
	while (y < game->map_height)
	{
		if (game->map[0][y] != '1' || game->map[game->map_width - 1][y] != '1')
			return (ft_printf("Error, Walls opened at width%i\n", y), 1);
		y++;
	}
	x = 0;
	while (x < game->map_width)
	{
		if (game->map[0][x] != '1' || game->map[game->map_height - 1][x] != '1')
			return (ft_printf("Error, Walls openes at height%i\n", x), 1);
		x++;
	}
	return (0);
}

void	check_elements(t_game *game)
{
	int	y;
	int	x;

	game->player = 0;
	game->exit = 0;
	game->collectible = 0;
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
				game->collectible++;
			x++;
		}
		y++;
	}
}

void	init(t_items *game)
{
	game->player = 0;
}