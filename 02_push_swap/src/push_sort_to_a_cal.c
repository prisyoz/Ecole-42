#include "push_swap.h"

void	moves_rotate_a(t_struct *data, t_node *target_node)
{
	int	position;

	position = find_safe_insertion_position(data, target_node->sorted_index);
	if (position > data->size_a)
		position = data->size_a;
	if (position <= data->size_a / 2)
	{
		target_node->cost_a = position;
		target_node->dir_a = 1;
	}
	else
	{
		target_node->cost_a = data->size_a - position;
		target_node->dir_a = -1;
	}
}

int	outside_bound_position(t_struct *data)
{
	t_node	*curr;
	int		pos;

	pos = 0;
	curr = data->stack_a;
	while (curr)
	{
		if (curr->sorted_index == data->lis_min_a)
			return (pos);
		curr = curr->next;
		pos++;
	}
	return (0);
}

int	find_safe_insertion_position(t_struct *data, int sorted_index)
{
	t_node	*curr;
	int		pos;

	pos = 0;
	if (!data || !data->stack_a)
		return (0);
	curr = data->stack_a;
	if (sorted_index < data->lis_min_a || sorted_index > data->lis_max_a)
	{
		pos = outside_bound_position(data);
		return (pos);
	}
	curr = data->stack_a;
	pos = 0;
	while (curr->next)
	{
		if (curr->sorted_index < sorted_index
			&& sorted_index < curr->next->sorted_index)
			return (pos + 1);
		curr = curr->next;
		pos++;
	}
	return (0);
}
