/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_sort_array.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pang <pang@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 12:00:01 by pang              #+#    #+#             */
/*   Updated: 2025/09/10 22:19:16 by pang             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sorted_arr(t_struct *data)
{
	data->sorted_arr = malloc(sizeof(int) * data->arr_size);
	if (!data->sorted_arr)
		return ;
	data->sorted_arr = ft_memcpy(data->sorted_arr, data->int_arr,
			data->arr_size * sizeof(int));
	bubble_sort(data);
}

void	bubble_sort(t_struct *data)
{
	int	out;
	int	count;
	int	temp;

	out = 0;
	count = 0;
	while (out < data->arr_size - 1)
	{
		count = 0;
		while (count < data->arr_size - 1 - out)
		{
			if (data->sorted_arr[count] > data->sorted_arr[count + 1])
			{
				temp = data->sorted_arr[count];
				data->sorted_arr[count] = data->sorted_arr[count + 1];
				data->sorted_arr[count + 1] = temp;
			}
			count++;
		}
		out++;
	}
}

int	find_arr_index(int *arr, int value, int arr_size)
{
	int	i;

	i = 0;
	while (i < arr_size)
	{
		if (arr[i] == value)
			return (i);
		i++;
	}
	return (-1);
}

void	index_stack(t_struct *data)
{
	t_node	*curr;
	int		index;

	sorted_arr(data);
	curr = data->stack_a;
	while (curr != NULL)
	{
		index = find_arr_index(data->sorted_arr, curr->value, data->arr_size);
		curr->sorted_index = index;
		curr = curr->next;
	}
}
