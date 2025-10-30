/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_main_helper.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pang <pang@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 17:57:37 by pang              #+#    #+#             */
/*   Updated: 2025/09/13 23:10:01 by pang             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	split_argument(int argc, char **argv, t_struct *data)
{
	int	count;

	count = 0;
	while (count < argc)
	{
		if (argv[count][0] == '\0')
			free_errorexit(data);
		count++;
	}
	if (argc == 2)
	{
		data->char_arr = ft_split(argv[1], ' ');
		if (!data->char_arr || !*data->char_arr)
			free_errorexit(data);
	}
	else
	{
		data->combined_str = argument_to_array(argc, argv);
		if (!data->combined_str)
			free_errorexit(data);
		data->char_arr = ft_split(data->combined_str, ' ');
		if (!data->char_arr || !*data->char_arr)
			free_errorexit(data);
	}
}

int	verify_stack_order(t_struct *data)
{
	t_node	*curr;
	t_node	*next;

	if (!data->stack_a || !data->stack_a->next)
		return (1);
	curr = data->stack_a;
	next = data->stack_a->next;
	while (next)
	{
		if (curr->value >= next->value)
			return (1);
		curr = next;
		next = curr->next;
	}
	return (0);
}
