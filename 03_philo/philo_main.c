/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pang <pang@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/26 20:19:33 by pang              #+#    #+#             */
/*   Updated: 2025/11/20 19:57:03 by pang             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_program	prog;
	pthread_t	death_thread;

	if (argc < 5 || argc > 6)
	{
		printf("Invalid arguments\n");
		return (1);
	}
	memset(&prog, 0, sizeof(t_program));
	if (parse_command(argc, argv, &prog) != 0)
		return (1);
	if (prog.num_of_philo == 0 || prog.num_of_eattimes == 0)
		return (0);
	init_setup(&prog);
	prog.simulation_ended = 0;
	pthread_create(&death_thread, NULL, &monitor_death, &prog);
	thread_setup(&prog);
	join_thread(&prog);
	pthread_join(death_thread, NULL);
	free_all(&prog);
	return (0);
}

int	init_setup(t_program *prog)
{
	if (init_fork(prog))
	{
		free_all(prog);
		return (1);
	}
	if (init_prog(prog))
	{
		free_all(prog);
		return (1);
	}
	if (init_other_mutex(prog))
	{
		free_all(prog);
		return (1);
	}
	if (init_philo(prog))
	{
		free_all(prog);
		return (1);
	}
	set_start_time(prog);
	return (0);
}

int	thread_setup(t_program *prog)
{
	if (init_thread(prog))
	{
		free_all(prog);
		printf("Error init thread\n");
		return (1);
	}
	return (0);
}
