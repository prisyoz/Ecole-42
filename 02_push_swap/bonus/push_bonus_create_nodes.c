#include "push_swap_bonus.h"

t_bonus_node	*ft_lstnew_node(int value)
{
	t_bonus_node	*new_node;

	new_node = malloc(sizeof(t_bonus_node));
	if (!new_node)
		return (NULL);
	ft_memset(new_node, 0, sizeof(t_bonus_node));
	new_node->value = value;
	new_node->next = NULL;
	return (new_node);
}

void	ft_lstadd_back_node(t_bonus_node **lst, t_bonus_node *new_node)
{
	t_bonus_node	*curr;

	if (!lst || !new_node)
		return ;
	if (*lst == NULL)
	{
		*lst = new_node;
		return ;
	}
	curr = *lst;
	while (curr->next)
		curr = curr->next;
	curr->next = new_node;
}

void	parse_stack_a(t_checker *checker)
{
	t_bonus_node	*new_node;
	int				count;

	count = 0;
	while (count < checker->arr_size)
	{
		new_node = ft_lstnew_node(checker->int_arr[count]);
		if (!new_node)
			free_exit(checker);
		ft_lstadd_back_node(&checker->stack_a, new_node);
		count++;
	}
}
