/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_sort_data.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pang <pang@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 17:17:21 by pang              #+#    #+#             */
/*   Updated: 2025/09/10 20:35:18 by pang             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_data(t_struct *data)
{
	index_stack(data);
	lis_init(data);
	set_longest_seq(data);
	stack_a_lis(data);
	total_chunks(data);
	percentile_boundaries(data);
	push_to_b(data);
	while (data->size_b > 0)
	{
		check_ab_cost(data);
		moving_sort(data);
		data->size_a++;
		data->size_b--;
		find_lis_minmax_a(data);
	}
	final_sort_a(data);
}

void	final_sort_a(t_struct *data)
{
	int	min_pos;

	min_pos = find_sorted_pos(data->stack_a, 0);
	if (min_pos == -1)
		return ;
	if (min_pos <= data->size_a / 2)
	{
		while (min_pos > 0)
		{
			rotate_a(data);
			min_pos--;
		}
	}
	else
	{
		while (min_pos < data->size_a)
		{
			revrotate_a(data);
			min_pos++;
		}
	}
}

int	find_sorted_pos(t_node *stack, int target_sorted_index)
{
	t_node	*curr;
	int		position;

	curr = stack;
	position = 0;
	while (curr)
	{
		if (curr->sorted_index == target_sorted_index)
			return (position);
		curr = curr->next;
		position++;
	}
	return (-1);
}

void	sort_lis_stack_a(t_struct *data)
{
	t_node	*curr;
	int		pos;

	curr = data->stack_a;
	pos = 0;
	while (curr)
	{
		if (curr->sorted_index == data->lis_min_a)
			break ;
		curr = curr->next;
		pos++;
	}
	if (pos <= data->size_a / 2)
	{
		while (pos-- > 0)
			rotate_a(data);
	}
	else
	{
		pos = data->size_a - pos;
		while (pos-- > 0)
			revrotate_a(data);
	}
}
