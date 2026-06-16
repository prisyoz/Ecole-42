/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chllee <chllee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/10 00:00:00 by chllee            #+#    #+#             */
/*   Updated: 2026/06/09 18:56:24 by chllee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	key_press(int key, t_game *g)
{
	if (key == KEY_ESC)
		close_win(g);
	if (key == KEY_W)
		g->keys.w = 1;
	if (key == KEY_A)
		g->keys.a = 1;
	if (key == KEY_S)
		g->keys.s = 1;
	if (key == KEY_D)
		g->keys.d = 1;
	if (key == KEY_LEFT)
		g->keys.left = 1;
	if (key == KEY_RIGHT)
		g->keys.right = 1;
	if (key == KEY_TAB)
	{
		g->keys.captured = !g->keys.captured;
		if (g->keys.captured)
			mlx_mouse_move(g->mlx, g->win, WIN_W / 2, WIN_H / 2);
	}
	return (0);
}

int	key_release(int key, t_game *g)
{
	if (key == KEY_W)
		g->keys.w = 0;
	if (key == KEY_A)
		g->keys.a = 0;
	if (key == KEY_S)
		g->keys.s = 0;
	if (key == KEY_D)
		g->keys.d = 0;
	if (key == KEY_LEFT)
		g->keys.left = 0;
	if (key == KEY_RIGHT)
		g->keys.right = 0;
	return (0);
}

int	close_win(t_game *g)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (g->tex[i].img)
			mlx_destroy_image(g->mlx, g->tex[i].img);
		i++;
	}
	if (g->screen.img)
		mlx_destroy_image(g->mlx, g->screen.img);
	free_resources(g->map);
	mlx_destroy_window(g->mlx, g->win);
	mlx_destroy_display(g->mlx);
	free(g->mlx);
	exit(0);
	return (0);
}

// mlx hori plane
int	mouse_move(int x, int y, t_game *g)
{
	int	pixel;

	(void)y;
	if (!g->keys.captured)
		return (0);
	if (x == WIN_W / 2)
		return (0);
	pixel = x - WIN_W / 2;
	if (pixel > 33)
		pixel = 33;
	if (pixel < -33)
		pixel = -33;
	rotate(g, pixel * MOUSE);
	mlx_mouse_move(g->mlx, g->win, WIN_W / 2, WIN_H / 2);
	return (0);
}

int	game_loop(t_game *g)
{
	handle_movement(g);
	render_frame(g);
	draw_minimap(g);
	mlx_put_image_to_window(g->mlx, g->win, g->screen.img, 0, 0);
	return (0);
}
