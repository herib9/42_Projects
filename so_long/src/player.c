/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmolina <<hmolina@student.42.fr>>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 00:57:00 by hmolina           #+#    #+#             */
/*   Updated: 2025/07/29 21:48:56 by hmolina          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	find_player_position(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->map_height)
	{
		x = 0;
		while (x < game->map_width)
		{
			if (game->map[y][x] == PLAYER)
			{
				game->player_x = x;
				game->player_y = y;
				return ;
			}
			x++;
		}
		y++;
	}
}

void	find_exit_position(t_game *game)
{
	int	y;
	int	x;
	
	y = 0;
	while (y < game->map_height)
	{
		x = 0;
		while (x < game->map_width)
		{
			if (game->map[y][x] == EXIT)
			{
				game->exit_x = x;
				game->exit_y = y;
				return ;
			}
			x++;
		}
		y++;
	}
}

void	count_collectibles(t_game *game)
{
	int	x;
	int	y;

	game->total_totallectibles = 0;
	y = 0;
	while (y < game->map_height)
	{
		x = 0;
		while (x < game->map_width)
		{
			if (game->map[y][x] == COLLECTIBLE)
				game->total_collectibles++;
			x++;
		}
		y++;
	}
}

void	move_player(t_game *game, int dx, int dy)
{
	
}