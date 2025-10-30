/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_process.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pang <pang@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 16:36:42 by pang              #+#    #+#             */
/*   Updated: 2025/08/17 18:10:44 by pang             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	empty_line(const char *line)
{
	if (!line)
		return (1);
	while (*line)
	{
		if (!(*line == ' ' || (*line >= 7 && *line <= 13)))
			return (0);
		line++;
	}
	return (1);
}

// Count number of rows
int	count_row(char *filename)
{
	int		fd;
	int		count;
	char	*line;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		exit_error("count lines file cannot open");
	count = 0;
	line = get_next_line(fd);
	while (line != NULL)
	{
		if (!(empty_line(line)))
			count++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (count);
}

// read map
static int	read_map(int fd, char **grid)
{
	char	*line;
	int		index;

	index = 0;
	line = get_next_line(fd);
	while (line)
	{
		strip_space(line);
		if (line[0] != '\0')
			grid[index++] = line;
		else
			free(line);
		line = get_next_line(fd);
	}
	grid[index] = NULL;
	return (index);
}

// Store map into 2D array
t_map	*store_map(char *filename)
{
	int		fd;
	int		lines_count;
	t_map	*map;

	fd = file_open(filename);
	lines_count = count_row(filename);
	map = malloc(sizeof(t_map));
	if (!map)
		exit_error("Allocation fail for map\n");
	map->grid = malloc(sizeof(char *) * (lines_count + 1));
	if (!map->grid)
		freealloc_exit(map, "Allocation fail for map grid\n");
	map->row_count = read_map(fd, map->grid);
	close(fd);
	return (map);
}

void	strip_space(char *line)
{
	int	len;

	len = ft_strlen(line);
	if (len > 0 && (((line[len - 1] >= 7) && line[len - 1] <= 13)
			|| line[len - 1] == ' '))
		line[len - 1] = '\0';
}
