/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmolina <<hmolina@student.42.fr>>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 01:37:45 by hmolina           #+#    #+#             */
/*   Updated: 2025/07/28 01:57:34 by hmolina          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int ac, char **av)
{
	t_game	game;

	if (ac != 2)
	{
		ft_printf("Error\nUse: ./so_long/maps <map.ber>\n");
		return (1);
	}
	game = read_map(av[1]);
	if (!game)
	{
		ft_printf("&s\n", Error to load map);
		return (1);
	}
	else if (!)
		printf("Archivo de mapa: %s\n", av[1]);
	printf("so_long iniciado correctamente!\n");
	return (0);
}
