/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_bonus_instructions_2.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pang <pang@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 13:10:46 by pang              #+#    #+#             */
/*   Updated: 2025/09/10 14:48:22 by pang             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

// last element becomes first one
void	revrotate_a_bonus(t_checker *checker)
{
	t_bonus_node	*prev;
	t_bonus_node	*last;

	if (!checker->stack_a || !(checker->stack_a)->next)
		return ;
	prev = NULL;
	last = checker->stack_a;
	while (last->next != NULL)
	{
		prev = last;
		last = last->next;
	}
	prev->next = NULL;
	last->next = checker->stack_a;
	checker->stack_a = last;
}

void	revrotate_b_bonus(t_checker *checker)
{
	t_bonus_node	*prev;
	t_bonus_node	*last;

	if (!checker->stack_b || !checker->stack_b || !checker->stack_b->next)
		return ;
	prev = NULL;
	last = checker->stack_b;
	while (last->next != NULL)
	{
		prev = last;
		last = last->next;
	}
	prev->next = NULL;
	last->next = checker->stack_b;
	checker->stack_b = last;
}

void	revrotate_ab_bonus(t_checker *checker)
{
	revrotate_a_bonus(checker);
	revrotate_b_bonus(checker);
}
