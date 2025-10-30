/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pang <pang@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 21:20:30 by pang              #+#    #+#             */
/*   Updated: 2025/08/27 11:40:00 by pang             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_resources(t_game *game)
{
	if (game->player_pos)
		free(game->player_pos);
	if (game->map)
		free_map(game->map);
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

void	init_game(t_game *game, t_map *map)
{
	game->map = map;
	game->player_pos = malloc(sizeof(t_playerpos));
	if (!game->player_pos)
	{
		free_map(map);
		free_resources(game);
		exit_error("Player allocation failed");
	}
	game->player_pos->player_x = 0;
	game->player_pos->player_y = 0;
	game->player_collect = 0;
	game->player_moves = 0;
	game->win_width = 0;
	game->win_height = 0;
	game->map_offset_x = 0;
	game->map_offset_y = 0;
}
