/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmolina <<hmolina@student.42.fr>>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 18:23:26 by hmolina           #+#    #+#             */
/*   Updated: 2025/08/06 23:32:42 by hmolina          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	close_handler(t_game *g)
{
	return (close_game(g));
}

int	close_game(t_game *g)
{
	if (g->_0)
		mlx_destroy_image(g->mlx, g->_0);
	if (g->_1)
		mlx_destroy_image(g->mlx, g->_1);
	if (g->_p)
		mlx_destroy_image(g->mlx, g->_p);
	if (g->_c)
		mlx_destroy_image(g->mlx, g->_c);
	if (g->_e)
		mlx_destroy_image(g->mlx, g->_e);
	if (g->win)
		mlx_destroy_window(g->mlx, g->win);
	if (g->mlx)
		mlx_destroy_display(g->mlx);
	if (g->mlx)
		free(g->mlx);
	free_map(g->map);
	exit(0);
}

void	handle_coin(t_game *g)
{
	ft_printf(" Coins collected: %i/%i\n", g->coined, g->t_coin);
}

/*
	=== ENTRADA Y CONTROL ===

int close_game(t_game *g)
-  Qué hace: Limpia recursos y cierra el juego
-  Comportamiento: Destruye imágenes, ventana, display, libera memoria y sale

int close_handler(t_game *g)
-  Qué hace: Wrapper para el cierre del juego
-  Comportamiento: Simplemente llama a close_game

void handle_coin(t_game *g)
-  Qué hace: Muestra mensaje cuando se recoge una moneda
-  Comportamiento: Printf con contador de monedas
*/