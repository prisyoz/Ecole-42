/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_sort_helper.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pang <pang@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 11:01:00 by pang              #+#    #+#             */
/*   Updated: 2025/09/12 14:40:07 by pang             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_min_value(t_node *stack)
{
	t_node	*curr;
	int		min_val;

	if (!stack)
		return (0);
	curr = stack;
	min_val = curr->value;
	while (curr)
	{
		if (curr->value < min_val)
			min_val = curr->value;
		curr = curr->next;
	}
	return (min_val);
}

int	find_index(t_node *stack, int value)
{
	t_node	*curr;
	int		count;

	curr = stack;
	count = 0;
	while (curr)
	{
		if (curr->value == value)
			return (count);
		count++;
		curr = curr->next;
	}
	return (-1);
}
