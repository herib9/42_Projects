/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manuelfe <manuelfe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/13 18:57:55 by manuelfe          #+#    #+#             */
/*   Updated: 2026/02/13 18:57:57 by manuelfe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	up_move(t_game *game)
{
	double	new_x;
	double	new_y;
	double	margin;

	new_x = game->player->pos_x + game->player->dir_x
		* game->player->move_speed;
	if (game->player->dir_x > 0)
		margin = new_x + 0.2;
	else
		margin = new_x + (-0.2);
	if (game->map->map[(int)game->player->pos_y][(int)(margin)] != '1')
		game->player->pos_x = new_x;
	new_y = game->player->pos_y + game->player->dir_y
		* game->player->move_speed;
	if (game->player->dir_y > 0)
		margin = new_y + 0.2;
	else
		margin = new_y + (-0.2);
	if (game->map->map[(int)(margin)][(int)game->player->pos_x] != '1')
		game->player->pos_y = new_y;
}

void	down_move(t_game *game)
{
	double	new_x;
	double	new_y;
	double	margin;

	new_x = game->player->pos_x - game->player->dir_x
		* game->player->move_speed;
	if (game->player->dir_x > 0)
		margin = new_x + (-0.2);
	else
		margin = new_x + 0.2;
	if (game->map->map[(int)game->player->pos_y][(int)(margin)] != '1')
		game->player->pos_x = new_x;
	new_y = game->player->pos_y - game->player->dir_y
		* game->player->move_speed;
	if (game->player->dir_y > 0)
		margin = new_y + (-0.2);
	else
		margin = new_y + 0.2;
	if (game->map->map[(int)(margin)][(int)game->player->pos_x] != '1')
		game->player->pos_y = new_y;
}

void	left_move(t_game *game)
{
	double	new_x;
	double	new_y;
	double	margin;

	new_x = game->player->pos_x - game->player->plane_x
		* game->player->move_speed;
	if (game->player->plane_x > 0)
		margin = new_x - 0.2;
	else
		margin = new_x + 0.2;
	if (game->map->map[(int)game->player->pos_y][(int)(margin)] != '1')
		game->player->pos_x = new_x;
	new_y = game->player->pos_y - game->player->plane_y
		* game->player->move_speed;
	if (game->player->plane_y > 0)
		margin = new_y - 0.2;
	else
		margin = new_y + 0.2;
	if (game->map->map[(int)(margin)][(int)game->player->pos_x] != '1')
		game->player->pos_y = new_y;
}

void	right_move(t_game *game)
{
	double	new_x;
	double	new_y;
	double	margin;

	new_x = game->player->pos_x + game->player->plane_x
		* game->player->move_speed;
	if (game->player->plane_x > 0)
		margin = new_x + 0.2;
	else
		margin = new_x + (-0.2);
	if (game->map->map[(int)game->player->pos_y][(int)(margin)] != '1')
		game->player->pos_x = new_x;
	new_y = game->player->pos_y + game->player->plane_y
		* game->player->move_speed;
	if (game->player->plane_y > 0)
		margin = new_y + 0.2;
	else
		margin = new_y - 0.2;
	if (game->map->map[(int)(margin)][(int)game->player->pos_x] != '1')
		game->player->pos_y = new_y;
}

void	render_frame(t_game *game)
{
	ft_memset(game->img->pixels, 0,
		game->img->width * game->img->height * sizeof(int32_t));
	ft_memset(game->img_3d->pixels, 0,
		game->img_3d->width * game->img_3d->height * sizeof(int32_t));
	print_back_ground(game);
	cast_rays_3d(game);
	draw_2d_map(game);
	draw_player(game);
	draw_direction_line(game);
}
