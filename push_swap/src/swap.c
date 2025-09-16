/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmolina <hmolina@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 20:31:08 by hmolina           #+#    #+#             */
/*   Updated: 2025/09/16 19:00:30 by hmolina          ###   ########lyon.fr   */
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
	if (two->next)
		two->next->prev = one;
	two->next = one;
	two->prev = one->prev;
	one->prev = two;
	if (two->prev)
		two->prev->next = two;
	*stack = two;
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

/*
	OPERACIONES DE PILA

FUNCIONES DE INTERCAMBIO (SWAP)
- swap(t_node **stack): Intercambia los dos primeros elementos de una pila
- sa(t_node **stack_a): Intercambia los dos primeros de la pila A e imprime "sa"
- sb(t_node **stack_b): Intercambia los dos primeros de la pila B e imprime "sb"
- ss(t_node **stack_a, t_node **stack_b): Ejecuta sa y sb simultáneamente e imprime "ss"
*/