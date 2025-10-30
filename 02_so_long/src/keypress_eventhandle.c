/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keypress_eventhandle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pang <pang@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 17:00:53 by pang              #+#    #+#             */
/*   Updated: 2025/08/30 19:38:36 by pang             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	player_currpos(t_game *game, t_map *map)
{
	player_start(map);
	game->player_pos->player_x = map->start_pos.x_pos;
	game->player_pos->player_y = map->start_pos.y_pos;
}

int	game_movement(int keycode, t_game *game)
{
	if (keycode == XK_Escape)
	{
		close_game(game);
		exit(0);
	}
	if (keycode == XK_w || keycode == XK_Up)
		move_player(game, -1, 0);
	else if (keycode == XK_s || keycode == XK_Down)
		move_player(game, 1, 0);
	else if (keycode == XK_a || keycode == XK_Left)
		move_player(game, 0, -1);
	else if (keycode == XK_d || keycode == XK_Right)
		move_player(game, 0, 1);
	render_frame(game);
	return (0);
}

int	close_game(t_game *game)
{
	ft_printf("Oi! Where's my cheese!!! My cheese!!!!!\n");
	free_resources(game);
	exit(EXIT_FAILURE);
}

void	move_player(t_game *game, int grid_x, int grid_y)
{
	int		x;
	int		y;
	char	next_tile;

	x = game->player_pos->player_x;
	y = game->player_pos->player_y;
	next_tile = game->map->grid[x + grid_x][y + grid_y];
	if (next_tile == '1')
		return ;
	if (next_tile == 'E')
	{
		if (game->player_collect == game->map->collect_count)
			success_game(game);
		else
			return ;
	}
	if (next_tile == 'C')
		game->player_collect += 1;
	game->map->grid[x][y] = '0';
	game->map->grid[grid_x + x][grid_y + y] = 'P';
	game->player_pos->player_x += grid_x;
	game->player_pos->player_y += grid_y;
	game->player_moves += 1;
	ft_printf("Player move count: %d\n", game->player_moves);
}
