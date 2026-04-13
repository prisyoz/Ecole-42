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
