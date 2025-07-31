/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmolina <<hmolina@student.42.fr>>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 19:07:28 by hmolina           #+#    #+#             */
/*   Updated: 2025/07/31 23:15:44 by hmolina          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	keymap(int keycode, t_game *g)
{
	if (keycode == KEY_ESC)
		close_handler(g);
	else if (keycode == KEY_S || keycode == KEY_DOWN)
		move_player(g, 0, -1);
	else if (keycode == KEY_D || keycode == KEY_RIGHT)
		move_player(g, 1, 0);
	else if (keycode == KEY_A || keycode == KEY_LEFT)
		move_player(g, -1, 0);
	else if (keycode == KEY_W || keycode == KEY_UP)
		move_player(g, 0, -1);
	render_map(g);
	return (0);
}

void	move_player(t_game *g, int dx, int dy)
{
	int	n_x;
	int	n_y;

	n_x = g->p_x + dx;
	n_y = g->p_y + dy;
	if (n_x < 0 || n_x >= g->map_width || n_y < 0 || n_y >= g->map_height)
		return ;
	if (g->map[n_y][n_x] == WALL)
		return ;
	if (g->map[n_y][n_x] == COIN)
	{
		g->map[n_y][n_x] = EMPTY;
		g->coined++;
		handle_coin(g);
	}
	if (g->map[n_y][n_x] == EXIT && g->coined == g->t_coin)
	{
		ft_printf("YOU WIN! movements: %i\n", g->moves + 1);
		close_game(g);
		return ;
	}
	g->p_x = n_x;
	g->p_y = n_y;
	g->moves++;
}
