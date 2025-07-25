/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmolina <<hmolina@student.42.fr>>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 20:18:54 by hmolina           #+#    #+#             */
/*   Updated: 2025/07/24 19:36:14 by hmolina          ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#ifndef SO_LONG_H
# define SO_LONG_H

// librerias
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include "libft.h"
# include "../libs/minilibx/mlx.h"
# include <X11/keysym.h>
# include <X11/X.h>

// constantes del juego
# define TILE_SIZE 64

// estructura del juego
typedef struct s_game
{
	int	total_collectibles;
}	t_game;


// elementos del mapa
# define EMPTY '0'
# define WALL '1'
# define COLLECTIBLE 'C'
# define EXIT 'E'
# define PLAYER 'P'

// codigos de teclas
# define KEY_W		119
# define KEY_S		115
# define KEY_A		97
# define KEY_D		100
# define KEY_UP		65362
# define KEY_DOWN	65364
# define KEY_LEFT	65361
# define KEY_RIGHT	65363
# define KEY_ESC	65307












