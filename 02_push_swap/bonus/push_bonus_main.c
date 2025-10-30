/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_bonus_main.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pang <pang@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 19:24:03 by pang              #+#    #+#             */
/*   Updated: 2025/09/14 11:56:33 by pang             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	verify_stack_order(t_checker *checker)
{
	t_bonus_node	*curr;
	t_bonus_node	*next;

	curr = checker->stack_a;
	next = checker->stack_a->next;
	if (!checker->stack_a || !checker->stack_a->next)
		return (0);
	while (next)
	{
		if (curr->value >= next->value)
			return (1);
		curr = next;
		next = curr->next;
	}
	return (0);
}

int	stack_b_stack(t_checker *checker)
{
	t_bonus_node	*curr;

	curr = checker->stack_b;
	if (!curr)
		return (0);
	else
		return (1);
}

void	print_stack(t_bonus_node *stack, const char *name)
{
	printf("%s:\n", name);
	while (stack)
	{
		printf("  %d\n", stack->value);
		stack = stack->next;
	}
	printf("\n");
}

int	main(int argc, char **argv)
{
	t_checker	checker;

	ft_bzero(&checker, sizeof(t_checker));
	if (argc <= 1)
		return (1);
	split_argument(argc, argv, &checker);
	checker.arr_size = count_array(checker.char_arr);
	if (!checker.arr_size)
		free_error_exit(&checker);
	checker.int_arr = validate_and_convert(&checker);
	if (!checker.int_arr)
		free_error_exit(&checker);
	parse_stack_a(&checker);
	read_stdin(&checker);
	if (verify_stack_order(&checker) == 0 && stack_b_stack(&checker) == 0)
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	free_exit(&checker);
	return (0);
}
