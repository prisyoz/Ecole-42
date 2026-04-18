/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_time.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pang <pang@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 17:48:44 by pang@studen       #+#    #+#             */
/*   Updated: 2026/01/02 18:48:08 by pang             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long	get_current_time(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return (tv.tv_sec * 1000 + tv.tv_usec / 1000);
}

void	log_state(t_program *prog, int philo_id, char *msg)
{
	long	timestamp;
	int		print;

	pthread_mutex_lock(prog->death_mutex);
	print = !prog->simulation_ended;
	pthread_mutex_unlock(prog->death_mutex);
	if (!print && ft_strcmp(msg, "died") != 0)
		return ;
	pthread_mutex_lock(prog->print_mutex);
	timestamp = get_current_time() - prog->start_time;
	printf("%ld %d %s\n", timestamp, philo_id, msg);
	pthread_mutex_unlock(prog->print_mutex);
	if (ft_strcmp(msg, "died") == 0)
	{
		pthread_mutex_lock(prog->death_mutex);
		prog->simulation_ended = 1;
		pthread_mutex_unlock(prog->death_mutex);
	}
}

void	set_start_time(t_program *prog)
{
	long	start_time;
	int		count;

	start_time = get_current_time();
	count = 0;
	while (count < prog->num_of_philo)
	{
		prog->philo[count].last_meal_time = start_time;
		count++;
	}
	prog->start_time = start_time;
}
