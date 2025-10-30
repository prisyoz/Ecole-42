/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pang <pang@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 15:54:53 by pang              #+#    #+#             */
/*   Updated: 2025/08/30 19:30:28 by pang             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	start_game(t_game *game)
{
	img_load(game);
	player_currpos(game, game->map);
	render_frame(game);
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
