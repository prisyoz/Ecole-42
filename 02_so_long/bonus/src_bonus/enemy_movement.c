/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_movement.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pang <pang@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 15:22:12 by pang              #+#    #+#             */
/*   Updated: 2025/08/19 22:48:41 by pang             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	enemy_valid_move(t_game *game, int x, int y)
{
	int	index;

	index = 0;
	if (x < 0 || y < 0 || x >= game->map->row_count
		|| y >= game->map->col_count)
		return (0);
	if (game->map->grid[x][y] == '1' || game->map->grid[x][y] == 'E'
		|| game->map->grid[x][y] == 'C')
		return (0);
	while (index < game->enemy_count)
	{
		if (game->enemies[index].enemy_x == x
			&& game->enemies[index].enemy_y == y)
			return (0);
		index++;
	}
	return (1);
}

// Generate random direction: 0 = up, 1 = down, 2 = left, 3 = right
// Move all enemies
void	move_enemy(t_game *game, int index)
{
	int	direction;
	int	new_x;
	int	new_y;

	direction = rand() % 4;
	new_x = game->enemies[index].enemy_x;
	new_y = game->enemies[index].enemy_y;
	if (direction == 0)
		new_y--;
	else if (direction == 1)
		new_y++;
	else if (direction == 2)
		new_x--;
	else
		new_x++;
	if (enemy_valid_move(game, new_x, new_y) == 1)
	{
		game->map->grid[game->enemies[index].enemy_x]
		[game->enemies[index].enemy_y] = '0';
		game->map->grid[new_x][new_y] = 'H';
		game->enemies[index].enemy_x = new_x;
		game->enemies[index].enemy_y = new_y;
	}
}

void	enemy_movement(t_game *game)
{
	int	index;

	if (!game->enemies)
		return ;
	index = 0;
	while (index < game->enemy_count)
	{
		move_enemy(game, index);
		index++;
	}
}

void	check_collision(t_game *game)
{
	int	index;

	index = 0;
	if (!game->enemies)
		return ;
	while (index < game->enemy_count)
	{
		if (game->enemies[index].enemy_x == game->player_pos->player_x
			&& game->enemies[index].enemy_y == game->player_pos->player_y)
		{
			lose_game(game);
			return ;
		}
		index++;
	}
}
