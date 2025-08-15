/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmolina <<hmolina@student.42.fr>>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 19:41:19 by hmolina           #+#    #+#             */
/*   Updated: 2025/07/31 20:42:32 by hmolina          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**asignement_n_read_lines(int fd)
{
	char	**map;
	char	*line;
	int		i;

	map = malloc(sizeof(char *) * 100);
	if (!map)
		return (NULL);
	i = 0;
	line = get_next_line(fd);
	while (line != NULL)
	{
		if (line && line[ft_strlen(line) - 1] == '\n')
			line[ft_strlen(line) - 1] = '\0';
		map[i] = line;
		i++;
		if (i >= 99)
			break ;
		line = get_next_line(fd);
	}
	map[i] = NULL;
	return (map);
}

char	**read_map(char *filename)
{
	char	**map;
	int		fd;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
	{
		perror("Error, read failure");
		return (NULL);
	}
	map = asignement_n_read_lines(fd);
	close(fd);
	if (!map)
	{
		perror("Error allocating memory");
		return (NULL);
	}
	return (map);
}

int	map_loading_error(char **map, char *filename)
{
	if (!map)
	{
		ft_printf("Error\nFailed to load map: %s\n", filename);
		return (0);
	}
	return (1);
}

void	free_map(char **map)
{
	int	i;

	if (!map)
		return ;
	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}

void	calculate_map_size(t_game *g)
{
	int	height;

	height = 0;
	while (g->map[height])
		height++;
	g->map_height = height;
	if (height > 0)
		g->map_width = ft_strlen(g->map[0]);
	else
		g->map_width = 0;
}
