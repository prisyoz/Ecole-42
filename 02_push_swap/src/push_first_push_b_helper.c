/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_first_push_b_helper.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pang <pang@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 10:43:14 by pang              #+#    #+#             */
/*   Updated: 2025/09/10 20:32:51 by pang             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	total_chunks(t_struct *data)
{
	if (data->arr_size <= 200)
		data->chunk_count = 4;
	else if (data->arr_size > 200 && data->arr_size < 1000)
		data->chunk_count = data->arr_size / 50;
	else if (data->arr_size >= 1000)
		data->chunk_count = 20;
}

void	percentile_boundaries(t_struct *data)
{
	int			index;

	data->percentile = malloc(sizeof(int) * data->chunk_count);
	if (!data->percentile)
		return ;
	index = 0;
	while (index < data->chunk_count - 1)
	{
		data->percentile[index] = data->arr_size
			/ data->chunk_count * (index + 1);
		index++;
	}
	data->percentile[index] = data->arr_size;
}

void	find_lis_minmax_a(t_struct *data)
{
	t_node	*curr;

	curr = data->stack_a;
	if (!curr)
		return ;
	data->lis_min_a = curr->sorted_index;
	data->lis_max_a = curr->sorted_index;
	while (curr)
	{
		if (curr->sorted_index < data->lis_min_a)
			data->lis_min_a = curr->sorted_index;
		if (curr->sorted_index > data->lis_max_a)
			data->lis_max_a = curr->sorted_index;
		curr = curr->next;
	}
}
