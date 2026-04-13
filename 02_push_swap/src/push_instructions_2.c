#include "push_swap.h"

// last element becomes first one
void	revrotate_a_clean(t_struct *data)
{
	t_node	*prev;
	t_node	*last;

	if (!data->stack_a || !(data->stack_a)->next)
		return ;
	prev = NULL;
	last = data->stack_a;
	while (last->next != NULL)
	{
		prev = last;
		last = last->next;
	}
	prev->next = NULL;
	last->next = data->stack_a;
	data->stack_a = last;
}

void	revrotate_b_clean(t_struct *data)
{
	t_node	*prev;
	t_node	*last;

	if (!data->stack_b || !data->stack_b || !data->stack_b->next)
		return ;
	prev = NULL;
	last = data->stack_b;
	while (last->next != NULL)
	{
		prev = last;
		last = last->next;
	}
	prev->next = NULL;
	last->next = data->stack_b;
	data->stack_b = last;
}

void	revrotate_ab(t_struct *data)
{
	revrotate_a_clean(data);
	revrotate_b_clean(data);
	data->ins_count++;
	write(1, "rrr\n", 4);
}
