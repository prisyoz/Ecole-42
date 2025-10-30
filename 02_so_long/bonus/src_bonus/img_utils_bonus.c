/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_utils_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pang <pang@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 18:14:49 by pang              #+#    #+#             */
/*   Updated: 2025/08/27 11:39:48 by pang             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	free_resources(t_game *game)
{
	if (game->player_pos)
		free(game->player_pos);
	if (game->enemies)
	{
		free(game->enemies);
		game->enemies = NULL;
	}
	game->enemy_count = 0;
	if (game->map)
		free_map(game->map);
	free_more_resources(game);
}

void	free_more_resources(t_game *game)
{
	if (game->img.img_enemy)
		mlx_destroy_image(game->mlx_ptr, game->img.img_enemy);
	if (game->img.img_player)
		mlx_destroy_image(game->mlx_ptr, game->img.img_player);
	if (game->img.img_wall)
		mlx_destroy_image(game->mlx_ptr, game->img.img_wall);
	if (game->img.img_collectible)
		mlx_destroy_image(game->mlx_ptr, game->img.img_collectible);
	if (game->img.img_exit)
	{
		mlx_destroy_image(game->mlx_ptr, game->img.img_exit);
	}
	if (game->win_ptr)
		mlx_destroy_window(game->mlx_ptr, game->win_ptr);
	if (game->mlx_ptr)
	{
		mlx_destroy_display(game->mlx_ptr);
		free(game->mlx_ptr);
	}
}

void	success_game(t_game *game)
{
	ft_printf("Yay! Niam niam niam!!\n");
	free_resources(game);
	exit(EXIT_SUCCESS);
}

void	lose_game(t_game *game)
{
	ft_printf("Oi! Watch where you are going!!\n");
	free_resources(game);
	exit(EXIT_FAILURE);
}

void	init_game(t_game *game, t_map *map)
{
	srand(time(NULL));
	game->map = map;
	game->player_pos = malloc(sizeof(t_playerpos));
	if (!game->player_pos)
	{
		free_map(map);
		free_resources(game);
		exit_error("Player allocation failed");
	}
	init_enemies(game);
	game->player_pos->player_x = 0;
	game->player_pos->player_y = 0;
	game->player_collect = 0;
	game->player_moves = 0;
	game->last_enemy_move.tv_sec = 0;
	game->last_enemy_move.tv_usec = 0;
	game->current_frame = 0;
	game->win_width = 0;
	game->win_height = 0;
	game->map_offset_x = 0;
	game->map_offset_y = 0;
}
