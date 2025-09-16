/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmolina <hmolina@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 13:08:27 by hmolina           #+#    #+#             */
/*   Updated: 2025/09/16 18:59:08 by hmolina          ###   ########lyon.fr   */
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
	return (-1);
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

int	get_max_num(t_node *stack)
{
	int	max;

	max = stack->value;
	while (stack)
	{
		if (stack->value > max)
			max = stack->value;
		stack = stack->next;
	}
	return (max);
}

int	get_max_bits(int max_num)
{
	int	bits;

	bits = 0;
	while ((max_num >> bits) != 0)
		bits++;
	return (bits);
}

void	normalize_stack(t_node *stack)
{
	t_node	*actual;
	t_node	*compare;
	int		rank;

	actual = stack;
	while (actual)
	{
		rank = 0;
		compare = stack;
		while (compare)
		{
			if (compare->value < actual->value)
				rank++;
			compare = compare->next;
		}
		actual->index = rank;
		actual = actual->next;
	}
}

/*
	FUNCIONES DE OBTENCIÓN DE DATOS

get_position(t_node *node, int value)
- Propósito: Encuentra la posición de un valor específico en la pila
- Funcionamiento: Recorre la pila hasta encontrar el valor y devuelve su posición

get_min_num(t_node *node)
- Propósito: Encuentra el valor mínimo en la pila
- Funcionamiento: Recorre toda la pila comparando valores

get_max_num(t_node *stack)
- Propósito: Encuentra el valor máximo en la pila
- Funcionamiento: Similar al mínimo pero buscando el mayor

get_max_bits(int max_num)
- Propósito: Calcula cuántos bits se necesitan para representar un número
- Funcionamiento: Cuenta cuántas veces se puede dividir por 2 hasta llegar a 0

normalize_stack(t_node *stack)
- Propósito: Asigna índices normalizados (0, 1, 2...) a cada valor según su orden
- Funcionamiento: Para cada nodo, cuenta cuántos valores son menores que él

*/