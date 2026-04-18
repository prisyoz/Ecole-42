/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_food.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pang <pang@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 20:41:55 by pang              #+#    #+#             */
/*   Updated: 2025/11/20 21:54:05 by pang             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	acquire_forks(t_philo *philo, t_program *prog,
			int *left_fork, int *right_fork)
{
	int	ticket_left;
	int	ticket_right;

	*left_fork = philo->id;
	*right_fork = (philo->id + 1) % prog->num_of_philo;
	ticket_left = ticket_queue(prog, *left_fork);
	ticket_right = ticket_queue(prog, *right_fork);
	wait_for_turn(prog, *left_fork, ticket_left);
	wait_for_turn(prog, *right_fork, ticket_right);
	if (philo->id % 2 == 0)
		lock_even_forks(philo);
	else
		lock_odd_forks(philo);
}

void	eat(t_philo *philo, t_program *prog)
{
	pthread_mutex_lock(prog->death_mutex);
	philo->last_meal_time = get_current_time();
	pthread_mutex_unlock(prog->death_mutex);
	log_state(prog, philo->id, "is eating");
	usleep(prog->time_to_eat * 1000);
	pthread_mutex_lock(prog->death_mutex);
	philo->meals_eaten += 1;
	pthread_mutex_unlock(prog->death_mutex);
}
