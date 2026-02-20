/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_3d.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manuelfe <manuelfe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/13 18:58:31 by manuelfe          #+#    #+#             */
/*   Updated: 2026/02/13 18:58:33 by manuelfe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static double	calculate_wall_x(t_game *game, t_ray *ray)
{
	double	wall_x;

	if (ray->side == 0)
		wall_x = game->player->pos_y + ray->perp_wall_dist * ray->ray_dir_y;
	else
		wall_x = game->player->pos_x + ray->perp_wall_dist * ray->ray_dir_x;
	return (wall_x - floor(wall_x));
}

static int	calculate_tex_x(t_ray *ray, double wall_x, int tex_width)
{
	int	tex_x;

	tex_x = (int)(wall_x * tex_width);
	if ((ray->side == 0 && ray->ray_dir_x > 0)
		|| (ray->side == 1 && ray->ray_dir_y < 0))
		tex_x = tex_width - tex_x - 1;
	return (tex_x);
}

void	init_draw(t_game *game, t_ray *ray, mlx_texture_t *tex, t_draw *d)
{
	double	wall_x;

	d->line_height = (int)(HEIGHT / ray->perp_wall_dist);
	d->start = -d->line_height / 2 + HEIGHT / 2;
	if (d->start < 0)
		d->start = 0;
	d->end = d->line_height / 2 + HEIGHT / 2;
	if (d->end >= HEIGHT)
		d->end = HEIGHT - 1;
	wall_x = calculate_wall_x(game, ray);
	d->tex_x = calculate_tex_x(ray, wall_x, tex->width);
	d->step = (double)tex->height / d->line_height;
	d->tex_pos = (d->start - HEIGHT / 2 + d->line_height / 2) * d->step;
}
