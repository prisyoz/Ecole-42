/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_parse.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pang <pang@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/27 18:24:13 by pang              #+#    #+#             */
/*   Updated: 2025/11/20 19:39:46 by pang             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	valid_number(char *arr)
{
	int	count;

	count = 0;
	if (arr[count] == '+')
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

int	parse_command(int argc, char **argv, t_program *prog)
{
	int	count;

	count = 1;
	while (count < argc)
	{
		if (!(valid_number(argv[count])))
		{
			printf("Invalid parse\n");
			return (1);
		}
		count++;
	}
	prog->num_of_philo = ft_atoi(argv[1]);
	prog->time_to_die = ft_atoi(argv[2]);
	prog->time_to_eat = ft_atoi(argv[3]);
	prog->time_to_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		prog->num_of_eattimes = ft_atoi(argv[5]);
	else
		prog->num_of_eattimes = -1;
	prog->time_to_think = prog->time_to_die
		- prog->time_to_eat - prog->time_to_sleep;
	return (0);
}
