/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_instructions_1.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pang <pang@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 12:53:26 by pang              #+#    #+#             */
/*   Updated: 2025/09/10 14:24:59 by pang             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Shift up all emements of a stack by 1. first element becomes last
void	rotate_a_clean(t_struct *data)
{
	t_node	*a_first;
	t_node	*a_last;

	if (!data->stack_a || !data->stack_a->next)
		return ;
	a_first = data->stack_a;
	a_last = data->stack_a;
	while (a_last->next != NULL)
		a_last = a_last->next;
	data->stack_a = a_first->next;
	a_last->next = a_first;
	a_first->next = NULL;
}

void	rotate_b_clean(t_struct *data)
{
	t_node	*b_first;
	t_node	*b_last;

	if (!data->stack_b || !data->stack_b->next)
		return ;
	b_first = data->stack_b;
	b_last = data->stack_b;
	while (b_last->next != NULL)
		b_last = b_last->next;
	data->stack_b = b_first->next;
	b_last->next = b_first;
	b_first->next = NULL;
}

void	rotate_ab(t_struct *data)
{
	rotate_a_clean(data);
	rotate_b_clean(data);
	data->ins_count++;
	write(1, "rr\n", 3);
}

void	rotate_b(t_struct *data)
{
	rotate_b_clean(data);
	data->ins_count++;
	write(1, "rb\n", 3);
}
