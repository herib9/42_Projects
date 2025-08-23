/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmolina <<hmolina@student.42.fr>>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 19:40:12 by hmolina           #+#    #+#             */
/*   Updated: 2025/08/23 03:21:04 by hmolina          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sort(t_node *node)
{
	while (node && node->next)
	{
		if (node->value > node->next->value)
			return (0);
		node = node->next;
	}
	return (1);
}

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

void	sort_three(t_node **stack_a)
{
	int	min_pos;
	
	if (sort(*stack_a))
		return ;
	min_pos = get_position(*stack_a, get_min_num(*stack_a));
	while (min_pos != 0)
	{
		if (min_pos == 1)
			sa(stack_a);
		else if (min_pos == 2)
			rra(stack_a);
		min_pos = get_position(*stack_a, get_min_num(*stack_a));
	}
	if ((*stack_a)->next->value > (*stack_a)->next->next->value)
		sa(stack_a);
}
