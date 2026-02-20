/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manuelfe <manuelfe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/13 18:58:07 by manuelfe          #+#    #+#             */
/*   Updated: 2026/02/13 18:58:08 by manuelfe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	is_color(char *line)
{
	char	**tokens;
	int		res;
	int		num_tok;

	tokens = ft_split(line, ' ');
	num_tok = num_tokens(tokens);
	res = 0;
	if (num_tok == 2)
	{
		if (!tokens[0] || ft_strlen(tokens[0]) != 1)
			res = 1;
		else if (ft_strncmp(tokens[0], "F", ft_strlen(tokens[0])) == 0
			|| ft_strncmp(tokens[0], "C", ft_strlen(tokens[0])) == 0)
			res = 0;
		else
			res = 1;
	}
	else
		res = 1;
	free_tokens(tokens);
	return (res);
}

int	save_color(char *line, t_game *game, int *cf)
{
	char	**tokens;
	int		res;

	tokens = ft_split(line, ' ');
	res = 0;
	if (ft_strncmp(tokens[0], "F", ft_strlen(tokens[0])) == 0
		&& game->floor->b == -1)
		res = parse_floor_color(tokens[1], game);
	else if (ft_strncmp(tokens[0], "C", ft_strlen(tokens[0])) == 0
		&& game->ceiling->b == -1)
		res = parse_ceiling_color(tokens[1], game);
	else if (game->floor->b != -1 || game->ceiling->b != -1)
	{
		res = 1;
		ft_printf("Error\nColor duplicado\n");
	}
	else
		res = 1;
	free_tokens(tokens);
	(*cf)++;
	if (res != 0)
		game->error = 1;
	return (res);
}

static int	parse_rgb_value(char *str)
{
	int	value;

	if (is_valid_number(str) == -1)
		return (-1);
	value = ft_atoi(str);
	if (value < 0 || value > 255)
		return (-1);
	return (value);
}

int	parse_floor_color(char *color, t_game *game)
{
	char	**tk_rgb;

	tk_rgb = ft_split(color, ',');
	if (num_tokens(tk_rgb) != 3)
	{
		free_tokens(tk_rgb);
		ft_printf("Error\nFloor color invalid: format incorrect\n");
		return (-1);
	}
	game->floor->r = parse_rgb_value(tk_rgb[0]);
	game->floor->g = parse_rgb_value(tk_rgb[1]);
	game->floor->b = parse_rgb_value(tk_rgb[2]);
	free_tokens(tk_rgb);
	if (game->floor->r == -1 || game->floor->g == -1 || game->floor->b == -1)
	{
		ft_printf("Error\nFloor color invalid: out of range value\n");
		return (-1);
	}
	return (0);
}

int	parse_ceiling_color(char *line, t_game *game)
{
	char	**tk_rgb;

	tk_rgb = ft_split(line, ',');
	if (num_tokens(tk_rgb) != 3)
	{
		free_tokens(tk_rgb);
		ft_printf("Error\nCeiling color invalid: format incorrect\n");
		return (-1);
	}
	game->ceiling->r = parse_rgb_value(tk_rgb[0]);
	game->ceiling->g = parse_rgb_value(tk_rgb[1]);
	game->ceiling->b = parse_rgb_value(tk_rgb[2]);
	free_tokens(tk_rgb);
	if (game->ceiling->r == -1 || game->ceiling->g == -1
		|| game->ceiling->b == -1)
	{
		ft_printf("Error\nCeiling color invalid: out of range value\n");
		return (-1);
	}
	return (0);
}
