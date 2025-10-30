/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_instructions_3.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pang <pang@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 16:46:15 by pang              #+#    #+#             */
/*   Updated: 2025/09/10 20:31:12 by pang             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//Swap the first 2 elements at the top of stack a.
//Do nothing if there is only one element or none.
void	swap_a_clean(t_struct *data)
{
	t_node	*first;
	t_node	*second;

	if (!data->stack_a || !data->stack_a->next)
		return ;
	first = data->stack_a;
	second = first->next;
	first->next = second->next;
	second->next = first;
	data->stack_a = second;
}

void	swap_b_clean(t_struct *data)
{
	t_node	*first;
	t_node	*second;

	if (!data->stack_b || !data->stack_b->next)
		return ;
	first = data->stack_b;
	second = first->next;
	first->next = second->next;
	second->next = first;
	data->stack_b = second;
}

void	swap_ab(t_struct *data)
{
	swap_a_clean(data);
	swap_b_clean(data);
	data->ins_count++;
	write(1, "ss\n", 3);
}

// Take the first element at the top of b and put it at the top of a
// Do nothing if b is empty
void	push_a(t_struct *data)
{
	t_node	*b_first;

	if (!data->stack_b || !data->stack_b)
		return ;
	b_first = data->stack_b;
	data->stack_b = b_first->next;
	b_first->next = data->stack_a;
	data->stack_a = b_first;
	data->ins_count++;
	write(1, "pa\n", 3);
}

void	push_b(t_struct *data)
{
	t_node	*a_first;

	if (!data->stack_a || !data->stack_a)
		return ;
	a_first = data->stack_a;
	data->stack_a = a_first->next;
	a_first->next = data->stack_b;
	data->stack_b = a_first;
	data->ins_count++;
	write(1, "pb\n", 3);
}
