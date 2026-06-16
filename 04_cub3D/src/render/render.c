/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pang <pang@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/10 00:00:00 by chllee            #+#    #+#             */
/*   Updated: 2026/05/29 13:13:16 by pang             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	is_wall(t_map *map, int x, int y)
{
	char	c;

	if (y < 0 || y >= map->y_max || x < 0)
		return (1);
	if (!map->grid[y] || x >= (int)ft_strlen(map->grid[y]))
		return (1);
	c = map->grid[y][x];
	return (c != '0' && c != 'N' && c != 'S' && c != 'E' && c != 'W');
}

static void	get_wall_bounds(double perp_dist, t_wall *w)
{
	if (perp_dist < 0.1)
		perp_dist = 0.1;
	w->full_h = (int)(WIN_H / perp_dist);
	w->line_h = w->full_h;
	w->top = WIN_H / 2 - w->line_h / 2;
	w->bot = WIN_H / 2 + w->line_h / 2;
	if (w->top < 0)
		w->top = 0;
	if (w->bot >= WIN_H)
		w->bot = WIN_H - 1;
}

void	render_frame(t_game *g)
{
	t_ray	ray;
	t_wall	wall;
	int		x;

	x = 0;
	while (x < WIN_W)
	{
		cast_ray(&ray, &g->player, g->map, x);
		wall.x = x;
		get_wall_bounds(ray.perp_wall_dist, &wall);
		draw_bg(g, &wall);
		draw_wall(g, &ray, &wall);
		x++;
	}
}
