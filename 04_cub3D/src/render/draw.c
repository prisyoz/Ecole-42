/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pang <pang@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/10 00:00:00 by chllee            #+#    #+#             */
/*   Updated: 2026/05/30 16:32:47 by pang             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	put_pixel(t_img *screen, int x, int y, int color)
{
	char	*dst;

	if (x < 0 || x >= WIN_W || y < 0 || y >= WIN_H)
		return ;
	dst = screen->addr + (y * screen->line_len + x * (screen->bpp / 8));
	*(unsigned int *)dst = (unsigned int)color;
}

static int	get_tex_color(t_tex *tex, int tx, int ty)
{
	char	*src;

	if (tx < 0)
		tx = 0;
	if (ty < 0)
		ty = 0;
	if (tx >= tex->width)
		tx = tex->width - 1;
	if (ty >= tex->height)
		ty = tex->height - 1;
	src = tex->addr + (ty * tex->line_len + tx * (tex->bpp / 8));
	return (*(int *)src);
}

void	draw_bg(t_game *g, t_wall *w)
{
	int	y;

	y = 0;
	while (y < w->top)
	{
		put_pixel(&g->screen, w->x, y, (int)g->map->c_hex);
		y++;
	}
	y = w->bot + 1;
	while (y < WIN_H)
	{
		put_pixel(&g->screen, w->x, y, (int)g->map->f_hex);
		y++;
	}
}

static void	draw_tex_strip(t_game *g, t_tex *tex, t_wall *w, int tex_x)
{
	int		y;
	int		tex_y;
	double	step;
	double	tex_pos;

	step = 1.0 * tex->height / w->full_h;
	tex_pos = (w->top - WIN_H / 2 + w->full_h / 2) * step;
	y = w->top;
	while (y <= w->bot)
	{
		tex_y = (int)tex_pos & (tex->height - 1);
		tex_pos += step;
		put_pixel(&g->screen, w->x, y, get_tex_color(tex, tex_x, tex_y));
		y++;
	}
}

void	draw_wall(t_game *g, t_ray *r, t_wall *w)
{
	t_tex	*tex;
	int		tex_x;

	tex = &g->tex[get_tex_idx(r)];
	tex_x = get_tex_x(r, &g->player, tex->width);
	draw_tex_strip(g, tex, w, tex_x);
}
