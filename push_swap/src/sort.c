/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmolina <<hmolina@student.42.fr>>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 19:40:12 by hmolina           #+#    #+#             */
/*   Updated: 2025/09/02 20:16:03 by hmolina          ###   ########lyon.fr   */
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
	int	one;
	int	two;
	int	three;

	one = (*stack_a)->value;
	two = (*stack_a)->next->value;
	three = (*stack_a)->next->next->value;
	if (one > two && two < three && one < three)
		sa(stack_a);
	else if (one > two && two > three && one > three)
	{
		sa(stack_a);
		rra(stack_a);
	}
	else if (one > two && two < three && one > three)
		ra(stack_a);
	else if (one < two && two > three && one < three)
	{
		sa(stack_a);
		ra(stack_a);
	}
	else if (one < two && two > three && one > three)
		rra(stack_a);
}

void	sort_five(t_node **stack_a, t_node **stack_b)
{
	int	actual_size;
	t_node	*temp;

	actual_size = 0;
	temp = *stack_a;
	while (temp)
	{
		actual_size++;
		temp = temp->next;
	}
	if (sort(*stack_a))
		return ;
	push_min_2_stack_b(stack_a, stack_b);
	if (actual_size == 5)
		push_min_2_stack_b(stack_a, stack_b);
	sort_three(stack_a);
	while (*stack_b)
		pa(stack_a, stack_b);
}

void	sort_stack(t_node **stack_a, t_node **stack_b, int size)
{
	if (sort(*stack_a))
		return ;
	if (size == 2)
		sort_two(stack_a);
	else if (size == 3)
		sort_three(stack_a);
	else if (size <= 5)
		sort_five(stack_a, stack_b);
	else
		radix_sort(stack_a, stack_b, size);
}

void	push_min_2_stack_b(t_node **stack_a, t_node **stack_b)
{
	int		min;
	int		min_pos;
	int		node_size;
	t_node	*temp;

	min = get_min_num(*stack_a);
	min_pos = get_position(*stack_a, min);
	node_size = 0;
	temp = *stack_a;
	while (temp)
	{
		node_size++;
		temp = temp->next;
	}
	if (min_pos <= node_size / 2)
	{
		while ((*stack_a)->value != min)
			ra(stack_a);
	}
	else
	{
		while ((*stack_a)->value != min)
			rra(stack_a);
	}
	pb(stack_a, stack_b);
}

//con el if roto hacia alante (mas corto)
//con el else roto hacia atras (mas corto)