/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manuelfe <manuelfe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/13 18:58:14 by manuelfe          #+#    #+#             */
/*   Updated: 2026/02/13 18:58:17 by manuelfe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	parse_single_texture(char *line)
{
	int	len;
	int	fd;

	len = ft_strlen(line);
	if (len < 4)
	{
		ft_printf("Error\nTexture file invalid");
		return (-1);
	}
	if (ft_strncmp(line + ft_strlen(line) - 4, ".png", 4) != 0)
	{
		ft_printf("Error\nTexture is not .png extension\n");
		return (-1);
	}
	fd = open(line, O_RDONLY);
	if (fd == -1)
	{
		ft_printf("Error\nTexture file not found\n");
		return (-1);
	}
	close(fd);
	return (0);
}

int	is_texture(char *line)
{
	char	**tokens;
	int		res;
	int		num_tok;

	tokens = ft_split(line, ' ');
	num_tok = num_tokens(tokens);
	res = 0;
	if (num_tok == 2)
	{
		if (!tokens[0] || ft_strlen(tokens[0]) != 2)
			res = 1;
		else if (ft_strncmp(tokens[0], "NO", ft_strlen(tokens[0])) == 0
			|| ft_strncmp(tokens[0], "SO", ft_strlen(tokens[0])) == 0
			|| ft_strncmp(tokens[0], "WE", ft_strlen(tokens[0])) == 0
			|| ft_strncmp(tokens[0], "EA", ft_strlen(tokens[0])) == 0)
			res = 0;
		else
			res = 1;
	}
	else
		res = 1;
	free_tokens(tokens);
	return (res);
}

int	save_texture(char *line, t_game *game, int *cf)
{
	char	**tokens;
	int		res;

	tokens = ft_split(line, ' ');
	res = 0;
	if (parse_single_texture(tokens[1]) != 0)
		res = 1;
	if (ft_strncmp(tokens[0], "NO", 2) == 0 && game->texture->north == NULL)
		game->texture->north = ft_strdup(tokens[1]);
	else if (ft_strncmp(tokens[0], "SO", 2) == 0
		&& game->texture->south == NULL)
		game->texture->south = ft_strdup(tokens[1]);
	else if (ft_strncmp(tokens[0], "WE", 2) == 0 && game->texture->west == NULL)
		game->texture->west = ft_strdup(tokens[1]);
	else if (ft_strncmp(tokens[0], "EA", 2) == 0 && game->texture->east == NULL)
		game->texture->east = ft_strdup(tokens[1]);
	else
	{
		ft_printf("Error\nTextura duplicada\n");
		res = 1;
	}
	if (res == 1)
		game->error = 1;
	(*cf)++;
	return (free_tokens(tokens), res);
}
