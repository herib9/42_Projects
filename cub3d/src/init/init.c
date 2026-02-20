/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manuelfe <manuelfe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/13 18:57:30 by manuelfe          #+#    #+#             */
/*   Updated: 2026/02/13 18:57:32 by manuelfe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_game	*init_game(void)
{
	t_game	*game;

	game = ft_calloc(sizeof(t_game), 1);
	if (!game)
		return (NULL);
	game->error = 0;
	return (game);
}

static void	ft_asing_dir_player(t_game *game, t_pos pos, double x, double y)
{
	game->player->dir_x = pos.x;
	game->player->dir_y = pos.y;
	game->player->plane_x = x;
	game->player->plane_y = y;
}

void	init_player(t_game *game)
{
	game->player = ft_calloc(sizeof(t_player), 1);
	game->player->pos_x = game->map->init_position->x + 0.5;
	game->player->pos_y = game->map->init_position->y + 0.5;
	game->player->move_speed = 0.1;
	game->player->rot_speed = 0.05;
	if (game->map->orientation == 'N')
		ft_asing_dir_player(game, (t_pos){0, -1}, 0.66, 0);
	else if (game->map->orientation == 'S')
		ft_asing_dir_player(game, (t_pos){0, 1}, -0.66, 0);
	else if (game->map->orientation == 'E')
		ft_asing_dir_player(game, (t_pos){1, 0}, 0, 0.66);
	else if (game->map->orientation == 'W')
		ft_asing_dir_player(game, (t_pos){-1, 0}, 0, -0.66);
}

void	init_minimap(t_game *game)
{
	int	pos_x;
	int	pos_y;

	if (game->img)
		mlx_delete_image(game->mlx, game->img);
	game->img = mlx_new_image(game->mlx, MINI_MAP_SIZE, MINI_MAP_SIZE);
	pos_x = WIDTH - MINI_MAP_SIZE - MARGIN_MINIMAP;
	pos_y = HEIGHT - MINI_MAP_SIZE - MARGIN_MINIMAP;
	mlx_image_to_window(game->mlx, game->img, pos_x, pos_y);
	mlx_set_instance_depth(&game->img->instances[0], 1);
}

void	init_imag_3d(t_game *game)
{
	game->img_3d = mlx_new_image(game->mlx, WIDTH, HEIGHT);
	mlx_image_to_window(game->mlx, game->img_3d, 0, 0);
	mlx_set_instance_depth(&game->img_3d->instances[0], 0);
}
