/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmolina <<hmolina@student.42.fr>>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 19:41:19 by hmolina           #+#    #+#             */
/*   Updated: 2025/07/25 00:24:17 by hmolina          ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "so_long.h"

char	**read_map(char *filename)
{
	char	**map;
	char	*line;
	int	fd;
	int	i;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
	{
		perror("Error, read failure");
		return (NULL);
	}
	map = malloc(sizeof(char*) * 100);
	if (!map)
	{
		close(fd);
		return (NULL);
	}
	i = 0;
	while ((line = get_next_line(fd)) != NULL)
	{
		if (line && line[ft_strlen(line) - 1] == '\n')
			line[ft_strlen(line) - 1] = '\0';
		map[i] = line;
		i++;
		if (i >= 99)
			break;
	}
	map[i] = NULL;
	close(fd);
	return (map);
}

void	error(char **map)
{
	int	y;
	int	x;
	
	y = 0;
	while(map[y] != 0)
	{
		x = 0;
	}
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

void	calculate_map_size(t_game *game)
{

}