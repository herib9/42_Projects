/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmolina <<hmolina@student.42.fr>>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 20:18:54 by hmolina           #+#    #+#             */
/*   Updated: 2025/08/07 19:14:18 by hmolina          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

// == LIBRERIES ==
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include "libft.h"
# include "../libs/minilibx/mlx.h"
# include <X11/keysym.h>
# include <X11/X.h>

// == GAME CONSTANTS ==
# define TILE_SIZE 64

// == MAP ELEMENTS ==
# define EMPTY '0'
# define WALL '1'
# define COIN 'C'
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

// == GAME STRUCTURES ==
typedef struct s_game
{
	// == GRAPHICS CONNECTION ==
	void	*mlx;
	void	*win;

	// == SPRITES ==
	void	*_1;
	void	*_0;
	void	*_p;
	void	*_c;
	void	*_e;

	// == MAP ==
	char	**map;
	int		map_width;
	int		map_height;

	// == PLAYER POSITION ==
	int		p_x;
	int		p_y;

	// == EXIT POSITION ==
	int		exit_x;
	int		exit_y;

	// == STATS ==
	int		moves;
	int		coined;
	int		t_coin;

	// == ELEMENTS ==
	int		player;
	int		exit;
	int		coin;

}	t_game;

// == CHECK FUNCTIONS ==
int		check_walls(t_game *g);
void	check_elements(t_game *game);
int		check_valid_chars(t_game *g);
int		check_coins_accesibility(t_game *g);
int		check_exit_accesibility(t_game *g);

// == FLOOD_FILL ==
char	**copy_map(char **map, int height);
void	flood_fill(char **map, int x, int y, t_game *g);
void	exit_flood_fill(char **map, int x, int y, t_game *g);
int		check_player_can_move(t_game *g);

// == GRAPHICS FUNCTIONS ==
int		load_sprites(t_game *g);
int		init_graphics(t_game *g);
void	render_map(t_game *g);
void	render_coin(t_game *g, int x, int y);
void	render_exit(t_game *g, int x, int y);

// == INPUT FUNCTIONS ==
int		close_game(t_game *g);
int		close_handler(t_game *g);
void	handle_coin(t_game *g);
void	update_stats_display(t_game *g);

// == MAP FUNCTIONS ==
char	**asignement_n_read_lines(int fd);
char	**read_map(char *filename);
int		map_loading_error(char **map, char *filename);
void	free_map(char **map);
void	calculate_map_size(t_game *g);

// == MOVEMENT FUNCIONTS ==
int		keymap(int keycode, t_game *g);
void	move_player(t_game *g, int dx, int dy);
void	update_stats_display(t_game *g);

// == PLAYER FUNCTIONS ==
void	find_player_position(t_game *g);
void	find_exit_position(t_game *g);
void	count_coin(t_game *g);

// == SO_LONG ==
int		st_val_map(t_game *g, char *filename);
int		nd_val_map(t_game *g);
int		init_game(t_game *g);
int		main(int ac, char **av);

// == VALIDATE FUNCTIONS ==
int		count_map_height(char **map);
int		is_rectangular(char **map, int height, int width);
int		validate_map(char **map);
int		check_walls(t_game *g);
void	check_elements(t_game *game);

#endif