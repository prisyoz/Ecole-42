/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pang <pang@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 20:25:01 by pang              #+#    #+#             */
/*   Updated: 2025/11/20 20:41:48 by pang             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	dining(t_philo *philo, t_program *prog)
{
	int	left_fork;
	int	right_fork;

	if (check_simulation_ended(prog))
		return ;
	acquire_forks(philo, prog, &left_fork, &right_fork);
	release_fork(prog, left_fork);
	release_fork(prog, right_fork);
	if (check_simulation_ended(prog))
	{
		unlock_all_forks(philo);
		return ;
	}
	eat(philo, prog);
	unlock_all_forks(philo);
}

static void	routine_loop(t_philo *philo)
{
	int		ended;

	while (1)
	{
		pthread_mutex_lock(philo->prog->death_mutex);
		ended = philo->prog->simulation_ended;
		pthread_mutex_unlock(philo->prog->death_mutex);
		if (ended)
			break ;
		dining(philo, philo->prog);
		if (check_simulation_ended(philo->prog))
			break ;
		log_state(philo->prog, philo->id, "is sleeping");
		usleep(philo->prog->time_to_sleep * 1000);
		if (check_simulation_ended(philo->prog))
			break ;
		log_state(philo->prog, philo->id, "is thinking");
		usleep(philo->prog->time_to_think);
	}
}

void	*routine(void *arg)
{
	t_philo	*philo;

	philo = (void *)arg;
	if (philo->prog->num_of_philo == 1)
	{
		single_philo(philo);
		return (NULL);
	}
	if (philo->id % 2 == 0)
		usleep(5000);
	routine_loop(philo);
	return (NULL);
}

int	single_philo(t_philo *philo)
{
	pthread_mutex_lock(philo->left_fork);
	log_state(philo->prog, philo->id, "has taken a fork");
	while (!check_simulation_ended(philo->prog))
		usleep(1000);
	pthread_mutex_unlock(philo->left_fork);
	return (0);
}
