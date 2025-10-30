/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_bonus_instructions_3.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pang <pang@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 16:46:15 by pang              #+#    #+#             */
/*   Updated: 2025/09/10 22:30:38 by pang             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

//Swap the first 2 elements at the top of stack a.
//Do nothing if there is only one element or none.
void	swap_a_bonus(t_checker *checker)
{
	t_bonus_node	*first;
	t_bonus_node	*second;

	if (!checker->stack_a || !checker->stack_a->next)
		return ;
	first = checker->stack_a;
	second = first->next;
	first->next = second->next;
	second->next = first;
	checker->stack_a = second;
}

void	swap_b_bonus(t_checker *checker)
{
	t_bonus_node	*first;
	t_bonus_node	*second;

	if (!checker->stack_b || !checker->stack_b->next)
		return ;
	first = checker->stack_b;
	second = first->next;
	first->next = second->next;
	second->next = first;
	checker->stack_b = second;
}

void	swap_ab_bonus(t_checker *checker)
{
	swap_a_bonus(checker);
	swap_b_bonus(checker);
}

// Take the first element at the top of b and put it at the top of a
// Do nothing if b is empty
void	push_a_bonus(t_checker *checker)
{
	t_bonus_node	*b_first;

	if (!checker->stack_b || !checker->stack_b)
		return ;
	b_first = checker->stack_b;
	checker->stack_b = b_first->next;
	b_first->next = checker->stack_a;
	checker->stack_a = b_first;
}

void	push_b_bonus(t_checker *checker)
{
	t_bonus_node	*a_first;

	if (!checker->stack_a || !checker->stack_a)
		return ;
	a_first = checker->stack_a;
	checker->stack_a = a_first->next;
	a_first->next = checker->stack_b;
	checker->stack_b = a_first;
}
