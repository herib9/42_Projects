/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manuelfe <manuelfe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/13 18:59:15 by manuelfe          #+#    #+#             */
/*   Updated: 2026/02/13 18:59:16 by manuelfe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	*clean_line(char *line)
{
	return (ft_strtrim(line, " \t\n"));
}

static void	init_struc(t_game *game)
{
	game->texture = ft_calloc(1, sizeof(t_texture));
	game->floor = ft_calloc(1, sizeof(t_color));
	game->floor->r = -1;
	game->floor->g = -1;
	game->floor->b = -1;
	game->ceiling = ft_calloc(1, sizeof(t_color));
	game->ceiling->r = -1;
	game->ceiling->g = -1;
	game->ceiling->b = -1;
	game->list = NULL;
}

static int	save_tex_and_color(char *line, t_game *game, int *cf)
{
	int		error;
	char	*trim;

	trim = clean_line(line);
	error = 0;
	if (is_texture(trim) == 0)
		error = save_texture(trim, game, cf);
	else if (is_color(trim) == 0)
		error = save_color(trim, game, cf);
	else if (is_map(trim) == 0 && (*cf) == 6)
		error = save_map(line, trim, &game->list);
	else if (trim && trim[0] != '\0')
	{
		ft_printf("Error\nConfiguración desconocida o incorrecta\n");
		error = 1;
	}
	if (error != 0)
		game->error = 1;
	free(trim);
	free(line);
	return (error);
}

int	save_file(int fd, t_game *game)
{
	int		error;
	char	*line;
	int		cf;

	error = 0;
	cf = 0;
	line = get_next_line(fd);
	init_struc(game);
	while (line)
	{
		if (error == 0)
			error = save_tex_and_color(line, game, &cf);
		else
			free(line);
		line = get_next_line(fd);
	}
	if (error == 0 && cf == 6 && ft_lstsize(game->list) > 0)
		error = list_to_map(game);
	else if ((game->error == 0) && (cf < 6 || ft_lstsize(game->list) == 0))
	{
		ft_printf("Error\nInsuficientes parametros\n");
		error = 1;
	}
	return (error);
}
