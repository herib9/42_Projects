/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_validations.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manuelfe <manuelfe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/13 18:59:50 by manuelfe          #+#    #+#             */
/*   Updated: 2026/02/13 18:59:52 by manuelfe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	validate_file(char *av)
{
	int		fd;

	if (check_file_extension(av) == -1)
	{
		ft_printf("Error\nThe file don't have the correct extension\n");
		return (-1);
	}
	fd = open(av, O_RDONLY);
	if (fd < 0)
	{
		ft_printf("Error\nThe file cannot be opened\n");
		return (-1);
	}
	return (fd);
}

int	is_player_char(char c, t_map *map, t_pos pos, int *player_count)
{
	if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
	{
		if (is_correct_position(map, pos.x, pos.y) == -1)
			return (-1);
		(*player_count)++;
		map->orientation = c;
	}
	return (0);
}

int	is_correct_position(t_map *map, int x, int y)
{
	if (x <= 0 || x >= map->w - 1 || y <= 0 || y >= map->h - 1)
	{
		ft_printf("Error\nThe player are in invalid position\n");
		return (-1);
	}
	if (map->map[y - 1][x] == ' ' || map->map[y + 1][x] == ' ')
	{
		ft_printf("Error\nThe player are in invalid position\n");
		return (-1);
	}
	if (map->map[y][x - 1] == ' ' || map->map[y][x + 1] == ' ')
	{
		ft_printf("Error\nThe player are in invalid position\n");
		return (-1);
	}
	map->init_position->x = x;
	map->init_position->y = y;
	return (0);
}

int	is_char_valid(char c)
{
	if (c != '0' && c != '1' && c != ' ' && c != 'N' && c != 'S'
		&& c != 'E' && c != 'W' && c != '\n')
		return (-1);
	return (0);
}

char	**ft_copy_map(char **map, int h, int w)
{
	int		i;
	char	**new_map;

	new_map = malloc(sizeof(char *) * (h + 1));
	if (!new_map)
		return (NULL);
	i = 0;
	while (i < h)
	{
		new_map[i] = malloc(sizeof(char) * (w + 1));
		if (!new_map[i])
		{
			while (i > 0)
				free(new_map[--i]);
			free(new_map);
			return (NULL);
		}
		ft_strlcpy(new_map[i], map[i], w + 1);
		i++;
	}
	new_map[h] = NULL;
	return (new_map);
}
