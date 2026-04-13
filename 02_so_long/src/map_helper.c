#include "so_long.h"

int	file_open(char *filename)
{
	int	fd;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		exit_error("Map cannot open");
	return (fd);
}

void	exit_error(char *msg)
{
	ft_printf("Error\n%s\n", msg);
	exit(EXIT_FAILURE);
}

void	free_map(t_map *map)
{
	int	count;

	if (!map)
		return ;
	if (map->grid)
	{
		count = 0;
		while (map->grid[count])
		{
			free(map->grid[count]);
			count++;
		}
		free(map->grid);
	}
	free(map);
}

void	freealloc_exit(t_map *map, char *msg)
{
	free_map(map);
	ft_printf("Error\n%s\n", msg);
	exit(EXIT_FAILURE);
}
