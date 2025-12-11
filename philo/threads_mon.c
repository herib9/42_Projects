/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads_mon.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmolina <<hmolina@student.42.fr>>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 18:55:13 by hmolina           #+#    #+#             */
/*   Updated: 2025/12/06 20:21:05 by hmolina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_death_philo(t_philo *philo)
{
	long	time_since_eat;
	long	timestamp;

	pthread_mutex_lock(&philo->data->meal_mutex);
	time_since_eat = get_time() - philo->last_meal_time;
	pthread_mutex_unlock(&philo->data->meal_mutex);
	if (time_since_eat >= philo->data->time_2_die)
	{
		pthread_mutex_lock(&philo->data->dead_mutex);
		philo->data->flag_philo_rip = 1;
		pthread_mutex_unlock(&philo->data->dead_mutex);
		pthread_mutex_lock(&philo->data->write_mutex);
		timestamp = get_time() - philo->data->start_time;
		printf("%ld %d died\n", timestamp, philo->id);
		pthread_mutex_unlock(&philo->data->write_mutex);
		return (1);
	}
	return (0);
}

int	check_all_ate(t_data *data)
{
	int	i;
	int	all_finish;

	all_finish = 1;
	i = 0;
	if (data->must_eat_count == -1)
		return (0);
	pthread_mutex_lock(&data->meal_mutex);
	while (i < data->num_philo)
	{
		if (data->philos[i].meals_eaten < data->must_eat_count)
			all_finish = 0;
		i++;
	}
	pthread_mutex_unlock(&data->meal_mutex);
	if (all_finish)
	{
		pthread_mutex_lock(&data->dead_mutex);
		data->flag_philo_rip = 1;
		pthread_mutex_unlock(&data->dead_mutex);
		return (1);
	}
	return (0);
}

void	*monitor(void *arg)
{
	t_data	*data;
	int		i;

	data = (t_data *)arg;
	while (1)
	{
		i = 0;
		while (i < data->num_philo)
		{
			if (check_death_philo(&data->philos[i]))
				return (NULL);
			i++;
		}
		if (check_all_ate(data))
			return (NULL);
		usleep(1000);
	}
	return (NULL);
}
