/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manuelfe <manuelfe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/13 18:56:49 by manuelfe          #+#    #+#             */
/*   Updated: 2026/02/13 18:56:52 by manuelfe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <stdbool.h>
# include <math.h>
# include "libft.h"
# include "MLX42/MLX42.h"
# include "MLX42/MLX42_Int.h"

# ifndef M_PI
#  define M_PI 3.14159265358979323846
# endif

# define WIDTH 1920
# define HEIGHT 1080
# define TILE_SIZE 16
# define MINI_MAP_SIZE 200
# define MARGIN_MINIMAP 20

typedef struct s_direction
{
	double	dir_x;
	double	dir_y;
}	t_direction;

typedef struct s_pos
{
	int			x;
	int			y;
}	t_pos;

typedef struct s_map
{
	char		**map;
	int			h;
	int			w;
	t_pos		*init_position;
	char		orientation;
}	t_map;

typedef struct s_texture
{
	char			*north;
	char			*south;
	char			*west;
	char			*east;
	mlx_texture_t	*north_tex;
	mlx_texture_t	*south_tex;
	mlx_texture_t	*west_tex;
	mlx_texture_t	*east_tex;
}	t_texture;

typedef struct s_color
{
	int			r;
	int			g;
	int			b;
}	t_color;

typedef struct s_player
{
	double		pos_x;
	double		pos_y;
	double		dir_x;
	double		dir_y;
	double		plane_x;
	double		plane_y;
	double		move_speed;
	double		rot_speed;
}	t_player;

typedef struct s_ray
{
	double		cam_x;
	double		ray_dir_x;
	double		ray_dir_y;
	int			map_x;
	int			map_y;
	double		side_dist_x;
	double		side_dist_y;
	double		delta_dist_x;
	double		delta_dist_y;
	double		perp_wall_dist;
	int			step_x;
	int			step_y;
	int			hit;
	int			side;
}	t_ray;

typedef struct s_draw
{
	int		line_height;
	int		start;
	int		end;
	int		tex_x;
	double	step;
	double	tex_pos;
}	t_draw;

typedef struct s_game
{
	t_texture	*texture;
	t_color		*floor;
	t_color		*ceiling;
	t_map		*map;
	t_list		*list;
	mlx_t		*mlx;
	mlx_image_t	*img;
	t_player	*player;
	int			win_w;
	int			win_h;
	mlx_image_t	*img_3d;
	int			error;
}	t_game;

/* ************************************************************************ */
/*									VALIDATIONS								*/
/* ************************************************************************ */
	/*validate_map.c*/
int			ft_create_size_map(t_list *list_lines, t_map *map);
char		**ft_line_to_map(t_list *list, int h, int w);
void		ft_free_map(char **map, int h);
int			validate_map(t_map *map);
int			save_map(char *line, char *trim, t_list **list);
char		*clean_line(char *line);

	/*utils_validations.c*/
int			validate_file(char *av);
int			is_player_char(char c, t_map *map, t_pos pos, int *player_count);
int			is_correct_position(t_map *map, int x, int y);
int			is_char_valid(char c);
char		**ft_copy_map(char **map, int h, int w);

	/*utils_validations2.c*/
char		**allocate_map_lines(int h, int w);
void		copy_line_from_node(t_list *node, char *dest, int w);
int			check_file_extension(char *file);
int			is_valid_number(char *s);

	/*utils_validations3.c*/
int			list_to_map(t_game *game);
int			is_map(char *line);
int			init_flood_fill(t_map *map);

	/*flood_fill.c*/
int			flood_fill(char **map, t_pos pos, int h, int w);

/* ************************************************************************ */
/*									SAVE_FILE								*/
/* ************************************************************************ */
	/*save_file.c*/
int			save_file(int fd, t_game *game);

/* ************************************************************************ */
/*									UTILS									*/
/* ************************************************************************ */
	/*clean_game.c*/
void		clean_game(t_game *game);
void		free_cpy_map(char **cpy);
void		ft_close_mlx(void *param);

	/*utils_tokens.c*/
int			num_tokens(char **tok);
void		free_tokens(char **tk);
void		ft_free_list(t_list *list);

/* ************************************************************************ */
/*									INIT									*/
/* ************************************************************************ */
	/*init.c*/
t_game		*init_game(void);
void		init_player(t_game *game);
void		init_minimap(t_game *game);
void		init_imag_3d(t_game *game);

	/*window.c*/
int			init_window(t_game *game);
void		game_loop(void *param);
int			load_textures(t_game *game);

/* ************************************************************************ */
/*									PARSING									*/
/* ************************************************************************ */
	/*textures.c*/
int			is_texture(char *line);
int			save_texture(char *line, t_game *game, int *cf);

	/*colors.c*/
int			is_color(char *line);
int			save_color(char *line, t_game *game, int *cf);
int			parse_floor_color(char *color, t_game *game);
int			parse_ceiling_color(char *line, t_game *game);

/* ************************************************************************ */
/*									MOVES									*/
/* ************************************************************************ */
	/*keyboard.c*/
void		key_loop(void *param);
void		look_player(t_game *game, int dir);
void		update_direction_line(t_game *game);

	/*movements.c*/
void		up_move(t_game *game);
void		down_move(t_game *game);
void		left_move(t_game *game);
void		right_move(t_game *game);
void		render_frame(t_game *game);

/* ************************************************************************ */
/*									PRINT_MAP								*/
/* ************************************************************************ */
	/*print_map.c*/
void		draw_2d_map(t_game *game);
void		draw_player(t_game *game);
void		draw_square(t_game *game, t_pos pos, int size, uint32_t color);

	/*print_line.c*/
void		draw_direction_line(t_game *game);
void		draw_line(t_game *game, int t_x, int t_y, uint32_t color);
/* ************************************************************************ */
/*									MINI_DDA								*/
/* ************************************************************************ */
	/*mini_dda.c*/
//t_direction	find_hit(t_game *game, t_direction ray_dir);
void		cast_rays_3d(t_game *game);

/* ************************************************************************ */
/*									PRINT_3D								*/
/* ************************************************************************ */
	/*print_3d.c*/
void		init_draw(t_game *game, t_ray *ray, mlx_texture_t *tex, t_draw *d);
	/*draw_wall_slice.c*/
void		draw_wall_slice(t_game *game, t_ray *ray, int x);
	/*print_background.c*/
void		print_back_ground(t_game *game);

#endif
