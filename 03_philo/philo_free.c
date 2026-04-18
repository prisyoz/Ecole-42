/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_free.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pang <pang@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 19:14:44 by pang              #+#    #+#             */
/*   Updated: 2025/11/20 19:53:13 by pang             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	free_all(t_program *prog)
{
	if (prog->thread)
		free(prog->thread);
	if (prog->philo)
		free(prog->philo);
	if (prog->fork != NULL)
		destroy_fork(prog);
	if (prog->print_mutex)
	{
		pthread_mutex_destroy(prog->print_mutex);
		free(prog->print_mutex);
	}
	if (prog->death_mutex)
	{
		pthread_mutex_destroy(prog->death_mutex);
		free(prog->death_mutex);
	}
	if (prog->ticket_mutex)
		destroy_ticket(prog);
}

void	destroy_fork(t_program *prog)
{
	int	count;

	count = 0;
	while (count < prog->num_of_philo)
	{
		pthread_mutex_destroy(&prog->fork[count]);
		count++;
	}
	free(prog->fork);
}

void	destroy_ticket(t_program *prog)
{
	int	i;

	i = 0;
	while (i < prog->num_of_philo)
	{
		pthread_mutex_destroy(&prog->ticket_mutex[i]);
		i++;
	}
	free(prog->ticket_mutex);
	free(prog->now_serving);
	free(prog->next_ticket);
}

int	join_thread(t_program *prog)
{
	int	count;

	count = 0;
	while (count < prog->num_of_philo)
	{
		if (pthread_join(prog->thread[count], NULL) != 0)
			return (1);
		count++;
	}
	return (0);
}
