/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmolina <<hmolina@student.42.fr>>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 13:08:27 by hmolina           #+#    #+#             */
/*   Updated: 2025/08/28 20:59:57 by hmolina          ###   ########lyon.fr   */
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

int	get_stack_size(t_node *stack)
{

}

int	get_max_num(t_node *stack)
{

}

void	normalize_stack(t_node *stack)
{

}
