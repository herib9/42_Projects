/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmolina <<hmolina@student.42.fr>>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 21:59:51 by hmolina           #+#    #+#             */
/*   Updated: 2025/08/07 01:22:06 by hmolina          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	load_sprites(t_game *g)
{
	int	width;
	int	height;

	g->_0 = mlx_xpm_file_to_image(g->mlx, "img/0.xpm", &width, &height);
	g->_1 = mlx_xpm_file_to_image(g->mlx, "img/1.xpm", &width, &height);
	g->_c = mlx_xpm_file_to_image(g->mlx, "img/c.xpm", &width, &height);
	g->_e = mlx_xpm_file_to_image(g->mlx, "img/e.xpm", &width, &height);
	g->_p = mlx_xpm_file_to_image(g->mlx, "img/p.xpm", &width, &height);
	if (!g->_0 || !g->_1 || !g->_c || !g->_e || !g->_p)
		return (ft_printf("Error\nFailed to load images\n"), 0);
	return (1);
}

int	init_graphics(t_game *g)
{
	g->mlx = mlx_init();
	if (!g->mlx)
		return (ft_printf("Error\nFailed to initialize MLX\n"), 0);
	g->win = mlx_new_window(g->mlx, g->map_width * TILE_SIZE,
			g->map_height * TILE_SIZE, "So Long");
	if (!g->win)
		return (ft_printf("Error\nFailed to create window\n"), 0);
	if (!load_sprites(g))
		return (0);
	return (1);
}

void	render_map(t_game *g)
{
	int	x;
	int	y;

	mlx_clear_window(g->mlx, g->win);
	y = 0;
	while (y < g->map_height)
	{
		x = 0;
		while (x < g->map_width)
		{
			if (g->map[y][x] == WALL)
				mlx_put_image_to_window(g->mlx, g->win, g->_1, x * 64, y * 64);
			else if (g->map[y][x] == EMPTY)
				mlx_put_image_to_window(g->mlx, g->win, g->_0, x * 64, y * 64);
			else if (g->map[y][x] == COIN)
				render_coin(g, x, y);
			else if (g->map[y][x] == EXIT)
				render_exit(g, x, y);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(g->mlx, g->win, g->_p, g->p_x * 64, g->p_y * 64);
}

void	render_coin(t_game *g, int x, int y)
{
	mlx_put_image_to_window(g->mlx, g->win, g->_0, x * 64, y * 64);
	mlx_put_image_to_window(g->mlx, g->win, g->_c, x * 64, y * 64);
}

void	render_exit(t_game *g, int x, int y)
{
	mlx_put_image_to_window(g->mlx, g->win, g->_0, x * 64, y * 64);
	mlx_put_image_to_window(g->mlx, g->win, g->_e, x * 64, y * 64);
}
