/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_wall_slice.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manuelfe <manuelfe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/13 18:58:24 by manuelfe          #+#    #+#             */
/*   Updated: 2026/02/13 18:58:26 by manuelfe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static mlx_texture_t	*get_texture(t_game *game, t_ray *ray)
{
	if (ray->side == 0)
	{
		if (ray->step_x > 0)
			return (game->texture->west_tex);
		return (game->texture->east_tex);
	}
	if (ray->step_y > 0)
		return (game->texture->north_tex);
	return (game->texture->south_tex);
}

static uint32_t	get_texture_color(mlx_texture_t *tex, int tex_x, int tex_y)
{
	int		index;
	uint8_t	*pixel;

	index = (tex_y * tex->width + tex_x) * tex->bytes_per_pixel;
	pixel = &tex->pixels[index];
	return (pixel[0] << 24 | pixel[1] << 16 | pixel[2] << 8 | pixel[3]);
}

static void	draw_texture_c(t_game *game, t_ray *ray, int x, mlx_texture_t *tex)
{
	t_draw	d;
	int		y;
	int		tex_y;

	init_draw(game, ray, tex, &d);
	y = d.start - 1;
	while (++y < d.end)
	{
		tex_y = (int)d.tex_pos & (tex->height - 1);
		mlx_put_pixel(game->img_3d, x, y,
			get_texture_color(tex, d.tex_x, tex_y));
		d.tex_pos += d.step;
	}
}

void	draw_wall_slice(t_game *game, t_ray *ray, int x)
{
	mlx_texture_t	*texture;

	if (ray->perp_wall_dist == 0 || ray->hit == 0 || ray->perp_wall_dist > 1000)
		return ;
	texture = get_texture(game, ray);
	if (!texture)
		return ;
	draw_texture_c(game, ray, x, texture);
}
