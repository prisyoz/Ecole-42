/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_sort_to_a_cal2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pang <pang@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/12 11:15:33 by pang              #+#    #+#             */
/*   Updated: 2025/09/12 11:18:40 by pang             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Moves to check b to rotate top
// current b top -> next, b_moves++; until it hits b->sorted 
void	moves_to_rotate_b(t_struct *data, t_node *target_node)
{
	t_node	*curr_b;
	int		position;

	curr_b = data->stack_b;
	position = 0;
	while (curr_b)
	{
		if (curr_b == target_node)
		{
			if (position <= data->size_b / 2)
			{
				target_node->cost_b = position;
				target_node->dir_b = 1;
			}
			else
			{
				target_node->cost_b = data->size_b - position;
				target_node->dir_b = -1;
			}
			return ;
		}
		curr_b = curr_b->next;
		position++;
	}
}

void	check_ab_cost(t_struct *data)
{
	t_node	*curr_b;

	curr_b = data->stack_b;
	while (curr_b)
	{
		moves_rotate_a(data, curr_b);
		moves_to_rotate_b(data, curr_b);
		curr_b->total_cost = ft_abs(curr_b->cost_a) + ft_abs(curr_b->cost_b);
		curr_b = curr_b->next;
	}
}

// Find the cheapest node to move
t_node	*find_best_move(t_struct *data)
{
	t_node	*curr;

	if (!data->stack_b)
		return (NULL);
	curr = data->stack_b;
	data->best_node = curr;
	while (curr)
	{
		if (curr->total_cost < data->best_node->total_cost)
			data->best_node = curr;
		curr = curr->next;
	}
	return (data->best_node);
}
