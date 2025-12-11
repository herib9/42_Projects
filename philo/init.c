/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmolina <<hmolina@student.42.fr>>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 17:59:22 by hmolina           #+#    #+#             */
/*   Updated: 2025/12/07 18:35:37 by hmolina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	init_data(t_data *data, char **av)
{
	data->start_time = 0;
	data->num_philo = ft_atol(av[1]);
	data->time_2_die = ft_atol(av[2]);
	data->time_2_eat = ft_atol(av[3]);
	data->time_2_sleep = ft_atol(av[4]);
	if (data->num_philo < 1 || data->num_philo > 200 || data->time_2_die < 60
		|| data->time_2_eat < 60 || data->time_2_sleep < 60)
		return (-1);
	if (av[5])
	{
		data->must_eat_count = ft_atol(av[5]);
		if (data->must_eat_count < 1)
			return (-1);
	}
	else
		data->must_eat_count = -1;
	data->flag_philo_rip = 0;
	data->flag_all_ate = 0;
	data->forks = NULL;
	data->philos = NULL;
	return (0);
}

int	init_mutex(t_data *data)
{
	int		i;

	data->forks = malloc(sizeof(pthread_mutex_t) * data->num_philo);
	i = 0;
	if (!data->forks)
	{
		printf("Error: Init mutex failed\n");
		return (-1);
	}
	while (i < data->num_philo)
	{
		if (pthread_mutex_init(&data->forks[i], NULL) != 0)
			return (-1);
		i++;
	}
	if (pthread_mutex_init(&data->write_mutex, NULL) != 0
		|| pthread_mutex_init(&data->dead_mutex, NULL) != 0
		|| pthread_mutex_init(&data->meal_mutex, NULL) != 0)
		return (-1);
	return (0);
}

int	init_philos(t_data *data)
{
	int		i;

	data->philos = malloc(sizeof(t_philo) * data->num_philo);
	if (!data->philos)
		return (-1);
	i = 0;
	while (i < data->num_philo)
	{
		data->philos[i].id = i + 1;
		data->philos[i].left_fork = i;
		data->philos[i].right_fork = (i + 1) % data->num_philo;
		data->philos[i].meals_eaten = 0;
		data->philos[i].last_meal_time = 0;
		data->philos[i].data = data;
		data->philos[i].thread = 0;
		i++;
	}
	return (0);
}

void	cleanup(t_data *data)
{
	int	i;

	if (data->forks)
	{
		i = 0;
		while (i < data->num_philo)
		{
			pthread_mutex_destroy(&data->forks[i]);
			i++;
		}
	}
	pthread_mutex_destroy(&data->write_mutex);
	pthread_mutex_destroy(&data->dead_mutex);
	pthread_mutex_destroy(&data->meal_mutex);
	if (data->forks)
		free(data->forks);
	if (data->philos)
		free(data->philos);
}

int	inicialize_init(t_data *data, char **av)
{
	if (init_data(data, av) == -1)
	{
		printf("Error: Init data failed\n");
		return (-1);
	}
	if (init_mutex(data) == -1)
	{
		printf("Error: Init mutex failed\n");
		cleanup(data);
		return (-1);
	}
	if (init_philos(data) == -1)
	{
		printf("Error: Init philos failed\n");
		cleanup(data);
		return (-1);
	}
	return (0);
}
