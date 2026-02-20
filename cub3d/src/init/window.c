/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manuelfe <manuelfe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/13 18:57:39 by manuelfe          #+#    #+#             */
/*   Updated: 2026/02/13 18:57:40 by manuelfe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	load_textures(t_game *game)
{
	game->texture->north_tex = mlx_load_png(game->texture->north);
	if (!game->texture->north_tex)
	{
		ft_printf("Error\nDo not load north texture", game->texture->north);
		return (-1);
	}
	game->texture->south_tex = mlx_load_png(game->texture->south);
	if (!game->texture->south_tex)
	{
		ft_printf("Error\nDo not load south texture", game->texture->south);
		return (-1);
	}
	game->texture->west_tex = mlx_load_png(game->texture->west);
	if (!game->texture->west_tex)
	{
		ft_printf("Error\nDo not load west texture", game->texture->west);
		return (-1);
	}
	game->texture->east_tex = mlx_load_png(game->texture->east);
	if (!game->texture->east_tex)
	{
		ft_printf("Error\nDo not load east texture", game->texture->east);
		return (-1);
	}
	return (0);
}

int	init_window(t_game *game)
{
	game->mlx = mlx_init(game->win_w, game->win_h, "cub3d", true);
	if (!game->mlx)
	{
		ft_printf("Error\nFailed to initialize MLX42\n");
		return (-1);
	}
	game->img = mlx_new_image(game->mlx, game->win_w, game->win_h);
	if (!game->img)
	{
		ft_printf("Error\nFailed to load image\n");
		mlx_terminate(game->mlx);
		return (-1);
	}
	if (mlx_image_to_window(game->mlx, game->img, 0, 0) == -1)
	{
		ft_printf("Error\nFailed to load image at window\n");
		mlx_delete_image(game->mlx, game->img);
		mlx_terminate(game->mlx);
		return (-1);
	}
	mlx_loop_hook(game->mlx, game_loop, game);
	return (0);
}

void	game_loop(void *param)
{
	t_game	*game;

	game = (t_game *)param;
	key_loop(game);
}
