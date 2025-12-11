/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmolina <<hmolina@student.42.fr>>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 17:59:54 by hmolina           #+#    #+#             */
/*   Updated: 2025/12/07 18:36:38 by hmolina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	validate_args(int ac, char **av)
{
	int		i;
	long	value;

	i = 1;
	if (ac != 5 && ac != 6)
	{
		printf("Error: Invalid number of arguments\n");
		return (-1);
	}
	while (i < ac)
	{
		value = ft_atol(av[i]);
		if (ft_is_number(av[i]) == -1 || value <= 0 || value > 2147483647)
		{
			printf("Error: Invalid arguments\n");
			return (-1);
		}
		i++;
	}
	return (0);
}

int	run_simulation(t_data *data)
{
	int	i;

	data->start_time = get_time();
	if (data->num_philo == 1)
	{
		print_status(&data->philos[0], "has taken a fork");
		precise_sleep(data->time_2_die);
		print_status(&data->philos[0], "died");
		return (0);
	}
	i = 0;
	while (i < data->num_philo)
	{
		data->philos[i].last_meal_time = data->start_time;
		i++;
	}
	i = 0;
	while (i < data->num_philo)
	{
		if (pthread_create(&data->philos[i].thread, NULL, philo_routine,
				&data->philos[i]) != 0)
			return (-1);
		i++;
	}
	return (run_simulation_2(data));
}

int	run_simulation_2(t_data *data)
{
	int			i;
	pthread_t	monitor_thread;

	i = 0;
	if (pthread_create(&monitor_thread, NULL, monitor, data) != 0)
		return (-1);
	pthread_join(monitor_thread, NULL);
	while (i < data->num_philo)
	{
		pthread_join(data->philos[i].thread, NULL);
		i++;
	}
	return (0);
}

int	main(int ac, char **av)
{
	t_data	data;

	if (validate_args(ac, av) == -1)
		return (1);
	if (inicialize_init(&data, av) == -1)
		return (1);
	if (run_simulation(&data) == -1)
	{
		printf("Error: Simulation failed\n");
		cleanup(&data);
		return (1);
	}
	cleanup(&data);
	return (0);
}
