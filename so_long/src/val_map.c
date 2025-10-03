/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   val_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmolina <<hmolina@student.42.fr>>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 18:23:39 by hmolina           #+#    #+#             */
/*   Updated: 2025/08/15 22:14:38 by hmolina          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	count_map_height(char **map)
{
	int	height;

	height = 0;
	while (map[height] != NULL)
		height++;
	return (height);
}

int	is_rectangular(char **map, int height, int width)
{
	int	i;
	int	actual_width;

	i = 0;
	while (i < height)
	{
		actual_width = ft_strlen(map[i]);
		if (actual_width != width)
			return (0);
		i++;
	}
	return (1);
}

int	validate_map(char **map)
{
	int	height;
	int	width;

	if (!map)
		return (ft_printf("Error\nMap is empty\n"), 0);
	height = count_map_height(map);
	if (height == 0)
		return (ft_printf("Error\nMap has no lines\n"), 0);
	width = ft_strlen(map[0]);
	if (width == 0)
		return (ft_printf("Error\nMap width is zero\n"), 0);
	if (!is_rectangular(map, height, width))
		return (ft_printf("Error\nMap is not rectangular\n"), 0);
	return (1);
}

int	check_map_extension(char *filename)
{
	int	len;

	if (!filename)
		return (0);
	len = ft_strlen(filename);
	if (len < 5)
		return (0);
	if (ft_strncmp(filename + len - 4, ".ber", 4) != 0)
	{
		ft_printf("Error\nThe file don't have the .ber extension\n");
		return (0);
	}
	return (1);
}

/*
	=== VALIDACIONES AVANZADAS ===

int validate_map(char **map)
-  Qué hace: Validación estructural del mapa
-  Comportamiento: Verifica que no esté vacío, tenga dimensiones válidas y sea rectangular

int is_rectangular(char **map, int height, int width)
-  Qué hace: Verifica que todas las filas tengan la misma longitud
-  Comportamiento: Compara strlen de cada fila con el ancho esperado

int count_map_height(char **map)
-  Qué hace: Cuenta el número de filas del mapa
-  Comportamiento: Itera hasta encontrar NULL

int check_map_extension(char *filename)
-  Qué hace: Verifica que el archivo tenga extensión .ber
-  Comportamiento: Usa strncmp para comparar los últimos 4 caracteres
*/