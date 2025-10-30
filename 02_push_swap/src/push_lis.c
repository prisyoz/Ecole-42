/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_lis.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pang <pang@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 17:28:17 by pang              #+#    #+#             */
/*   Updated: 2025/09/14 10:43:21 by pang             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	lis_init(t_struct *data)
{
	int	index;

	index = 0;
	data->dp = malloc(sizeof(int) * data->arr_size);
	if (!data->dp)
		return ;
	data->prev = malloc(sizeof(int) * data->arr_size);
	if (!data->prev)
		return ;
	while (index < data->arr_size)
	{
		data->dp[index] = 1;
		data->prev[index] = -1;
		index++;
	}
}

void	set_longest_seq(t_struct *data)
{
	int	i;
	int	j;

	i = 1;
	while (i < data->arr_size)
	{
		j = 0;
		while (j < i)
		{
			if (data->int_arr[i] > data->int_arr[j])
			{
				if ((data->dp[j] + 1) > data->dp[i])
				{
					data->dp[i] = data->dp[j] + 1;
					data->prev[i] = j;
				}
			}
			j++;
		}
		i++;
	}
}

void	mark_keep(t_struct *data, int index)
{
	t_node	*curr;

	curr = data->stack_a;
	while (curr)
	{
		if (curr->ori_index == index)
		{
			curr->keep = 1;
			break ;
		}
		curr = curr->next;
	}
}

// Decide which one in the LIS is to keep. keep = 1, push = 0
void	stack_a_keeps(t_struct *data, int index)
{
	mark_keep(data, index);
	while (data->prev[index] != -1)
	{
		index = data->prev[index];
		mark_keep(data, index);
	}
}

void	stack_a_lis(t_struct *data)
{
	int		count;
	int		index;

	count = 0;
	data->lis_max_seq = data->dp[count];
	index = count;
	while (count < data->arr_size)
	{
		if (data->lis_max_seq < data->dp[count])
		{
			data->lis_max_seq = data->dp[count];
			index = count;
		}
		count++;
	}
	stack_a_keeps(data, index);
}
