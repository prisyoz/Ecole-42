/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_first_push_b.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pang <pang@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 15:59:39 by pang              #+#    #+#             */
/*   Updated: 2025/09/10 20:29:51 by pang             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// 0: first chunk (bot B) 1: second chunk (top B) 
// 2: last chunk(odd chunk) -1: not in any current chunk
int	chunk_target(t_struct *data, int index, int chunk)
{
	if (index < data->percentile[chunk])
		return (0);
	if (chunk + 1 < data->chunk_count && index >= data->percentile[chunk]
		&& index < data->percentile[chunk + 1])
		return (1);
	if (chunk + 1 == data->chunk_count && index >= data->percentile[chunk])
		return (2);
	return (-1);
}

int	push_chunk_node(t_struct *data, t_node *curr, int chunk)
{
	int	target;

	target = chunk_target(data, curr->sorted_index, chunk);
	if (target == 0)
	{
		push_b(data);
		rotate_b(data);
		data->size_a--;
		data->size_b++;
		return (1);
	}
	if (target > 0)
	{
		push_b(data);
		data->size_a--;
		data->size_b++;
		return (1);
	}
	return (0);
}

void	update_chunk(t_struct *data)
{
	data->current_chunk += 2;
	if (data->current_chunk >= data->chunk_count)
	{
		if (data->current_chunk == data->chunk_count + 1)
			data->current_chunk = data->chunk_count - 1;
		else
			data->current_chunk = data->chunk_count;
	}
	data->current_size -= data->push_node;
	data->push_node = 0;
	data->seen_node = 0;
}

void	push_to_b(t_struct *data)
{
	t_node	*curr;

	data->current_size = data->size_a;
	while (data->stack_a && data->current_chunk < data->chunk_count)
	{
		curr = data->stack_a;
		if (curr->keep == 1)
		{
			rotate_a(data);
			data->seen_node++;
		}
		else if (push_chunk_node(data, curr, data->current_chunk))
		{
			data->seen_node++;
			data->push_node++;
		}
		else
		{
			rotate_a(data);
			data->seen_node++;
		}
		if (data->seen_node == data->current_size)
			update_chunk(data);
	}
	find_lis_minmax_a(data);
}
