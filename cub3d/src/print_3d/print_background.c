/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_background.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manuelfe <manuelfe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/13 18:58:40 by manuelfe          #+#    #+#             */
/*   Updated: 2026/02/13 18:58:41 by manuelfe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static uint32_t	get_rgba(t_color *rgb)
{
	return ((uint32_t)rgb->r << 24 | (uint32_t)rgb->g << 16
		| (uint32_t)rgb->b << 8 | (uint32_t)255);
}

void	print_back_ground(t_game *game)
{
	int			x;
	int			y;
	uint32_t	ceiling;
	uint32_t	floor;

	ceiling = get_rgba(game->ceiling);
	floor = get_rgba(game->floor);
	y = -1;
	while (++y < HEIGHT)
	{
		x = -1;
		while (++x < WIDTH)
		{
			if (y < HEIGHT / 2)
				mlx_put_pixel(game->img_3d, x, y, ceiling);
			else
				mlx_put_pixel(game->img_3d, x, y, floor);
		}
	}
}
