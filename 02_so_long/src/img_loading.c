/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_loading.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pang <pang@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 00:06:59 by pang              #+#    #+#             */
/*   Updated: 2025/09/01 11:00:27 by pang             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	img_load(t_game *game)
{
	int	width;
	int	height;

	game->img.img_player = mlx_xpm_file_to_image(game->mlx_ptr,
			"textures/Pink0.xpm", &width, &height);
	game->img.img_wall = mlx_xpm_file_to_image(game->mlx_ptr,
			"textures/full_wall.xpm", &width, &height);
	game->img.img_collectible = mlx_xpm_file_to_image(game->mlx_ptr,
			"textures/trans_white_cheese_piece.xpm", &width, &height);
	game->img.img_exit = mlx_xpm_file_to_image(game->mlx_ptr,
			"textures/trans_door.xpm", &width, &height);
	if (!(game->img.img_player && game->img.img_wall
			&& game->img.img_collectible && game->img.img_exit))
	{
		free_resources(game);
		exit_error("Fail to load images");
	}
}

void	calculate_win_size(t_game *game)
{
	game->win_width = game->map->col_count * TILE;
	game->win_height = game->map->row_count * TILE;
}

static void	draw_tile(t_game *game, char tile, int x, int y)
{
	void	*img;

	if (tile == '1')
		img = game->img.img_wall;
	else if (tile == 'C')
		img = game->img.img_collectible;
	else if (tile == 'E')
		img = game->img.img_exit;
	else if (tile == 'P')
		img = game->img.img_player;
	else
		return ;
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
		img, y * TILE - game->map_offset_y,
		x * TILE - game->map_offset_x);
}

void	draw_map(t_game *game, t_map *map)
{
	int	x;
	int	y;

	x = 0;
	while (x < map->row_count)
	{
		y = 0;
		while (y < map->col_count)
		{
			draw_tile(game, map->grid[x][y], x, y);
			y++;
		}
		x++;
	}
}

void	render_frame(t_game *game)
{
	char	*label;
	char	*moves;
	char	*move_display;

	label = "Player moves:";
	moves = ft_itoa(game->player_moves);
	move_display = ft_strjoin(label, moves);
	mlx_clear_window(game->mlx_ptr, game->win_ptr);
	map_scroll_hori(game);
	map_scroll_vert(game);
	draw_map(game, game->map);
	mlx_string_put(game->mlx_ptr, game->win_ptr,
		20, 20, 0x8fbc8f, move_display);
	free(moves);
	free(move_display);
}
