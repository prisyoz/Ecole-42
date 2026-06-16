/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pang <pang@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/10 00:00:00 by chllee            #+#    #+#             */
/*   Updated: 2026/06/06 18:33:36 by pang             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "map.h"
# include "mlx.h"
# include <math.h>
# include <stdlib.h>

# define WIN_W		1280
# define WIN_H		720
# define MOVE_SPEED	0.02
# define ROT_SPEED	0.02
# define MARGIN		0.2
# define MOUSE		0.0005

# define TEX_NO		0
# define TEX_SO		1
# define TEX_WE		2
# define TEX_EA		3

# define KEY_W		119
# define KEY_A		97
# define KEY_S		115
# define KEY_D		100
# define KEY_LEFT	65361
# define KEY_RIGHT	65363
# define KEY_ESC	65307
# define KEY_TAB	65289

# define MINI_SCALE	18
# define MINI_CELLS	11
# define MINI_W		200
# define MINI_H		200
# define MINI_OFF_X	10
# define MINI_OFF_Y	10
# define MINI_BORD	8

typedef struct s_player
{
	double	pos_x;
	double	pos_y;
	double	dir_x;
	double	dir_y;
	double	plane_x;
	double	plane_y;
}	t_player;

typedef struct s_ray
{
	double	camera_x;
	double	ray_dir_x;
	double	ray_dir_y;
	int		map_x;
	int		map_y;
	double	side_dist_x;
	double	side_dist_y;
	double	delta_dist_x;
	double	delta_dist_y;
	double	perp_wall_dist;
	int		step_x;
	int		step_y;
	int		hit;
	int		side;
}	t_ray;

typedef struct s_tex
{
	void	*img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
	int		width;
	int		height;
}	t_tex;

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}	t_img;

typedef struct s_keys
{
	int	w;
	int	a;
	int	s;
	int	d;
	int	left;
	int	right;
	int	captured;
}	t_keys;

typedef struct s_wall
{
	int	top;
	int	bot;
	int	line_h;
	int	full_h;
	int	x;
}	t_wall;

typedef struct s_game
{
	void		*mlx;
	void		*win;
	t_img		screen;
	t_tex		tex[4];
	t_player	player;
	t_map		*map;
	t_keys		keys;
}	t_game;

// game/init.c
int		init_game(t_game *g, t_map *map);

// game/events.c
int		key_press(int key, t_game *g);
int		key_release(int key, t_game *g);
int		close_win(t_game *g);
int		game_loop(t_game *g);
int		mouse_move(int x, int y, t_game *g);

// game/move.c
void	handle_movement(t_game *g);
void	rotate(t_game *g, double speed);

// render/render.c
int		is_wall(t_map *map, int x, int y);
void	render_frame(t_game *g);

// render/raycast.c
void	cast_ray(t_ray *r, t_player *p, t_map *map, int x);

// render/draw.c
void	draw_bg(t_game *g, t_wall *w);
void	draw_wall(t_game *g, t_ray *r, t_wall *w);
void	put_pixel(t_img *screen, int x, int y, int color);

// render/texture.c
int		get_tex_idx(t_ray *r);
int		get_tex_x(t_ray *r, t_player *p, int tex_w);
int		load_textures(t_game *g);

// mlx/mini.c
void	draw_minimap(t_game *g);
void	draw_mini_rect(t_game *g, int screen_x, int screen_y, int color);

// mlx/mini_mini.c
void	draw_mini_cells(t_game *g, int orig_x, int orig_y);
void	draw_mini_player(t_game *g);

#endif
