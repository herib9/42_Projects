/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmolina <<hmolina@student.42.fr>>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 01:37:45 by hmolina           #+#    #+#             */
/*   Updated: 2025/08/01 00:05:06 by hmolina          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int ac, char **av)
{
	t_game	game;

	if (ac != 2)
		return (ft_printf("Error\nUse: ./so_long/maps <map.ber>\n"), 1);
	ft_memset(&game, 0, sizeof(t_game));
	game.map = read_map(av[1]);
	if (!game.map)
		return (1);
	if (!validate_map(game.map))
		return (free_map(game.map), 1);
	calculate_map_size(&game);
	if (check_walls(&game))
		return (free_map(game.map), 1);
	check_elements(&game);
	if (game.player != 1 || game.exit != 1 || game.coin < 1)
		return (ft_printf("Error\nInvalid map elements\n"),
			free_map(game.map), 1);
	find_player_position(&game);
	find_exit_position(&game);
	count_coin(&game);
	if (!init_graphics(&game))
		return (free_map(game.map), 1);
	mlx_key_hook(game.win, keymap, &game);
	mlx_hook(game.win, 17, 0, close_game, &game);
	render_map(&game);
	mlx_loop(game.mlx);
	return (0);
}

	//start_game(&game);