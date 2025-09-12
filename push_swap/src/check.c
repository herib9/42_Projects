/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmolina <<hmolina@student.42.fr>>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/06 00:17:47 by hmolina           #+#    #+#             */
/*   Updated: 2025/09/11 22:52:47 by hmolina          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//verify int limits
int	check_overflow(char *s)
{
	long	num;

	num = ft_atol(s);
	if (num < INT_MIN || num > INT_MAX)
		return (0);
	return (1);
}
//check that there are no duplicate numbers
//atol convert string to int & verify if same
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

int	check_duplicates_simple(int count, char **args)
{
	int	i;
	int	j;

	i = 0;
	while (i < count - 1)
	{
		j = i + 1;
		while (j < count - 1)
		{
			if (ft_atol(args[i]) == ft_atol(args[j]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	check_duplicates_split(char **args)
{
	int	i;
	int	j;

	i = 0;
	while (args[i])
	{
		j = i + 1;
		while (args[j])
		{
			if (ft_atol(args[i]) == ft_atol(args[j]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	get_stack_size(t_node *stack)
{
	t_node	*current;
	int		size;

	if (!stack)
		return (0);
	size = 1;
	current = stack->next;
	while (current)
	{
		size++;
		current = current->next;
	}
	return (size);
}
