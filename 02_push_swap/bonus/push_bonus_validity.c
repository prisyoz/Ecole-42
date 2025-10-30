/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_bonus_validity.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pang <pang@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 15:03:47 by pang              #+#    #+#             */
/*   Updated: 2025/09/12 18:44:22 by pang             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

// check for valid number
int	valid_number(char *arr)
{
	int	count;

	count = 0;
	if (arr[count] == '-' || arr[count] == '+')
		count++;
	if (arr[count] == '\0')
		return (0);
	while (arr[count] != '\0')
	{
		if (arr[count] >= '0' && arr[count] <= '9')
			count++;
		else
			return (0);
	}
	return (1);
}

int	check_dup(char **arr)
{
	int		count;
	int		dupcount;
	long	no1;
	long	no2;

	count = 0;
	while (arr[count])
	{
		dupcount = count + 1;
		while (arr[dupcount])
		{
			no1 = ft_atol(arr[count]);
			no2 = ft_atol(arr[dupcount]);
			if (no1 == no2)
				return (0);
			dupcount++;
		}
		count++;
	}
	return (1);
}

// Check validity and convert to integer
int	check_validity(t_checker *checker)
{
	int		count;
	long	result;

	count = 0;
	while (checker->char_arr[count])
	{
		if (valid_number(checker->char_arr[count]) == 0)
			free_error_exit(checker);
		result = ft_atol(checker->char_arr[count]);
		if (result > 2147483647 || result < -2147483648)
			free_error_exit(checker);
		count++;
	}
	if (check_dup(checker->char_arr) == 0)
		free_error_exit(checker);
	return (1);
}

int	*validate_and_convert(t_checker *checker)
{
	int	count;

	if (!check_validity(checker))
		return (NULL);
	if (checker->arr_size == 0)
		return (NULL);
	checker->int_arr = malloc(sizeof(int) * checker->arr_size);
	if (!checker->int_arr)
		return (NULL);
	count = 0;
	while (checker->char_arr[count])
	{
		checker->int_arr[count] = ft_atol(checker->char_arr[count]);
		count++;
	}
	return (checker->int_arr);
}
