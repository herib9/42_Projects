/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmolina <hmolina@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 19:40:12 by hmolina           #+#    #+#             */
/*   Updated: 2025/09/16 19:10:00 by hmolina          ###   ########lyon.fr   */
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
	int		actual_size;

	actual_size = get_stack_size(*stack_a);
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

/*
	FUNCIONES DE ORDENAMIENTO

sort(t_node *node)
- Propósito: Verifica si una pila ya está ordenada
- Funcionamiento: Recorre la pila verificando que cada elemento sea menor que el siguiente

sort_two(t_node **stack_a)
- Propósito: Ordena una pila de 2 elementos
- Funcionamiento: Si el primer elemento es mayor que el segundo, los intercambia

sort_three(t_node **stack_a)
- Propósito: Ordena una pila de 3 elementos
- Funcionamiento: Analiza las 6 posibles combinaciones y aplica la secuencia de operaciones correspondiente

sort_five(t_node **stack_a, t_node **stack_b)
- Propósito: Ordena pilas de 4 o 5 elementos
- Funcionamiento:
	* Mueve los elementos más pequeños a la pila B
	* Ordena los 3 restantes en A
	* Devuelve los elementos de B a A

push_min_2_stack_b(t_node **stack_a, t_node **stack_b)
- Propósito: Encuentra el elemento mínimo y lo mueve a la pila B
- Funcionamiento:
	* Encuentra la posición del mínimo
	* Decide si rotar hacia arriba o abajo según la eficiencia
	* Mueve el mínimo a la pila B

sort_stack(t_node **stack_a, t_node **stack_b, int size)
- Propósito: Función principal de ordenamiento que decide qué algoritmo usar
- Funcionamiento:
	* Si ya está ordenada, no hace nada
	* Para 2-3 elementos: algoritmos específicos
	* Para 4-5 elementos: algoritmo de 5
	* Para más elementos: radix sort
*/