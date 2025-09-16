/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmolina <hmolina@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 00:56:56 by hmolina           #+#    #+#             */
/*   Updated: 2025/09/16 18:58:23 by hmolina          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//make a individual node
t_node	*create_node(int value)
{
	t_node	*node;

	node = malloc(sizeof(t_node));
	if (!node)
		return (NULL);
	node->value = value;
	node->next = NULL;
	node->prev = NULL;
	return (node);
}

void	add_end_node(t_node **stack, t_node *new)
{
	t_node	*last;

	if (!new)
		return ;
	if (!*stack)
	{
		*stack = new;
		return ;
	}
	last = *stack;
	while (last->next)
		last = last->next;
	last->next = new;
	new->prev = last;
}

t_node	*init_node(int ac, char **av)
{
	t_node	*stack;
	t_node	*new_node;
	int		i;

	stack = NULL;
	i = 1;
	while (i < ac)
	{
		new_node = create_node(ft_atoi(av[i]));
		if (!new_node)
		{
			free_stack(&stack);
			return (NULL);
		}
		add_end_node(&stack, new_node);
		i++;
	}
	return (stack);
}

t_node	*init_node_split(char **args)
{
	t_node	*stack;
	t_node	*new_node;
	int		i;

	stack = NULL;
	i = 0;
	while (args[i])
	{
		new_node = create_node(ft_atoi(args[i]));
		if (!new_node)
		{
			free_stack(&stack);
			return (NULL);
		}
		add_end_node(&stack, new_node);
		i++;
	}
	return (stack);
}

void	free_stack(t_node **stack)
{
	t_node	*current;
	t_node	*next;

	if (!stack || !*stack)
		return ;
	current = *stack;
	while (current)
	{
		next = current->next;
		free(current);
		current = next;
	}
	*stack = NULL;
}

/*
	FUNCIONES DE GESTIÓN DE PILAS

create_node(int value)
- Propósito: Crea un nuevo nodo con un valor específico
- Funcionamiento: Reserva memoria e inicializa un nodo con el valor dado

add_end_node(t_node **stack, t_node *new)
- Propósito: Añade un nuevo nodo al final de la pila
- Funcionamiento: Si la pila está vacía, el nuevo nodo se convierte en el primero. Si no, lo añade al final

init_node(int ac, char **av)
- Propósito: Inicializa una pila con argumentos individuales
- Funcionamiento: Recorre los argumentos creando nodos y añadiéndolos a la pila

init_node_split(char **args)
- Propósito: Inicializa una pila con argumentos de una cadena dividida
- Funcionamiento: Similar al anterior pero para arrays de strings

free_stack(t_node **stack)
- Propósito: Libera completamente la memoria de una pila
- Funcionamiento: Recorre todos los nodos liberando su memoria y pone la pila a NULL
*/