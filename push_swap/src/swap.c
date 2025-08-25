/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmolina <<hmolina@student.42.fr>>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 20:31:08 by hmolina           #+#    #+#             */
/*   Updated: 2025/08/25 23:33:01 by hmolina          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_node **stack)
{
	t_node	*one;
	t_node	*two;
	
	if (!stack || !*stack || !(*stack)->next)
		return ;
	one = *stack;
	two = one->next;
	one->next = two->next;
	two->next = one;
	*stack = second;
}

void	sa(t_node **stack_a)
{
	swap(stack_a);
	ft_printf("sa\n");
}

void	sb(t_node **stack_b)
{
	swap(stack_b);
	ft_printf("sb\n");
}

void	ss(t_node **stack_a, t_node **stack_b)
{
	swap(stack_a);
	swap(stack_b);
	ft_printf("ss\n");
}
