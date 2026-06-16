/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_mini.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pang <pang@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/29 14:08:54 by pang              #+#    #+#             */
/*   Updated: 2026/05/29 14:40:58 by pang             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	draw_cell(t_game *g, int map[2], int orig[2])
{
	int		sx;
	int		sy;
	char	c;

	sx = MINI_OFF_X + (map[0] - orig[0]) * MINI_SCALE;
	sy = MINI_OFF_Y + (map[1] - orig[1]) * MINI_SCALE;
	if (map[1] < 0 || map[1] >= g->map->y_max || map[0] < 0
		|| (size_t)map[0] >= ft_strlen(g->map->grid[map[1]]))
		return ;
	c = g->map->grid[map[1]][map[0]];
	if (c == '1')
		draw_mini_rect(g, sx, sy, 0xFFFFFF);
	else if (c == '0' || c == 'N' || c == 'S' || c == 'E' || c == 'W')
		draw_mini_rect(g, sx, sy, 0x555555);
}

void	draw_mini_cells(t_game *g, int orig_x, int orig_y)
{
	int	map[2];
	int	orig[2];

	orig[0] = orig_x;
	orig[1] = orig_y;
	map[1] = orig_y;
	while (map[1] < orig_y + MINI_CELLS)
	{
		map[0] = orig_x;
		while (map[0] < orig_x + MINI_CELLS)
		{
			draw_cell(g, map, orig);
			map[0]++;
		}
		map[1]++;
	}
}

static void	draw_mini_dir(t_game *g, int px, int py)
{
	int	i;

	i = 0;
	while (i < MINI_SCALE)
	{
		put_pixel(&g->screen,
			px + (int)(g->player.dir_x * i),
			py + (int)(g->player.dir_y * i),
			0xFF0000);
		i++;
	}
}

void	draw_mini_player(t_game *g)
{
	int	px;
	int	py;
	int	dx;
	int	dy;

	px = MINI_OFF_X + (MINI_CELLS / 2) * MINI_SCALE;
	py = MINI_OFF_Y + (MINI_CELLS / 2) * MINI_SCALE;
	dy = -4;
	while (dy <= 4)
	{
		dx = -4;
		while (dx <= 4)
		{
			put_pixel(&g->screen, px + dx, py + dy, 0xFF0000);
			dx++;
		}
		dy++;
	}
	draw_mini_dir(g, px, py);
}
