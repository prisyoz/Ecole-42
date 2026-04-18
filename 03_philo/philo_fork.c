/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_fork.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pang <pang@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 18:10:51 by pang              #+#    #+#             */
/*   Updated: 2025/11/16 23:58:55 by pang             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	unlock_all_forks(t_philo *philo)
{
	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);
}

void	lock_even_forks(t_philo *philo)
{
	pthread_mutex_lock(philo->right_fork);
	log_state(philo->prog, philo->id, "has taken a fork");
	pthread_mutex_lock(philo->left_fork);
	log_state(philo->prog, philo->id, "has taken a fork");
}

void	lock_odd_forks(t_philo *philo)
{
	pthread_mutex_lock(philo->left_fork);
	log_state(philo->prog, philo->id, "has taken a fork");
	pthread_mutex_lock(philo->right_fork);
	log_state(philo->prog, philo->id, "has taken a fork");
}
