/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pang <pang@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/25 22:02:06 by pang              #+#    #+#             */
/*   Updated: 2026/05/30 16:37:48 by pang             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_mini_rect(t_game *g, int screen_x, int screen_y, int color)
{
	int	x;
	int	y;

	y = 0;
	while (y < MINI_SCALE)
	{
		x = 0;
		while (x < MINI_SCALE)
		{
			put_pixel(&g->screen, screen_x + x, screen_y + y, color);
			x++;
		}
		y++;
	}
}

static void	clear_minimap(t_game *g)
{
	int	x;
	int	y;

	y = MINI_OFF_Y;
	while (y < MINI_OFF_Y + MINI_H)
	{
		x = MINI_OFF_X;
		while (x < MINI_OFF_X + MINI_W)
		{
			put_pixel(&g->screen, x, y, 0xFFFFFF);
			x++;
		}
		y++;
	}
}

static void	get_view_origin(t_game *g, int *orig_x, int *orig_y)
{
	*orig_x = (int)g->player.pos_x - MINI_CELLS / 2;
	*orig_y = (int)g->player.pos_y - MINI_CELLS / 2;
}

static void	draw_mini_border(t_game *g)
{
	int	x;
	int	y;
	int	i;

	i = 0;
	while (i < MINI_BORD)
	{
		x = MINI_OFF_X - MINI_BORD;
		while (x <= MINI_OFF_X + MINI_W + MINI_BORD)
		{
			put_pixel(&g->screen, x, MINI_OFF_Y - MINI_BORD + i, 0xff7f50);
			put_pixel(&g->screen, x, MINI_OFF_Y + MINI_H + i, 0xff7f50);
			x++;
		}
		y = MINI_OFF_Y - MINI_BORD;
		while (y <= MINI_OFF_Y + MINI_H + MINI_BORD)
		{
			put_pixel(&g->screen, MINI_OFF_X - MINI_BORD + i, y, 0xff7f50);
			put_pixel(&g->screen, MINI_OFF_X + MINI_W + i, y, 0xff7f50);
			y++;
		}
		i++;
	}
}

void	draw_minimap(t_game *g)
{
	int	orig_x;
	int	orig_y;

	get_view_origin(g, &orig_x, &orig_y);
	clear_minimap(g);
	draw_mini_cells(g, orig_x, orig_y);
	draw_mini_player(g);
	draw_mini_border(g);
}
