/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmolina <<hmolina@student.42.fr>>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 18:31:25 by hmolina           #+#    #+#             */
/*   Updated: 2025/08/07 19:22:54 by hmolina          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_walls(t_game *g)
{
	int	y;
	int	x;

	y = 0;
	while (y < g->map_height)
	{
		if (g->map[y][0] != '1' || g->map[y][g->map_width - 1] != '1')
			return (ft_printf("Error\nWalls opened at width %i\n", y), 1);
		y++;
	}
	x = 0;
	while (x < g->map_width)
	{
		if (g->map[0][x] != '1' || g->map[g->map_height - 1][x] != '1')
			return (ft_printf("Error\nWalls opened at height %i\n", x), 1);
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

int	check_valid_chars(t_game *g)
{
	int		y;
	int		x;
	char	c;

	y = 0;
	while (y < g->map_height)
	{
		x = 0;
		while (x < g->map_width)
		{
			c = g->map[y][x];
			if (c != '1' && c != '0' && c != 'C' && c != 'E' && c != 'P')
				return (ft_printf("Invalid char '%c' at position [%d,%d]\n",
						c, y, x), 0);
			x++;
		}
		y++;
	}
	return (1);
}

int	check_coins_accesibility(t_game *g)
{
	char	**map_copy;
	int		access_coins;
	int		x;
	int		y;

	map_copy = copy_map(g->map, g->map_height);
	if (!map_copy)
		return (0);
	flood_fill(map_copy, g->p_x, g->p_y, g);
	access_coins = 0;
	y = -1;
	while (++y < g->map_height)
	{
		x = -1;
		while (++x < g->map_width)
		{
			if (g->map[y][x] == 'C' && map_copy[y][x] == 'V')
				access_coins++;
		}
	}
	free_map(map_copy);
	if (access_coins != g->t_coin)
		return (ft_printf("Error\nCoins arent accesible (%d/%d)\n",
				access_coins, g->t_coin), 0);
	return (1);
}

int	check_exit_accesibility(t_game *g)
{
	char	**map_copy;
	int		access_exit;
	int		x;
	int		y;

	map_copy = copy_map(g->map, g->map_height);
	if (!map_copy)
		return (0);
	exit_flood_fill(map_copy, g->p_x, g->p_y, g);
	access_exit = 0;
	y = -1;
	while (++y < g->map_height)
	{
		x = -1;
		while (++x < g->map_width)
		{
			if (g->map[y][x] == 'E' && map_copy[y][x] == 'V')
				access_exit = 1;
		}
	}
	free_map(map_copy);
	if (!access_exit)
		return (ft_printf("Error\nExit isnt accessible\n"), 0);
	return (1);
}
