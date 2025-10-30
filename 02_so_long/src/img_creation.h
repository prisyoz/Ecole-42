/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_creation.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pang <pang@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 21:05:01 by pang              #+#    #+#             */
/*   Updated: 2025/08/27 11:41:09 by pang             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMG_CREATION_H
# define IMG_CREATION_H

# include "so_long.h"
# define TILE 32
# define DIS_WIDTH 1280
# define DIS_HEIGHT 720

typedef struct s_map	t_map;

typedef struct s_texture
{
	void	*img_player;
	void	*img_wall;
	void	*img_collectible;
	void	*img_exit;
	void	*img_background;
	void	*img_display;
	void	*img_enemy;
}	t_texture;

typedef struct s_playerpos
{
	int	player_x;
	int	player_y;
}	t_playerpos;

typedef struct s_game
{
	void		*mlx_ptr;
	void		*win_ptr;
	int			win_width;
	int			win_height;
	int			player_collect;
	int			player_moves;
	int			map_offset_x;
	int			map_offset_y;
	t_texture	img;
	t_map		*map;
	t_playerpos	*player_pos;
}	t_game;

void	start_game(t_game *game);
void	init_game(t_game *game, t_map *map);
void	img_load(t_game *game);
void	map_scroll_vert(t_game *game);
void	map_scroll_hori(t_game *game);
void	draw_map(t_game *game, t_map *map);
void	render_frame(t_game *game);
void	free_resources(t_game *game);
void	calculate_win_size(t_game *game);
void	player_currpos(t_game *game, t_map *map);
void	success_game(t_game *game);
void	start_game(t_game *game);
int		game_movement(int keycode, t_game *game);
int		close_game(t_game *game);
void	move_player(t_game *game, int grid_x, int grid_y);

#endif