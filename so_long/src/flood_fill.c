/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmolina <<hmolina@student.42.fr>>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 19:45:15 by hmolina           #+#    #+#             */
/*   Updated: 2025/08/07 19:12:41 by hmolina          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**copy_map(char **map, int height)
{
	char	**copy;
	int		i;

	copy = malloc(sizeof(char *) * (height + 1));
	if (!copy)
		return (NULL);
	i = 0;
	while (i < height)
	{
		copy[i] = ft_strdup(map[i]);
		if (!copy[i])
		{
			while (i-- >= 0)
				free(copy[i]);
			free(copy);
			return (NULL);
		}
		i++;
	}
	copy[i] = NULL;
	return (copy);
}

void	flood_fill(char **map, int x, int y, t_game *g)
{
	if (x < 0 || x >= g->map_width || y < 0 || y >= g->map_height)
		return ;
	if (map[y][x] == '1' || map[y][x] == 'V' || map[y][x] == 'E')
		return ;
	map[y][x] = 'V';
	flood_fill(map, x + 1, y, g);
	flood_fill(map, x - 1, y, g);
	flood_fill(map, x, y + 1, g);
	flood_fill(map, x, y - 1, g);
}

void	exit_flood_fill(char **map, int x, int y, t_game *g)
{
	if (x < 0 || x >= g->map_width || y < 0 || y >= g->map_height)
		return ;
	if (map[y][x] == '1' || map[y][x] == 'V')
		return ;
	map[y][x] = 'V';
	exit_flood_fill(map, x + 1, y, g);
	exit_flood_fill(map, x - 1, y, g);
	exit_flood_fill(map, x, y + 1, g);
	exit_flood_fill(map, x, y - 1, g);
}

int	check_player_can_move(t_game *g)
{
	int	move_dir;

	move_dir = 0;
	if (g->p_y > 0 && g->map[g->p_y - 1][g->p_x] != '1')
		move_dir++;
	if (g->p_y < g->map_height - 1 && g->map[g->p_y + 1][g->p_x] != '1')
		move_dir++;
	if (g->p_x > 0 && g->map[g->p_y][g->p_x - 1] != '1')
		move_dir++;
	if (g->p_x < g->map_width - 1 && g->map[g->p_y][g->p_x + 1] != '1')
		move_dir++;
	if (move_dir == 0)
		return (ft_printf("Error\nPlayer cannot move\n"), 0);
	return (1);
}

/*
	=== ALGORITMO FLOOD FILL ===

char **copy_map(char **map, int height)
-  Qué hace: Crea una copia del mapa para testing
-  Comportamiento: Duplica cada string usando ft_strdup

void flood_fill(char **map, int x, int y, t_game *g)
-  Qué hace: Algoritmo recursivo que marca celdas accesibles
-  Comportamiento: Marca con 'V' (visitado) todas las celdas alcanzables, se detiene en paredes y salidas

void exit_flood_fill(char **map, int x, int y, t_game *g)
-  Qué hace: Versión específica del flood fill para verificar acceso a la salida
-  Comportamiento: Similar al anterior pero permite pasar por la salida

int check_player_can_move(t_game *g)
-  Qué hace: Verifica que el jugador no esté completamente bloqueado
-  Comportamiento: Cuenta direcciones válidas desde la posición inicial del jugador
*/