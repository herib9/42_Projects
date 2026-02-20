/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manuelfe <manuelfe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/13 18:58:56 by manuelfe          #+#    #+#             */
/*   Updated: 2026/02/13 18:58:57 by manuelfe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_direction_line(t_game *game)
{
	int			target_x;
	int			target_y;
	uint32_t	color;
	int			max_dim;
	double		tile_s;

	if (game->map->h > game->map->w)
		max_dim = game->map->h;
	else
		max_dim = game->map->w;
	tile_s = (double)MINI_MAP_SIZE / max_dim;
	color = 0xFF0000FF;
	target_x = (game->player->pos_x
			+ game->player->dir_x * 2.0) * tile_s;
	target_y = (game->player->pos_y
			+ game->player->dir_y * 2.0) * tile_s;
	draw_line(game, target_x, target_y, color);
}

static double	get_tile_s(int h, int w)
{
	int	max_dim;

	if (h > w)
		max_dim = h;
	else
		max_dim = w;
	return ((double)MINI_MAP_SIZE / max_dim);
}

void	draw_line(t_game *game, int t_x, int t_y, uint32_t color)
{
	int			steps;
	t_direction	inc;
	double		x;
	double		y;
	int			i;

	x = game->player->pos_x * get_tile_s(game->map->h, game->map->w);
	y = game->player->pos_y * get_tile_s(game->map->h, game->map->w);
	if (fabs(t_x - x) > fabs(t_y - y))
		steps = fabs(t_x - x);
	else
		steps = fabs(t_y - y);
	inc.dir_x = (t_x - x) / (double)steps;
	inc.dir_y = (t_y - y) / (double)steps;
	i = 0;
	while (i <= steps)
	{
		if (x >= 0 && x < (int)game->img->width
			&& y >= 0 && y < (int)game->img->height)
			mlx_put_pixel(game->img, round(x), round(y), color);
		x += inc.dir_x;
		y += inc.dir_y;
		i++;
	}
}
