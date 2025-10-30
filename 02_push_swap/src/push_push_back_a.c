/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_push_back_a.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pang <pang@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/06 16:59:09 by pang              #+#    #+#             */
/*   Updated: 2025/09/10 22:19:49 by pang             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	execute_moves_ab(t_node *best_node, t_struct *data)
{
	while (best_node->cost_a > 0 && best_node->cost_b > 0
		&& best_node->dir_a > 0 && best_node->dir_b > 0)
	{
		rotate_ab(data);
		best_node->cost_a--;
		best_node->cost_b--;
	}
	while (best_node->cost_a > 0 && best_node->cost_b > 0
		&& best_node->dir_a < 0 && best_node->dir_b < 0)
	{
		revrotate_ab(data);
		best_node->cost_a--;
		best_node->cost_b--;
	}
}

void	execute_moves_a(t_node *best_node, t_struct *data)
{
	if (best_node->dir_a > 0)
	{
		while (best_node->cost_a > 0)
		{
			rotate_a(data);
			best_node->cost_a--;
		}
	}
	else
	{
		while (best_node->cost_a > 0)
		{
			revrotate_a(data);
			best_node->cost_a--;
		}
	}
}

void	execute_moves_b(t_node *best_node, t_struct *data)
{
	if (best_node->dir_b == 1)
	{
		while (best_node->cost_b > 0)
		{
			rotate_b(data);
			best_node->cost_b--;
		}
	}
	else
	{
		while (best_node->cost_b > 0)
		{
			revrotate_b(data);
			best_node->cost_b--;
		}
	}
}

void	moving_sort(t_struct *data)
{
	t_node	*best_node;

	best_node = find_best_move(data);
	if (!best_node)
		return ;
	execute_moves_ab(best_node, data);
	execute_moves_a(best_node, data);
	execute_moves_b(best_node, data);
	push_a(data);
}
