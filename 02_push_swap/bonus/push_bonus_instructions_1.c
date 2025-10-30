/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_bonus_instructions_1.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pang <pang@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 12:53:26 by pang              #+#    #+#             */
/*   Updated: 2025/09/10 14:48:14 by pang             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

// Shift up all emements of a stack by 1. first element becomes last
void	rotate_a_bonus(t_checker *checker)
{
	t_bonus_node	*a_first;
	t_bonus_node	*a_last;

	if (!checker->stack_a || !checker->stack_a->next)
		return ;
	a_first = checker->stack_a;
	a_last = checker->stack_a;
	while (a_last->next != NULL)
		a_last = a_last->next;
	checker->stack_a = a_first->next;
	a_last->next = a_first;
	a_first->next = NULL;
}

void	rotate_b_bonus(t_checker *checker)
{
	t_bonus_node	*b_first;
	t_bonus_node	*b_last;

	if (!checker->stack_b || !checker->stack_b->next)
		return ;
	b_first = checker->stack_b;
	b_last = checker->stack_b;
	while (b_last->next != NULL)
		b_last = b_last->next;
	checker->stack_b = b_first->next;
	b_last->next = b_first;
	b_first->next = NULL;
}

void	rotate_ab_bonus(t_checker *checker)
{
	rotate_a_bonus(checker);
	rotate_b_bonus(checker);
}
