/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   val_args.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmolina <<hmolina@student.42.fr>>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 19:03:36 by hmolina           #+#    #+#             */
/*   Updated: 2025/09/02 22:52:32 by hmolina          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	val_numb(char *s)
{
	int	i;

	i = 0;
	if (s[i] == '+' || s[i] == '-')
		i++;
	if (!s[i])
		return (0);
	while (s[i])
	{
		if (!ft_isdigit(s[i]))
			return (0);
		i++;
	}
	return (1);
}

int	check_overflow(char *s)
{
	long	num;

	num = ft_atol(s);
	if (num < INT_MIN || num > INT_MAX)
		return (0);
	return (1);
}

int	check_duplicates(int ac, char **av)
{
	int	i;
	int	j;

	i = 1;
	while (i < ac)
	{
		j = i + 1;
		while (j < ac)
		{
			if (ft_atol(av[i]) == ft_atol(av[j]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	val_args(int ac, char **av)
{
	int	i;

	if (ac < 2)
		return (0);
	i = 1;
	while (i < ac)
	{
		if (!val_numb(av[i]))
			return (0);
		if (!check_overflow(av[i]))
			return (0);
		i++;
	}
	if (!check_duplicates(ac, av))
		return (0);
	return (1);
}

int	count_args(char **args)