/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_bonus_stdin.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pang <pang@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 14:13:42 by pang              #+#    #+#             */
/*   Updated: 2025/09/14 11:48:30 by pang             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

// 0 - reads stdin
void	*read_stdin(t_checker *checker)
{
	char	*line;

	while (1)
	{
		line = get_next_line(0);
		if (!line)
			break ;
		if (ft_strcmp(line, "\n") == 0 || !check_instructions(line, checker))
		{
			free(line);
			free_get_next_line();
			free_error_exit(checker);
		}
		free(line);
	}
	free_get_next_line();
	return (NULL);
}

int	check_instructions(char *line, t_checker *checker)
{
	if (ft_strcmp(line, "pa\n") == 0)
		push_a_bonus(checker);
	else if (ft_strcmp(line, "pb\n") == 0)
		push_b_bonus(checker);
	else if (ft_strcmp(line, "ss\n") == 0)
		swap_ab_bonus(checker);
	else if (ft_strcmp(line, "ra\n") == 0)
		rotate_a_bonus(checker);
	else if (ft_strcmp(line, "rb\n") == 0)
		rotate_b_bonus(checker);
	else if (ft_strcmp(line, "rr\n") == 0)
		rotate_ab_bonus(checker);
	else if (ft_strcmp(line, "rra\n") == 0)
		revrotate_a_bonus(checker);
	else if (ft_strcmp(line, "rrb\n") == 0)
		revrotate_b_bonus(checker);
	else if (ft_strcmp(line, "rrr\n") == 0)
		revrotate_ab_bonus(checker);
	else if (ft_strcmp(line, "sa\n") == 0)
		swap_a_bonus(checker);
	else if (ft_strcmp(line, "sb\n") == 0)
		swap_b_bonus(checker);
	else
		return (0);
	return (1);
}
