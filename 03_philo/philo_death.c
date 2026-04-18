/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_death.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pang <pang@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 17:19:25 by pang              #+#    #+#             */
/*   Updated: 2025/11/20 17:11:47 by pang             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*monitor_death(void *arg)
{
	t_program	*prog;

	prog = (t_program *)arg;
	while (1)
	{
		if (check_death_condition(prog))
			return (NULL);
		if (check_simulation_finished(prog))
			return (NULL);
		usleep(1000);
	}
}

int	check_death_condition(t_program *prog)
{
	long	current_time;
	long	meal_diff;
	int		count;

	count = 0;
	while (count < prog->num_of_philo)
	{
		pthread_mutex_lock(prog->death_mutex);
		current_time = get_current_time();
		meal_diff = current_time - prog->philo[count].last_meal_time;
		if (meal_diff > prog->time_to_die)
		{
			prog->simulation_ended = 1;
			pthread_mutex_unlock(prog->death_mutex);
			log_state(prog, prog->philo[count].id, "died");
			return (1);
		}
		pthread_mutex_unlock(prog->death_mutex);
		count++;
	}
	return (0);
}

int	check_simulation_finished(t_program *prog)
{
	if (philo_finished_eating(prog))
	{
		pthread_mutex_lock(prog->death_mutex);
		prog->simulation_ended = 1;
		pthread_mutex_unlock(prog->death_mutex);
		return (1);
	}
	return (0);
}

int	philo_finished_eating(t_program *prog)
{
	int	count;
	int	meals;

	count = 0;
	if (prog->num_of_eattimes == -1)
		return (0);
	while (count < prog->num_of_philo)
	{
		pthread_mutex_lock(prog->death_mutex);
		meals = prog->philo[count].meals_eaten;
		pthread_mutex_unlock(prog->death_mutex);
		if (meals < prog->num_of_eattimes)
			return (0);
		count++;
	}
	return (1);
}

int	check_simulation_ended(t_program *prog)
{
	int	ended;

	pthread_mutex_lock(prog->death_mutex);
	ended = prog->simulation_ended;
	pthread_mutex_unlock(prog->death_mutex);
	return (ended);
}
