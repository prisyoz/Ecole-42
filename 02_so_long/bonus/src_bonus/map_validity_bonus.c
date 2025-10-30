/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validity_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pang <pang@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 12:31:51 by pang              #+#    #+#             */
/*   Updated: 2025/09/01 16:57:59 by pang             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

// Check that file ends in .ber and more than .ber (4 characters)
void	ext_file(char *filename)
{
	int	len;

	len = ft_strlen(filename);
	if (len < 4)
		exit_error("Filename invalid");
	if (ft_strcmp((filename + len - 4), ".ber") != 0)
		exit_error("Invalid ext filename");
}

// check for file validity
t_map	*process_map(char *filename)
{
	int		fd;
	t_map	*map;
	int		file_size;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		exit_error("File check cannot open");
	file_size = count_row(filename);
	close(fd);
	if (file_size <= 0)
		exit_error("Empty map\n");
	map = store_map(filename);
	map_validity(map);
	return (map);
}

// Check for map validity
void	map_validity(t_map *map)
{
	t_map	*map_copy;

	init_map(map);
	rect_check(map);
	character_check(map);
	pce_check(map);
	boundaries_check(map);
	map_copy = copy_map(map);
	player_start(map_copy);
	map_copy->collect_count = map->collect_count;
	map_copy->collectibles = 0;
	map_copy->exit_found = 0;
	flood_fill(map_copy, map_copy->start_pos.x_pos, map_copy->start_pos.y_pos);
	if (map_copy->collectibles != map_copy->collect_count
		|| map_copy->exit_found != 1)
	{
		free_map(map_copy);
		freealloc_exit(map, "No valid path");
	}
	free_map(map_copy);
}
