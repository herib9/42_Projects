/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manuelfe <manuelfe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/13 18:57:07 by manuelfe          #+#    #+#             */
/*   Updated: 2026/02/13 18:57:09 by manuelfe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	init_mlx(t_game *game)
{
	mlx_set_setting(MLX_STRETCH_IMAGE, true);
	game->mlx = mlx_init(WIDTH, HEIGHT, "cub3d", true);
	if (!game->mlx)
		return (-1);
	game->img = mlx_new_image(game->mlx, WIDTH, HEIGHT);
	if (!game->img || (mlx_image_to_window(game->mlx, game->img, 0, 0) < 0))
	{
		mlx_terminate(game->mlx);
		game->mlx = NULL;
		return (-1);
	}
	return (0);
}

static void	ft_game(t_game *game)
{
	init_player(game);
	mlx_close_hook(game->mlx, &ft_close_mlx, game);
	mlx_loop_hook(game->mlx, &key_loop, game);
	init_minimap(game);
	init_imag_3d(game);
	render_frame(game);
	print_back_ground(game);
	draw_2d_map(game);
	draw_player(game);
	draw_direction_line(game);
	mlx_loop(game->mlx);
	cast_rays_3d(game);
}

static int	ft_validate_arg_file(int ac, char **av)
{
	int	fd;

	fd = -1;
	if (ac != 2)
		fd = -1;
	fd = validate_file(av[1]);
	return (fd);
}

int	main(int ac, char **av)
{
	int		valido;
	t_game	*game;
	int		fd;

	fd = ft_validate_arg_file(ac, av);
	if (fd >= 0)
	{
		game = init_game();
		valido = save_file(fd, game);
		if (valido == 0 && init_mlx(game) == 0 && load_textures(game) == 0)
			ft_game(game);
		else
		{
			clean_game(game);
			return (-1);
		}
		close(fd);
		clean_game(game);
	}
	else
		return (-1);
	return (0);
}
