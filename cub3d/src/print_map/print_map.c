/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manuelfe <manuelfe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/13 18:59:03 by manuelfe          #+#    #+#             */
/*   Updated: 2026/02/13 18:59:05 by manuelfe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static uint32_t	get_color(char c)
{
	uint32_t	color;

	if (c == '1')
		color = 0x000000FF;
	else if (c == ' ')
		color = 0x222222FF;
	else
		color = 0xFFFFFFFF;
	return (color);
}

void	draw_2d_map(t_game *game)
{
	int			i;
	int			j;
	int			max_dim;
	double		tile_s;

	if (game->map->h > game->map->w)
		max_dim = game->map->h;
	else
		max_dim = game->map->w;
	tile_s = ((double)MINI_MAP_SIZE / max_dim);
	j = 0;
	while (j < game->map->h)
	{
		i = 0;
		while (i < game->map->w)
		{
			if (i < (int)ft_strlen(game->map->map[j]))
				draw_square(game, (t_pos){i * tile_s, j * tile_s},
					tile_s + 1, get_color(game->map->map[j][i]));
			i++;
		}
		j++;
	}
}

void	draw_player(t_game *game)
{
	int		max_dim;
	double	tile_s;
	int		size;
	t_pos	pos;

	if (game->map->h > game->map->w)
		max_dim = game->map->h;
	else
		max_dim = game->map->w;
	tile_s = (double)MINI_MAP_SIZE / max_dim;
	pos.x = game->player->pos_x * tile_s;
	pos.y = game->player->pos_y * tile_s;
	size = tile_s / 2;
	if (size < 2)
		size = 2;
	pos.x = pos.x - size / 2;
	pos.y = pos.y - size / 2;
	draw_square(game, pos, size, 0xFF0000FF);
}

void	draw_square(t_game *game, t_pos pos, int size, uint32_t color)
{
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			if (pos.x + i >= 0 && pos.x + i < (int)game->img->width
				&& pos.y + j >= 0 && pos.y + j < (int)game->img->height)
				mlx_put_pixel(game->img, pos.x + i, pos.y + j, color);
			j++;
		}
		i++;
	}
}
