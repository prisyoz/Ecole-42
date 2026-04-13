#include "so_long_bonus.h"

void	move_player(t_game *game, int grid_x, int grid_y)
{
	int		x;
	int		y;
	char	next_tile;

	x = game->player_pos->player_x;
	y = game->player_pos->player_y;
	next_tile = game->map->grid[x + grid_x][y + grid_y];
	if (next_tile == '1')
		return ;
	if (next_tile == 'E')
	{
		if (game->player_collect == game->map->collect_count)
			success_game(game);
		else
			return ;
	}
	if (next_tile == 'C')
		game->player_collect += 1;
	game->map->grid[x][y] = '0';
	game->map->grid[grid_x + x][grid_y + y] = 'P';
	game->player_pos->player_x += grid_x;
	game->player_pos->player_y += grid_y;
	game->player_moves += 1;
	ft_printf("Player move count: %d\n", game->player_moves);
}
