/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmolina <<hmolina@student.42.fr>>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 00:56:56 by hmolina           #+#    #+#             */
/*   Updated: 2025/08/27 19:58:43 by hmolina          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
			return (NULL);
		add_end_node(&stack, new_node);
		i++;
	}
	return (stack);
}
