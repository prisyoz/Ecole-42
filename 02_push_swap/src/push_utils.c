/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pang <pang@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/08 15:45:16 by pang              #+#    #+#             */
/*   Updated: 2025/09/10 21:53:01 by pang             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Free array after ft_split
void	free_array(char **arr)
{
	int	i;

	i = 0;
	while (arr && arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

// Free stack
void	free_stack(t_node *stack)
{
	t_node	*temp;

	while (stack)
	{
		temp = stack->next;
		free(stack);
		stack = temp;
	}
}

// Free everything
void	free_exit(t_struct *data)
{
	if (data->char_arr)
		free_array(data->char_arr);
	if (data->combined_str)
		free(data->combined_str);
	if (data->int_arr)
		free(data->int_arr);
	if (data->stack_a)
		free_stack(data->stack_a);
	if (data->stack_b)
		free_stack(data->stack_b);
	if (data->sorted_arr)
		free(data->sorted_arr);
	if (data->dp)
		free(data->dp);
	if (data->prev)
		free(data->prev);
	if (data->percentile)
		free(data->percentile);
}

void	free_errorexit(t_struct *data)
{
	free_exit(data);
	write(2, "Error\n", 6);
	exit(1);
}

int	data_size(t_struct *data)
{
	int	count;

	count = 0;
	while (data->char_arr[count])
		count++;
	return (count);
}
