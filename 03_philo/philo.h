/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pang <pang@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/26 20:19:43 by pang              #+#    #+#             */
/*   Updated: 2025/11/27 15:24:33 by pang             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <string.h>
# include <stdio.h>
# include <sys/time.h>
# include <stdlib.h>
# include <pthread.h>

typedef struct s_program	t_program;

typedef struct s_philo
{
	int				id;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
	int				meals_eaten;
	long			last_meal_time;
	int				ticket_queue;
	t_program		*prog;
}	t_philo;

typedef struct s_program
{
	t_philo			*philo;
	int				num_of_philo;
	long			time_to_die;
	long			time_to_eat;
	long			time_to_sleep;
	long			time_to_think;
	int				num_of_eattimes;
	pthread_t		*thread;	
	pthread_mutex_t	*fork;
	pthread_mutex_t	*print_mutex;
	pthread_mutex_t	*death_mutex;
	pthread_mutex_t	*ticket_mutex;
	pthread_mutex_t	*meal_mutex;
	int				*next_ticket;
	int				*now_serving;
	int				simulation_ended;
	long			start_time;
}	t_program;

// helper functions
int		ft_atoi(const char *str);
int		ft_strcmp(const char *s1, const char *s2);
void	free_all(t_program *prog);
void	destroy_fork(t_program *prog);
long	get_current_time(void);
void	log_state(t_program *prog, int philo_id, char *msg);
void	set_start_time(t_program *prog);

int		parse_command(int argc, char **argv, t_program *philo);
int		valid_number(char *arr);
int		single_philo(t_philo *philo);
int		init_setup(t_program *prog);
int		thread_setup(t_program *prog);

int		init_prog(t_program *prog);
int		init_fork(t_program *prog);
int		init_philo(t_program *prog);
int		init_thread(t_program *prog);
int		init_other_mutex(t_program *prog);
int		join_thread(t_program *prog);

int		ticket_queue(t_program *prog, int fork_count);
void	wait_for_turn(t_program *prog, int fork_count, int ticket);
void	release_fork(t_program *prog, int fork_count);
void	destroy_ticket(t_program *prog);

void	*routine(void *arg);
void	dining(t_philo *philo, t_program *prog);
void	eat(t_philo *philo, t_program *prog);
void	acquire_forks(t_philo *philo, t_program *prog,
			int *left_fork, int *right_fork);
void	*monitor_death(void *arg);
int		check_death_condition(t_program *prog);
int		check_simulation_finished(t_program *prog);
int		philo_finished_eating(t_program *prog);
int		check_simulation_ended(t_program *prog);
void	unlock_all_forks(t_philo *philo);
void	lock_even_forks(t_philo *philo);
void	lock_odd_forks(t_philo *philo);

#endif