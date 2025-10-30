/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_hack.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pang <pang@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 21:42:01 by pang              #+#    #+#             */
/*   Updated: 2025/08/18 16:40:06 by pang             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// Map scrolling logic: move the map when 
//the player reaches the window boundaries
// Keep player near the center of the window, if possible

void	map_scroll_hori(t_game *game)
{
	int	map_offset_y;
	int	map_width_px;
	int	player_y_px;

	map_offset_y = 0;
	map_width_px = game->map->col_count * TILE;
	player_y_px = game->player_pos->player_y * TILE;
	if (map_width_px > DIS_WIDTH)
	{
		if (player_y_px < DIS_WIDTH / 2)
			map_offset_y = 0;
		else if (player_y_px > map_width_px - DIS_WIDTH / 2)
			map_offset_y = map_width_px - DIS_WIDTH;
		else
			map_offset_y = player_y_px - DIS_WIDTH / 2;
	}
	else
		map_offset_y = 0;
	game->map_offset_y = map_offset_y;
}

void	map_scroll_vert(t_game *game)
{
	int	map_offset_x;
	int	map_height_px;
	int	player_x_px;
	int	max_offset_x;

	map_offset_x = 0;
	map_height_px = game->map->row_count * TILE;
	max_offset_x = map_height_px - DIS_HEIGHT;
	player_x_px = game->player_pos->player_x * TILE;
	if (map_height_px <= DIS_HEIGHT)
		map_offset_x = 0;
	if (map_height_px > DIS_HEIGHT)
	{
		map_offset_x = player_x_px - DIS_HEIGHT / 2;
		if (map_offset_x < 0)
			map_offset_x = 0;
		else if (map_offset_x > max_offset_x)
			map_offset_x = max_offset_x;
	}
	game->map_offset_x = map_offset_x;
}
