/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_basic_sort.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pang <pang@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 14:50:15 by pang              #+#    #+#             */
/*   Updated: 2025/09/13 23:49:25 by pang             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_two(t_struct *data)
{
	int	first;
	int	second;

	if (!data->stack_a || !data->stack_a->next)
		return ;
	first = data->stack_a->value;
	second = data->stack_a->next->value;
	if (first > second)
		swap_a(data);
	else
		return ;
}

void	sort_three(t_struct *data)
{
	int	a;
	int	b;
	int	c;

	if (!data->stack_a || !data->stack_a->next || !data->stack_a->next->next)
		return ;
	a = data->stack_a->value;
	b = data->stack_a->next->value;
	c = data->stack_a->next->next->value;
	if (a < b && b > c && a < c)
	{
		swap_a(data);
		rotate_a(data);
	}
	else if (a > b && b < c && a < c)
		swap_a(data);
	else if (a < b && b > c && a > c)
		revrotate_a(data);
	else if (a > b && b > c)
	{
		rotate_a(data);
		swap_a(data);
	}
	else if (a > b && b < c && a > c)
		rotate_a(data);
}

void	push_smallest_to_b(t_struct *data)
{
	int	min_val;
	int	position;

	while (data->size_a > 3)
	{
		min_val = find_min_value(data->stack_a);
		position = find_index(data->stack_a, min_val);
		if (position <= data->size_a / 2)
		{
			while (data->stack_a->value != min_val)
				rotate_a(data);
		}
		else
		{
			while (data->stack_a->value != min_val)
				revrotate_a(data);
		}
		push_b(data);
		data->size_a--;
		data->size_b++;
	}
}

void	sort_five(t_struct *data)
{
	push_smallest_to_b(data);
	sort_three(data);
	while (data->size_b > 0)
	{
		push_a(data);
		data->size_a++;
		data->size_b--;
	}
}
