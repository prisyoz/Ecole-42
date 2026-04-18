/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_ticket.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pang <pang@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 21:12:41 by pang              #+#    #+#             */
/*   Updated: 2025/11/20 19:33:29 by pang             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ticket_queue(t_program *prog, int fork_count)
{
	int	ticket;

	pthread_mutex_lock(&prog->ticket_mutex[fork_count]);
	ticket = prog->next_ticket[fork_count];
	prog->next_ticket[fork_count]++;
	pthread_mutex_unlock(&prog->ticket_mutex[fork_count]);
	return (ticket);
}

void	wait_for_turn(t_program *prog, int fork_count, int ticket)
{
	while (1)
	{
		pthread_mutex_lock(&prog->ticket_mutex[fork_count]);
		if (prog->now_serving[fork_count] == ticket)
		{
			pthread_mutex_unlock(&prog->ticket_mutex[fork_count]);
			return ;
		}
		pthread_mutex_unlock(&prog->ticket_mutex[fork_count]);
		usleep(200);
	}
}

void	release_fork(t_program *prog, int fork_count)
{
	pthread_mutex_lock(&prog->ticket_mutex[fork_count]);
	prog->now_serving[fork_count]++;
	pthread_mutex_unlock(&prog->ticket_mutex[fork_count]);
}
