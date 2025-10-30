/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pang <pang@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 16:53:40 by pang              #+#    #+#             */
/*   Updated: 2025/09/13 23:32:09 by pang             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	data_sort(t_struct *data)
{
	if (data->arr_size == 2)
		sort_two(data);
	else if (data->arr_size == 3)
		sort_three(data);
	else if (data->arr_size > 3 && data->arr_size <= 5)
		sort_five(data);
	else
		sort_data(data);
}

int	main(int argc, char **argv)
{
	t_struct	data;

	ft_bzero(&data, sizeof(t_struct));
	if (argc <= 1)
		return (1);
	split_argument(argc, argv, &data);
	data.arr_size = data_size(&data);
	data.int_arr = validate_and_convert(&data);
	data.size_a = data.arr_size;
	if (data.arr_size == 1)
	{
		free_exit(&data);
		return (0);
	}
	if (!data.int_arr)
		free_errorexit(&data);
	parse_stack_a(&data);
	if (verify_stack_order(&data) == 0)
	{
		free_exit(&data);
		return (0);
	}
	data_sort(&data);
	free_exit(&data);
	return (0);
}
