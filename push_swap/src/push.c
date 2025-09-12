/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmolina <<hmolina@student.42.fr>>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 22:17:46 by hmolina           #+#    #+#             */
/*   Updated: 2025/09/08 23:36:02 by hmolina          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_node(t_node **from, t_node **to)
{
	t_node	*node;

	if (!from || !*from)
		return ;
	node = *from;
	*from = node->next;
	if (*from)
		(*from)->prev = NULL;
	node->next = *to;
	node->prev = NULL;
	if (*to)
		(*to)->prev = node;
	*to = node;
}

void	pa(t_node **stack_a, t_node **stack_b)
{
	push_node(stack_b, stack_a);
	ft_printf("pa\n");
}

void	pb(t_node **stack_a, t_node **stack_b)
{
	push_node(stack_a, stack_b);
	ft_printf("pb\n");
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
