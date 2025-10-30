/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_create_nodes.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pang <pang@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 14:38:46 by pang              #+#    #+#             */
/*   Updated: 2025/09/10 20:29:07 by pang             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*ft_lstnew_node(int value)
{
	t_node	*new_node;

	new_node = malloc(sizeof(t_node));
	if (!new_node)
		return (NULL);
	ft_memset(new_node, 0, sizeof(t_node));
	new_node->value = value;
	new_node->next = NULL;
	return (new_node);
}

void	ft_lstadd_back_node(t_node **lst, t_node *new_node)
{
	t_node	*curr;

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

void	parse_stack_a(t_struct *data)
{
	t_node	*new_node;
	int		count;

	count = 0;
	while (count < data->arr_size)
	{
		new_node = ft_lstnew_node(data->int_arr[count]);
		if (!new_node)
			free_exit(data);
		new_node->ori_index = count;
		ft_lstadd_back_node(&data->stack_a, new_node);
		count++;
	}
}
