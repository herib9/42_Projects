/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manuelfe <manuelfe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/13 18:57:48 by manuelfe          #+#    #+#             */
/*   Updated: 2026/02/13 18:57:50 by manuelfe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	key_loop(void *param)
{
	t_game	*game;
	int		moved;

	game = (t_game *)param;
	moved = 1;
	if (mlx_is_key_down(game->mlx, MLX_KEY_ESCAPE))
		ft_close_mlx(game);
	if (mlx_is_key_down(game->mlx, MLX_KEY_W))
		up_move(game);
	if (mlx_is_key_down(game->mlx, MLX_KEY_S))
		down_move(game);
	if (mlx_is_key_down(game->mlx, MLX_KEY_A))
		left_move(game);
	if (mlx_is_key_down(game->mlx, MLX_KEY_D))
		right_move(game);
	if (mlx_is_key_down(game->mlx, MLX_KEY_LEFT))
		look_player(game, -1);
	if (mlx_is_key_down(game->mlx, MLX_KEY_RIGHT))
		look_player(game, 1);
	if (moved)
		render_frame(game);
}

void	update_direction_line(t_game *game)
{
	int	start_x;
	int	start_y;
	int	end_x;
	int	end_y;

	start_x = game->player->pos_x * TILE_SIZE + 4;
	start_y = game->player->pos_y * TILE_SIZE + 4;
	end_x = start_x + (game->player->dir_x * 100);
	end_y = start_y + (game->player->dir_y * 100);
	draw_line(game, end_x, end_y, 0xFF0000FF);
}

void	look_player(t_game *game, int dir)
{
	double	old_dir_x;
	double	old_plane_x;
	double	speed;

	old_dir_x = game->player->dir_x;
	speed = game->player->rot_speed * dir;
	game->player->dir_x = game->player->dir_x * cos(speed)
		- game->player->dir_y * sin(speed);
	game->player->dir_y = old_dir_x * sin(speed)
		+ game->player->dir_y * cos(speed);
	old_plane_x = game->player->plane_x;
	game->player->plane_x = game->player->plane_x * cos(speed)
		- game->player->plane_y * sin(speed);
	game->player->plane_y = old_plane_x * sin(speed)
		+ game->player->plane_y * cos(speed);
}
