/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_process.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pang <pang@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/19 17:19:46 by pang              #+#    #+#             */
/*   Updated: 2026/05/29 14:33:35 by pang             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

static t_map	*init_map(void)
{
	t_map	*map;

	map = malloc(sizeof(t_map));
	if (!map)
		exit_error("Map allocation fail\n");
	ft_bzero(map, sizeof(t_map));
	return (map);
}

static int	handle_line(char *line, t_map *map, int fd)
{
	char	*temp;

	strip_newline(line);
	temp = line;
	while (*temp && ft_isspace(*temp))
		temp++;
	if (*temp == '\0')
		return (0);
	if (is_mapline(temp))
	{
		if (map->texture_count != 6)
		{
			free(line);
			clear_gnl_buffer(fd);
			freealloc_exit(map, "Headers issue");
		}
		return (1);
	}
	path_allocation(line, map);
	return (0);
}

static t_map	*parse_map_loop(int fd, t_map *map, char *filename)
{
	char	*line;
	int		line_count;

	line_count = 0;
	line = get_next_line(fd);
	while (line)
	{
		line_count++;
		if (handle_line(line, map, fd))
		{
			free(line);
			clear_gnl_buffer(fd);
			close(fd);
			store_map(filename, map, line_count - 1);
			map_validity(map);
			return (map);
		}
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	freealloc_exit(map, "No map found");
	return (NULL);
}

t_map	*process_file(char *filename)
{
	int		fd;
	t_map	*map;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		exit_error("Cannot open file");
	map = init_map();
	if (!map)
	{
		close(fd);
		return (NULL);
	}
	return (parse_map_loop(fd, map, filename));
}

void	map_validity(t_map *map)
{
	valid_char(map);
	check_player(map);
	valid_path(map->no_path, map);
	valid_path(map->so_path, map);
	valid_path(map->we_path, map);
	valid_path(map->ea_path, map);
	valid_colours(map->f_path, map);
	valid_colours(map->c_path, map);
	boundaries_check(map);
	hex_colours(map);
}
