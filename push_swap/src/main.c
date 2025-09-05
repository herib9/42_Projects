/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmolina <<hmolina@student.42.fr>>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/17 23:31:41 by hmolina           #+#    #+#             */
/*   Updated: 2025/09/02 20:50:33 by hmolina          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_node	*stack_a;
	t_node	*stack_b;

	if (ac < 2)
		return (0);
	if (!val_args(ac, av))
		return (write(2, "Error\n", 6), 1);
		//return (ft_printf("Error\n"), 1);
	stack_a = init_node(ac, av);
	stack_b = NULL;
	sort_stack(&stack_a, &stack_b, ac - 1);
	return (0);
}

void	radix_sort(t_node **stack_a, t_node **stack_b, int size)
{
	int max_bits;
	int	bit;
	int	i;

	normalize_stack(*stack_a);
	max_bits = get_max_bits(size - 1);
	bit = 0;
	while (bit < max_bits)
	{
		i = 0;
		while (i < size)
		{
			if ((((*stack_a)->index >> bit) & 1) == 0)
				pb(stack_a, stack_b);
			else
				ra(stack_a);
			i++;
		}
		while (*stack_b)
			pa(stack_a, stack_b);
		bit++;
	}
}
