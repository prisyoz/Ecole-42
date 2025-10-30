/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keypress_eventhandle_bonus.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pang <pang@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 12:30:12 by pang              #+#    #+#             */
/*   Updated: 2025/08/27 11:30:18 by pang             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

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

void	moves_display(t_game *game)
{
	char	*label;
	char	*moves;
	char	*move_display;

	label = "Player moves: ";
	moves = ft_itoa(game->player_moves);
	move_display = ft_strjoin(label, moves);
	mlx_string_put(game->mlx_ptr, game->win_ptr,
		20, 20, 0x8fbc8f, move_display);
	free(moves);
	free(move_display);
}

void	collect_display(t_game *game)
{
	char	*label;
	char	*collectibles;
	char	*collect_display;
	char	*collect_total;
	char	*temp;

	label = "Collectibles: ";
	collectibles = ft_itoa(game->player_collect);
	collect_total = ft_itoa(game->map->collect_count);
	collect_display = ft_strjoin(label, collectibles);
	temp = ft_strjoin(collect_display, " / ");
	free(collect_display);
	collect_display = temp;
	temp = ft_strjoin(collect_display, collect_total);
	free(collect_display);
	collect_display = temp;
	mlx_string_put(game->mlx_ptr, game->win_ptr,
		1020, 20, 0x8fbc8f, collect_display);
	free(collectibles);
	free(collect_total);
	free(collect_display);
}
