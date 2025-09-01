/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmolina <<hmolina@student.42.fr>>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 13:08:27 by hmolina           #+#    #+#             */
/*   Updated: 2025/09/01 23:33:54 by hmolina          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_position(t_node *node, int value)
{
	int	pos;

	pos = 0;
	while (node)
	{
		if (node->value == value)
			return (pos);
		node = node->next;
		pos++;
	}
	return (1);
}

int	get_min_num(t_node *node)
{
	int	min;

	min = node->value;
	while (node)
	{
		if (node->value < min)
			min = node->value;
		node = node->next;
	}
	return (min);
}

int	get_max_num(t_node *stack)
{
	int	max;

	max = stack->value;
	while (stack)
	{
		if (stack->value > max)
			max = stack->value;
		stack = stack->next;
	}
	return (max);
}

int	get_max_bits(int max_num)
{
	int	bits;

	bits = 0;
	while ((max_num >> bits) != 0)
		bits++;
	return (bits);
}

void	normalize_stack(t_node *stack)
{
	t_node	*actual;
	t_node	*compare;
	int		rank;

	actual = stack;
	while (actual)
	{
		rank = 0;
		compare = stack;
		while (compare)
		{
			if (compare->value < actual->value)
				rank++;
			compare = compare->next;
		}
		actual->index = rank;
		actual = actual->next;
	}
}
