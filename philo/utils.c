/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmolina <<hmolina@student.42.fr>>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/18 18:00:09 by hmolina           #+#    #+#             */
/*   Updated: 2025/12/07 18:51:22 by hmolina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_is_number(char *s)
{
	int	i;

	i = 0;
	while (s[i] == ' ' || s[i] == '\t')
		i++;
	if (s[i] == '+')
		i++;
	if (!s[i])
		return (-1);
	if (s[i] == '-')
		return (-1);
	while (s[i])
	{
		if (s[i] < '0' || s[i] > '9')
			return (-1);
		i++;
	}
	return (0);
}

long	ft_atol(char *s)
{
	long	num;
	int		i;

	num = 0;
	i = 0;
	while ((s[i] >= 9 && s[i] <= 13) || (s[i] == ' '))
		i++;
	if (s[i] == '+')
		i++;
	while (s[i] >= '0' && s[i] <= '9')
	{
		if (num > (LONG_MAX - (s[i] - '0')) / 10)
			return (-1);
		num = num * 10 + (s[i] - '0');
		i++;
	}
	return (num);
}

long	get_time(void)
{
	struct timeval	tv;

	if (gettimeofday(&tv, NULL) == -1)
		return (-1);
	return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}

void	precise_sleep(long ms)
{
	long	start;
	long	actual;

	start = get_time();
	while (1)
	{
		actual = get_time();
		if ((actual - start) >= ms)
			break ;
		usleep(100);
	}
}
