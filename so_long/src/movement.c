/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmolina <<hmolina@student.42.fr>>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 19:07:28 by hmolina           #+#    #+#             */
/*   Updated: 2025/08/07 01:26:07 by hmolina          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	keymap(int keycode, t_game *g)
{
	if (keycode == KEY_ESC)
		close_handler(g);
	else if (keycode == KEY_W || keycode == KEY_UP)
		move_player(g, 0, -1);
	else if (keycode == KEY_S || keycode == KEY_DOWN)
		move_player(g, 0, 1);
	else if (keycode == KEY_D || keycode == KEY_RIGHT)
		move_player(g, 1, 0);
	else if (keycode == KEY_A || keycode == KEY_LEFT)
		move_player(g, -1, 0);
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
		ft_printf("\nYOU WIN!\nMovements: %i\n", g->moves + 1);
		close_game(g);
		return ;
	}
	g->p_x = n_x;
	g->p_y = n_y;
	g->moves++;
	update_stats_display(g);
}

void	update_stats_display(t_game *g)
{
	ft_printf("\033[2K\r");
	ft_printf("Movements: %i | Coins: %i/%i", g->moves, g->coined, g->t_coin);
	fflush(stdout);
}

/*
	=== MOVIMIENTO ===

int keymap(int keycode, t_game *g)
-  Qué hace: Maneja todas las teclas presionadas
-  Comportamiento: WASD/flechas para movimiento, ESC para salir, re-renderiza después

void move_player(t_game *g, int dx, int dy)
-  Qué hace: Función principal de movimiento del jugador
-  Comportamiento:
	-  Calcula nueva posición
	-  Verifica límites y paredes
	-  Maneja recolección de monedas
	-  Verifica condición de victoria
	-  Actualiza posición y estadísticas

void update_stats_display(t_game *g)
-  Qué hace: Actualiza la línea de estadísticas en terminal
-  Comportamiento: Usa códigos ANSI para sobrescribir la línea actual
*/