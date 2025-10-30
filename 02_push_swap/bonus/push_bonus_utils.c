/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_bonus_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pang <pang@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 11:31:29 by pang              #+#    #+#             */
/*   Updated: 2025/09/14 11:48:45 by pang             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	free_array_b(char **arr)
{
	int	i;

	i = 0;
	if (!arr)
		return ;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

void	free_stack(t_bonus_node *stack)
{
	t_bonus_node	*temp;

	while (stack)
	{
		temp = stack->next;
		free(stack);
		stack = temp;
	}
}

void	free_exit(t_checker *checker)
{
	if (checker->char_arr)
		free_array_b(checker->char_arr);
	if (checker->combined_str)
		free(checker->combined_str);
	if (checker->int_arr)
		free(checker->int_arr);
	if (checker->stack_a)
		free_stack(checker->stack_a);
	if (checker->stack_b)
		free_stack(checker->stack_b);
}

void	free_error_exit(t_checker *checker)
{
	free_exit(checker);
	write(2, "Error\n", 6);
	exit(1);
}

int	count_array(char **arr)
{
	int	count;

	count = 0;
	while (arr[count])
		count++;
	return (count);
}
