#include "so_long_bonus.h"

void	img_enemy_load(t_game *game)
{
	int	width;
	int	height;

	game->img.img_enemy = mlx_xpm_file_to_image(game->mlx_ptr,
			"textures/trans_enemy1.xpm", &width, &height);
	if (!game->img.img_enemy)
	{
		free_resources(game);
		exit_error("Failure to load enemy image");
	}
}

// Gets current time in milliseconds
long	get_time(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return (tv.tv_sec * 1000 + tv.tv_usec / 1000);
}

void	animate_enemy(t_game *game)
{
	long	current;
	long	last_move;

	current = get_time();
	last_move = game->last_enemy_move.tv_sec * 1000
		+ game->last_enemy_move.tv_usec / 1000;
	if (current - last_move >= 500)
	{
		enemy_movement(game);
		gettimeofday(&game->last_enemy_move, NULL);
	}
}
