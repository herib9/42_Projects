/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmolina <<hmolina@student.42.fr>>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 01:37:45 by hmolina           #+#    #+#             */
/*   Updated: 2025/08/15 22:13:20 by hmolina          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	st_val_map(t_game *g, char *filename)
{
	if (!check_map_extension(filename))
		return (0);
	g->map = read_map(filename);
	if (!g->map)
		return (0);
	if (!validate_map(g->map))
		return (free_map(g->map), 0);
	calculate_map_size(g);
	if (check_walls(g))
		return (free_map(g->map), 0);
	check_elements(g);
	if (g->player != 1 || g->exit != 1 || g->coin < 1)
	{
		ft_printf("Error\nInvalid map elements\n");
		free_map(g->map);
		return (0);
	}
	if (!check_valid_chars(g))
		return (free_map(g->map), 0);
	return (1);
}

int	nd_val_map(t_game *g)
{
	find_player_position(g);
	find_exit_position(g);
	count_coin(g);
	if (!check_player_can_move(g))
		return (free_map(g->map), 0);
	if (!check_coins_accesibility(g))
		return (free_map(g->map), 0);
	if (!check_exit_accesibility(g))
		return (free_map(g->map), 0);
	return (1);
}

int	init_game(t_game *g)
{
	if (!init_graphics(g))
		return (free_map(g->map), 0);
	mlx_key_hook(g->win, keymap, g);
	mlx_hook(g->win, 17, 0, close_game, g);
	render_map(g);
	ft_printf("So_Long is comming!\n");
	update_stats_display(g);
	mlx_loop(g->mlx);
	return (1);
}

int	main(int ac, char **av)
{
	t_game	game;

	if (ac != 2)
		return (ft_printf("Error\nUse: ./so_long/maps <map.ber>\n"), 1);
	ft_memset(&game, 0, sizeof(t_game));
	if (!st_val_map(&game, av[1]))
		return (1);
	if (!nd_val_map(&game))
		return (1);
	if (!init_game(&game))
		return (1);
	return (0);
}
