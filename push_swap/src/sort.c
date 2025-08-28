/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmolina <<hmolina@student.42.fr>>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 19:40:12 by hmolina           #+#    #+#             */
/*   Updated: 2025/08/28 21:05:43 by hmolina          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//check if the stack is sorted
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

void	sort_two(t_node **stack_a)
{
	if ((*stack_a)->value > (*stack_a)->next->value)
		sa(stack_a);
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

void	sort_five(t_node **stack_a, t_node **stack_b)
{
	int
}

void	sort_stack(t_node **stack_a, t_node **stack_b)
{
	int	size;
	if (sort(*stack_a))
		return ;
	size = get_size(*stack_a);
	if (size == 2)
		sort_two(**stack_a);
	else if (size == 3)
		sort_three(**stack_a);
	else if (size <= 5)
		sort_five(**stack_a, **stack_b);
	/*else
		sort(**stack_a, **stack_b);*/
}
