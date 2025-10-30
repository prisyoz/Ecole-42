/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pang <pang@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 15:24:10 by pang              #+#    #+#             */
/*   Updated: 2025/08/19 22:39:22 by pang             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	enemy_count(t_game *game)
{
	int	count;
	int	x;
	int	y;

	count = 0;
	x = 0;
	while (x < game->map->row_count)
	{
		y = 0;
		while (y < game->map->col_count)
		{
			if (game->map->grid[x][y] == 'H')
				count++;
			y++;
		}
		x++;
	}
	return (count);
}

static void	malloc_enemy(t_game *game)
{
	game->enemy_count = enemy_count(game);
	if (game->enemy_count == 0)
	{
		game->enemies = NULL;
		return ;
	}
	game->enemies = malloc(sizeof(t_enemypos) * game->enemy_count);
	if (!game->enemies)
	{
		free_resources(game);
		exit_error("Enemy allocation failed");
	}
}

void	init_enemies(t_game *game)
{
	int	x;
	int	y;
	int	enemy_index;

	x = 0;
	enemy_index = 0;
	malloc_enemy(game);
	while (x < game->map->row_count && enemy_index < game->enemy_count)
	{
		y = 0;
		while (y < game->map->col_count && enemy_index < game->enemy_count)
		{
			if (game->map->grid[x][y] == 'H')
			{
				game->enemies[enemy_index].enemy_x = x;
				game->enemies[enemy_index].enemy_y = y;
				enemy_index++;
			}
			y++;
		}
		x++;
	}
}

void	render_enemies(t_game *game)
{
	int	i;

	if (!game->enemies)
		return ;
	i = 0;
	while (i < game->enemy_count)
	{
		animate_enemy(game);
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
			game->img.img_enemy,
			game->enemies[i].enemy_y * TILE - game->map_offset_y,
			game->enemies[i].enemy_x * TILE - game->map_offset_x);
		i++;
	}
}
