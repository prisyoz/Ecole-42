/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pang <pang@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 17:00:52 by pang              #+#    #+#             */
/*   Updated: 2025/08/30 19:36:15 by pang             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// Make sure its a rectangle. at least 3 rows, and 5 columns
void	rect_check(t_map *map)
{
	int	row;
	int	col;

	row = 0;
	col = 0;
	map->col_count = ft_strlen(map->grid[0]);
	if (map->row_count < 3 || map->col_count < 3
		|| map->row_count == map->col_count)
	{
		free_map(map);
		exit_error("Map too small / square map");
	}
	while (map->grid[row])
	{
		col = ft_strlen(map->grid[row]);
		if (col != map->col_count)
		{
			free_map(map);
			exit_error("Map issue");
		}
		row++;
	}
}

// Check that only contains 01PCE
void	character_check(t_map *map)
{
	map->row = 0;
	while (map->grid[map->row])
	{
		map->col = 0;
		while (map->grid[map->row][map->col])
		{
			if (map->grid[map->row][map->col] != '0'
				&& map->grid[map->row][map->col] != '1'
				&& map->grid[map->row][map->col] != 'P'
				&& map->grid[map->row][map->col] != 'C'
				&& map->grid[map->row][map->col] != 'E')
			{
				free_map(map);
				exit_error("Invalid characters");
			}
			map->col++;
		}
		map->row++;
	}
}

// Check that only contains 1P, 1E and at least 1C
void	pce_check(t_map *map)
{
	map->start_count = 0;
	map->exit_count = 0;
	map->collect_count = 0;
	map->row = 0;
	while (map->grid[map->row])
	{
		map->col = 0;
		while (map->grid[map->row][map->col])
		{
			if (map->grid[map->row][map->col] == 'P')
				map->start_count++;
			if (map->grid[map->row][map->col] == 'E')
				map->exit_count++;
			if (map->grid[map->row][map->col] == 'C')
				map->collect_count++;
			map->col++;
		}
		map->row++;
	}
	if (map->start_count != 1 || map->exit_count != 1 || map->collect_count < 1)
	{
		free_map(map);
		exit_error("Map not playable\n");
	}
}

// Check that boundaries are 1
void	boundaries_check(t_map *map)
{
	map->col = 0;
	while (map->col < map->col_count)
	{
		if (map->grid[0][map->col] != '1'
			|| map->grid[map->row_count - 1][map->col] != '1')
		{
			free_map(map);
			exit_error("Top or bottom wall boundaries");
		}
		map->col++;
	}
	map->row = 0;
	while (map->row < map->row_count)
	{
		if (map->grid[map->row][0] != '1'
			|| map->grid[map->row][map->col_count -1] != '1')
		{
			free_map(map);
			exit_error("Left or right wall boundaries");
		}
		map->row++;
	}
}
