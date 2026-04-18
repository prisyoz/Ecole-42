/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pang <pang@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 15:16:27 by pang              #+#    #+#             */
/*   Updated: 2025/11/20 19:49:02 by pang             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	init_fork(t_program *prog)
{
	int	count;

	count = 0;
	prog->fork = malloc(sizeof(pthread_mutex_t) * prog->num_of_philo);
	if (!prog->fork)
		return (1);
	while (count < prog->num_of_philo)
	{
		if (pthread_mutex_init(&prog->fork[count], NULL) != 0)
			return (1);
		count++;
	}
	return (0);
}

int	init_philo(t_program *prog)
{
	int	count;

	count = 0;
	prog->philo = malloc(sizeof(t_philo) * prog->num_of_philo);
	if (!prog->philo)
		return (1);
	while (count < prog->num_of_philo)
	{
		prog->philo[count].id = count;
		prog->philo[count].left_fork = &prog->fork[count];
		prog->philo[count].right_fork = &prog->fork[(count + 1)
			% prog->num_of_philo];
		prog->philo[count].meals_eaten = 0;
		prog->philo[count].last_meal_time = 0;
		prog->philo[count].ticket_queue = -1;
		prog->philo[count].prog = prog;
		count++;
	}
	return (0);
}

int	init_thread(t_program *prog)
{
	int	count;

	count = 0;
	prog->thread = malloc(sizeof(pthread_t) * prog->num_of_philo);
	if (!prog->thread)
		return (1);
	while (count < prog->num_of_philo)
	{
		if (pthread_create(&prog->thread[count], NULL,
				routine, &prog->philo[count]) != 0)
			return (1);
		count++;
	}
	return (0);
}

int	init_other_mutex(t_program *prog)
{
	prog->print_mutex = malloc(sizeof(pthread_mutex_t));
	if (!prog->print_mutex)
		return (1);
	if (pthread_mutex_init(prog->print_mutex, NULL) != 0)
		return (1);
	prog->death_mutex = malloc(sizeof(pthread_mutex_t));
	if (!prog->death_mutex)
		return (1);
	if (pthread_mutex_init(prog->death_mutex, NULL) != 0)
		return (1);
	return (0);
}

int	init_prog(t_program *prog)
{
	int	i;

	i = 0;
	prog->next_ticket = malloc(sizeof(int) * prog->num_of_philo);
	prog->now_serving = malloc(sizeof(int) * prog->num_of_philo);
	prog->ticket_mutex = malloc(sizeof(pthread_mutex_t) * prog->num_of_philo);
	if (!prog->next_ticket || !prog->now_serving || !prog->ticket_mutex)
		return (1);
	while (i < prog->num_of_philo)
	{
		prog->next_ticket[i] = 0;
		prog->now_serving[i] = 0;
		pthread_mutex_init(&prog->ticket_mutex[i], NULL);
		i++;
	}
	return (0);
}
