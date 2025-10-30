/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_bonus_main_helper.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pang <pang@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 17:57:37 by pang              #+#    #+#             */
/*   Updated: 2025/09/12 16:48:00 by pang             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	split_argument(int argc, char **argv, t_checker *checker)
{
	int	count;

	count = 0;
	while (count < argc)
	{
		if (argv[count][0] == '\0')
			free_error_exit(checker);
		count++;
	}
	if (argc == 2)
	{
		checker->char_arr = ft_split(argv[1], ' ');
		if (!checker->char_arr || !*checker->char_arr)
			free_error_exit(checker);
	}
	else
	{
		checker->combined_str = argument_to_array(argc, argv);
		if (!checker->combined_str)
			free_error_exit(checker);
		checker->char_arr = ft_split(checker->combined_str, ' ');
		if (!checker->char_arr || !*checker->char_arr)
			free_error_exit(checker);
	}
}
