/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmolina <<hmolina@student.42.fr>>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 18:01:19 by hmolina           #+#    #+#             */
/*   Updated: 2025/12/06 18:37:59 by hmolina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <limits.h>
# include <pthread.h>
# include <sys/time.h>

typedef struct s_philo
{
	int				id;
	int				num_philo;
	int				left_fork;
	int				right_fork;
	int				last_food;
	int				meals_eaten;
	long			last_meal_time;
	pthread_t		thread;
	struct s_data	*data;
}	t_philo;

typedef struct s_data
{
	int				num_philo;
	long			start_time;
	long			time_2_die;
	long			time_2_eat;
	long			time_2_sleep;
	t_philo			*philos;
	pthread_mutex_t	*forks;
	pthread_mutex_t	write_mutex;
	pthread_mutex_t	dead_mutex;
	pthread_mutex_t	meal_mutex;
	int				must_eat_count;
	int				flag_all_ate;
	int				flag_philo_rip;
}	t_data;

//	=== MAIN FUNCTIONS ===
//int		main(int ac, char **av);
int			validate_args(int ac, char **av);
int			run_simulation(t_data *data);
int			run_simulation_2(t_data *data);

//	=== UTILS FUNCTIONS ===
int			ft_is_number(char *s);
long		ft_atol(char *s);
long		get_time(void);
void		precise_sleep(long ms);

// === INIT FUNCTIONS ===
int			init_data(t_data *data, char **av);
int			init_mutex(t_data *data);
int			init_philos(t_data *data);
void		cleanup(t_data *data);
int			inicialize_init(t_data *data, char **av);

// === PRINT_STATUS FUNCTION ===
void		print_status(t_philo *philo, char *status);

// === THREADS ROUTINE FUNCTIONS ===
void		take_forks(t_philo *philo);
void		philo_eat(t_philo *philo);
void		philo_sleep(t_philo *philo);
void		philo_think(t_philo *philo);
void		*philo_routine(void *arg);

// === THREADS MONITOR FUNCTIONS ===
int			check_death_philo(t_philo *philo);
int			check_all_ate(t_data *data);
void		*monitor(void *arg);

#endif