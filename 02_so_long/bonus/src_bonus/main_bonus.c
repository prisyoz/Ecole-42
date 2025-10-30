/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pang <pang@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 12:30:37 by pang              #+#    #+#             */
/*   Updated: 2025/08/26 21:11:01 by pang             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	game_loop(t_game *game)
{
	animate_enemy(game);
	render_frame(game);
	check_collision(game);
	return (1);
}

void	start_game(t_game *game)
{
	img_load(game);
	img_enemy_load(game);
	player_currpos(game, game->map);
	mlx_loop_hook(game->mlx_ptr, game_loop, game);
	mlx_hook(game->win_ptr, 2, KeyPressMask, game_movement, game);
	mlx_hook(game->win_ptr, 33, 0, close_game, game);
}

int	main(int argc, char **argv)
{
	t_game	game;
	t_map	*map;

	if (argc != 2)
		exit_error("Invalid argument");
	ext_file(argv[1]);
	map = process_map(argv[1]);
	game.map = map;
	game.mlx_ptr = mlx_init();
	if (!game.mlx_ptr)
		exit_error("mlx initialisation failed");
	calculate_win_size(&game);
	game.win_ptr = mlx_new_window(game.mlx_ptr,
			1280, 720, "Cheesy cheese");
	if (!game.win_ptr)
		exit_error("mlx window failed");
	init_game(&game, map);
	start_game(&game);
	mlx_loop(game.mlx_ptr);
	close_game(&game);
	return (0);
}
