/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_creation_bonus.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pang <pang@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 12:29:09 by pang              #+#    #+#             */
/*   Updated: 2025/09/01 11:56:25 by pang             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMG_CREATION_BONUS_H
# define IMG_CREATION_BONUS_H

# include "so_long_bonus.h"
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
/* 	void	*img_background; */
	void	*img_display;
	void	*img_enemy;
}	t_texture;

typedef struct s_playerpos
{
	int	player_x;
	int	player_y;
}	t_playerpos;

typedef struct s_enemy_pos
{
	int	enemy_x;
	int	enemy_y;
}	t_enemypos;

typedef struct s_game
{
	void			*mlx_ptr;
	void			*win_ptr;
	int				win_width;
	int				win_height;
	int				player_collect;
	int				player_moves;
	int				map_offset_x;
	int				map_offset_y;
	int				current_frame;
	int				enemy_count;
	int				current_enemy_frame;
	struct timeval	last_enemy_move;
	struct timeval	last_animation_time;
	t_texture		img;
	t_map			*map;
	t_playerpos		*player_pos;
	t_enemypos		*enemies;
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
void	lose_game(t_game *game);
void	start_game(t_game *game);
void	img_enemy_load(t_game *game);
void	animate_enemy(t_game *game);
void	enemy_movement(t_game *game);
void	check_collision(t_game *game);
void	init_enemies(t_game *game);
void	render_enemies(t_game *game);
void	moves_display(t_game *game);
void	collect_display(t_game *game);
void	free_more_resources(t_game *game);
int		game_movement(int keycode, t_game *game);
int		close_game(t_game *game);
int		enemy_valid_move(t_game *game, int x, int y);
long	get_time(void);
void	move_player(t_game *game, int grid_x, int grid_y);

#endif