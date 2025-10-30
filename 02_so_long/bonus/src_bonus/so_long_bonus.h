/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pang <pang@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 12:31:59 by pang              #+#    #+#             */
/*   Updated: 2025/09/01 17:02:44 by pang             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <X11/keysym.h>
# include <X11/X.h>
# include <sys/time.h>
# include <time.h>
# include "ft_printf.h"
# include "get_next_line.h"
# include "img_creation_bonus.h"
# include "libft.h"
# include "mlx.h"

# include <stdio.h>

typedef struct s_pos
{
	int	x_pos;
	int	y_pos;
}	t_pos;

typedef struct s_map
{
	char	**grid;
	int		row_count;
	int		col_count;
	int		collect_count;
	int		start_count;
	int		exit_count;
	int		enemy_count;
	int		collectibles;
	int		exit_found;
	int		row;
	int		col;
	t_pos	start_pos;
}	t_map;

int		ft_strcmp(const char *s1, const char *s2);
int		count_row(char *filename);
int		file_open(char *filename);
void	ext_file(char *filename);
void	rect_check(t_map *map);
void	free_map(t_map *map);
void	freealloc_exit(t_map *map, char *msg);
void	map_validity(t_map *map);
void	strip_space(char *line);
void	character_check(t_map *map);
void	pce_check(t_map *map);
void	boundaries_check(t_map *map);
void	flood_fill(t_map *map, int x, int y);
void	player_start(t_map *map);
void	exit_error(char *msg);
void	init_map(t_map *map);
t_map	*copy_map(t_map *map);
t_map	*process_map(char *filename);
t_map	*store_map(char *filename);
size_t	ft_strlcpy(char *dest, const char *src, size_t size);

#endif