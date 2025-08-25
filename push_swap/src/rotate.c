/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmolina <<hmolina@student.42.fr>>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 23:07:42 by hmolina           #+#    #+#             */
/*   Updated: 2025/08/25 23:24:57 by hmolina          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_node **stack)
{
	t_node	*one;
	t_node	*last;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	*one = *stack;
	last = *stack;
	while (last->next)
		last = last->next;
	*stack = one->next;
	one->next = NULL;
	last->next = one;
}

void	ra(t_node **stack_a)
{
	rotate(stack_a);
	ft_printf("ra\n");
}

void	rb(t_node **stack_b)
{
	rotate(stack_b);
	ft_printf("rb\n");
}

void	rr(t_node **stack_a, t_node **stack_b)
{
	rotate(stack_a);
	rotate(stack_b);
	ft_printf("rr\n");
}
