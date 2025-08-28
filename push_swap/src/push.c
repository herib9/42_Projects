/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmolina <<hmolina@student.42.fr>>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 22:17:46 by hmolina           #+#    #+#             */
/*   Updated: 2025/08/28 21:00:22 by hmolina          ###   ########lyon.fr   */
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
