/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmolina <<hmolina@student.42.fr>>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 00:57:00 by hmolina           #+#    #+#             */
/*   Updated: 2025/07/31 19:35:46 by hmolina          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	find_player_position(t_game *g)
{
	int	x;
	int	y;

	y = 0;
	while (y < g->map_height)
	{
		x = 0;
		while (x < g->map_width)
		{
			if (g->map[y][x] == PLAYER)
			{
				g->p_x = x;
				g->p_y = y;
				return ;
			}
			x++;
		}
		y++;
	}
}

void	find_exit_position(t_game *g)
{
	int	y;
	int	x;

	y = 0;
	while (y < g->map_height)
	{
		x = 0;
		while (x < g->map_width)
		{
			if (g->map[y][x] == EXIT)
			{
				g->exit_x = x;
				g->exit_y = y;
				return ;
			}
			x++;
		}
		y++;
	}
}

void	count_coin(t_game *g)
{
	int	x;
	int	y;

	g->t_coin = 0;
	y = 0;
	while (y < g->map_height)
	{
		x = 0;
		while (x < g->map_width)
		{
			if (g->map[y][x] == COIN)
				g->t_coin++;
			x++;
		}
		y++;
	}
}
