/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manuelfe <manuelfe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/13 18:59:25 by manuelfe          #+#    #+#             */
/*   Updated: 2026/02/13 18:59:26 by manuelfe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_cpy_map(char **cpy)
{
	int		i;

	i = 0;
	while (cpy[i])
	{
		if (cpy[i])
			free(cpy[i]);
		i++;
	}
	if (cpy)
		free(cpy);
}

static void	clean_texture(t_texture *texture)
{
	if (texture)
	{
		if (texture->north)
			free(texture->north);
		if (texture->south)
			free(texture->south);
		if (texture->west)
			free(texture->west);
		if (texture->east)
			free(texture->east);
		if (texture->north_tex)
			mlx_delete_texture(texture->north_tex);
		if (texture->south_tex)
			mlx_delete_texture(texture->south_tex);
		if (texture->west_tex)
			mlx_delete_texture(texture->west_tex);
		if (texture->east_tex)
			mlx_delete_texture(texture->east_tex);
		free(texture);
	}
}

static void	clean_map(t_map *map)
{
	if (map)
	{
		free(map->init_position);
		if (map->map)
		{
			free_cpy_map(map->map);
		}
		free(map);
	}
}

void	ft_close_mlx(void *param)
{
	t_game	*game;

	game = (t_game *)param;
	mlx_close_window(game->mlx);
}

void	clean_game(t_game *game)
{
	if (game)
	{
		if (game->texture)
			clean_texture(game->texture);
		if (game->ceiling)
			free(game->ceiling);
		if (game->floor)
			free(game->floor);
		if (game->list)
			ft_free_list(game->list);
		if (game->map)
			clean_map(game->map);
		if (game->player)
			free(game->player);
		if (game->mlx)
		{
			if (game->img)
				mlx_delete_image(game->mlx, game->img);
			if (game->img_3d)
				mlx_delete_image(game->mlx, game->img_3d);
			mlx_terminate(game->mlx);
		}
	}
	free(game);
}
