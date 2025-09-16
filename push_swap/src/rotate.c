/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmolina <hmolina@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 23:07:42 by hmolina           #+#    #+#             */
/*   Updated: 2025/09/16 19:10:11 by hmolina          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_node **stack)
{
	t_node	*one;
	t_node	*last;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	one = *stack;
	last = *stack;
	while (last->next)
		last = last->next;
	*stack = one->next;
	(*stack)->prev = NULL;
	one->next = NULL;
	one->prev = last;
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

/*
	FUNCIONES DE ROTACIÓN (ROTATE)

- rotate(t_node **stack): Mueve el primer elemento al final de la pila
- ra(t_node **stack_a): Rota la pila A hacia arriba e imprime "ra"
- rb(t_node **stack_b): Rota la pila B hacia arriba e imprime "rb"
- rr(t_node **stack_a, t_node **stack_b): Ejecuta ra y rb simultáneamente e imprime "rr"
*/