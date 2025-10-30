/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_route_check_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pang <pang@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 12:31:42 by pang              #+#    #+#             */
/*   Updated: 2025/09/01 17:03:06 by pang             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

t_map	*copy_map(t_map *map)
{
	t_map	*map_copy;
	int		x;

	x = 0;
	map_copy = malloc(sizeof(t_map));
	if (!map_copy)
		freealloc_exit(map_copy, "Map allocation for map_copy fail");
	map_copy->row_count = map->row_count;
	map_copy->col_count = map->col_count;
	map_copy->grid = malloc(sizeof(char *) * (map->row_count + 1));
	if (!map_copy->grid)
		freealloc_exit(map_copy, "Map allocation for map copy->grid fail\n");
	while (x < map->row_count)
	{
		map_copy->grid[x] = malloc(sizeof(char) * (map->col_count + 1));
		if (!map_copy->grid[x])
			freealloc_exit(map_copy, "Allocation fail for map copy grid\n");
		ft_strlcpy(map_copy->grid[x], map->grid[x], map->col_count + 1);
		x++;
	}
	map_copy->grid[map->row_count] = NULL;
	return (map_copy);
}

void	player_start(t_map *map)
{
	int	x;
	int	y;

	x = 0;
	map->start_pos.x_pos = 0;
	map->start_pos.y_pos = 0;
	while (x < map->row_count)
	{
		y = 0;
		while (y < map->col_count)
		{
			if (map->grid[x][y] == 'P')
			{
				map->start_pos.x_pos = x;
				map->start_pos.y_pos = y;
				return ;
			}
			y++;
		}
		x++;
	}
}

void	flood_fill(t_map *map, int x, int y)
{
	if (x < 0 || y < 0 || x >= map->row_count || y >= map->col_count)
		return ;
	if (map->grid[x][y] == '1' || map->grid[x][y] == 'V'
		|| map->grid[x][y] == 'H')
		return ;
	if (map->grid[x][y] == 'C')
		map->collectibles++;
	if (map->grid[x][y] == 'E')
	{
		map->exit_found++;
		map->grid[x][y] = 'V';
		return ;
	}
	map->grid[x][y] = 'V';
	flood_fill(map, x + 1, y);
	flood_fill(map, x - 1, y);
	flood_fill(map, x, y + 1);
	flood_fill(map, x, y - 1);
}
