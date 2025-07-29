/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmolina <<hmolina@student.42.fr>>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 18:23:26 by hmolina           #+#    #+#             */
/*   Updated: 2025/07/30 01:43:08 by hmolina          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	keymap(int keycode, t_game *game)
{
	if (keycode == KEY_ESC)
		close_handler(game);
	else if (keycode == KEY_S || keycode == KEY_DOWN)
		move_down(game, 0, -1);
	else if (keycode == KEY_D || keycode == KEY_RIGHT)
		move_right(game, 1, 0);
	else if (keycode == KEY_A || keycode == KEY_LEFT)
		move_left(game, -1, 0);
	else if (keycode == KEY_W || keycode == KEY_UP)
		move_up(game, 0, -1);
	return (0);
	}

int	close_hanler(t_game *game)
{
	
}

int	close_game(t_game *game)
{
	
}

void	handle_collectible(t_game *game)
{
	
}

void	check_win(t_game *game)
{
	
}