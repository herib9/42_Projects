/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manuelfe <manuelfe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/13 18:59:43 by manuelfe          #+#    #+#             */
/*   Updated: 2026/02/13 18:59:45 by manuelfe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	flood_fill(char **map, t_pos pos, int h, int w)
{
	if (pos.x < 0 || pos.x >= w || pos.y < 0 || pos.y >= h)
		return (1);
	if (map[pos.y][pos.x] == ' ')
		return (1);
	if (map[pos.y][pos.x] == '1' || map[pos.y][pos.x] == 'V')
		return (0);
	map[pos.y][pos.x] = 'V';
	if (flood_fill(map, (t_pos){pos.x + 1, pos.y}, h, w) == 1
		|| flood_fill(map, (t_pos){pos.x - 1, pos.y}, h, w) == 1
		|| flood_fill(map, (t_pos){pos.x, pos.y + 1}, h, w) == 1
		|| flood_fill(map, (t_pos){pos.x, pos.y - 1}, h, w) == 1)
		return (1);
	return (0);
}
