/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   val_args.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmolina <<hmolina@student.42.fr>>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 19:03:36 by hmolina           #+#    #+#             */
/*   Updated: 2025/09/11 22:56:11 by hmolina          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//validate that is a number
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
//Verify that there are arguments
//Verify that each one is a valid number
//Verify that none are outside the limits
//Verify that there are no duplicates
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

int	val_args_split(char **args)
{
	int	i;

	if (!args || !args[0])
		return (0);
	i = 0;
	while (args[i])
	{
		if (!val_numb(args[i]) || !check_overflow(args[i]))
			return (0);
		i++;
	}
	return (check_duplicates_split(args));
}

void	free_args(char **args)
{
	int	i;

	i = 0;
	if (!args)
		return ;
	while (args[i])
	{
		free (args[i]);
		i++;
	}
	free(args);
}
