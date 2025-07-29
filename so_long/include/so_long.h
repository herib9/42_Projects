/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmolina <<hmolina@student.42.fr>>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 20:18:54 by hmolina           #+#    #+#             */
/*   Updated: 2025/07/29 22:53:11 by hmolina          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

// == LIBRERIES ==
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include "libft.h"
# include "../libs/minilibx/mlx.h"
# include <X11/keysym.h>
# include <X11/X.h>

// == GAME CONSTANTS ==
# define TILE_SIZE 64

// == GAME STRUCTURES ==
typedef struct s_game
{
	// == GRAPHICS CONNECTION ==
	void	*mlx;
	void	*win;

	// == SPRITES ==
	void	*img_wall;
	void	*img_floor;
	void	*img_player;
	void	*img_collectible;
	void	*img_exit;

	// == MAP ==
	char	**map;
	int		map_width;
	int		map_height;

	// == PLAYER POSITION ==
	int		player_x;
	int		player_y;

	// == EXIT POSITION ==
	int		exit_x;
	int		exit_y;

	// == STATS ==
	int		moves;
	int		collected;
	int		total_collectibles;

	// == ELEMENTS ==
	int		player;
	int		exit;
	int		collectible;
	

}	t_game;

// == MAP ELEMENTS ==
# define EMPTY '0'
# define WALL '1'
# define COLLECTIBLE 'C'
# define EXIT 'E'
# define PLAYER 'P'

// == KEY CODES ==
# define KEY_W		119
# define KEY_S		115
# define KEY_A		97
# define KEY_D		100
# define KEY_UP		65362
# define KEY_DOWN	65364
# define KEY_LEFT	65361
# define KEY_RIGHT	65363
# define KEY_ESC	65307

int		main(int ac, char **av);

// == INPUT FUNCTIONS ==
int		keymap(int keycode, t_game *game);
int		close_game(t_game *game);
void	handle_collectible(t_game *game);
void	check_win(t_game *game);

// == PLAYER FUNCTIONS ==
void	find_player_position(t_game *game);
void	find_exit_position(t_game *game);
void	count_collectibles(t_game *game);
char	**asignement_n_read_lines(int fd);

// == MAP FUNCTIONS ==
char	**read_map(char *filename);
int		map_loading_error(char **map, char *filename);
void	free_map(char **map);
void	calculate_map_size(t_game *game);

// == VALIDATE FUNCTIONS ==
int		count_map_height(char **map);
int		is_rectangular(char **map, int height, int width);
int		check_walls(char **map, int height, int width);
int 	check_elements(char **map, int height, int width);
int		validate_map(char **map);

#endif