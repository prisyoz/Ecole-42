/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_instructions_write.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pang <pang@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 15:01:03 by pang              #+#    #+#             */
/*   Updated: 2025/09/10 14:44:09 by pang             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_a(t_struct *data)
{
	swap_a_clean(data);
	data->ins_count++;
	write(1, "sa\n", 3);
}

void	swap_b(t_struct *data)
{
	swap_b_clean(data);
	data->ins_count++;
	write(1, "sb\n", 3);
}

void	revrotate_b(t_struct *data)
{
	revrotate_b_clean(data);
	data->ins_count++;
	write(1, "rrb\n", 4);
}

void	revrotate_a(t_struct *data)
{
	revrotate_a_clean(data);
	data->ins_count++;
	write(1, "rra\n", 4);
}

void	rotate_a(t_struct *data)
{
	rotate_a_clean(data);
	data->ins_count++;
	write(1, "ra\n", 3);
}
