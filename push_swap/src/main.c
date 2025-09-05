/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmolina <<hmolina@student.42.fr>>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/17 23:31:41 by hmolina           #+#    #+#             */
/*   Updated: 2025/09/05 23:58:50 by hmolina          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_node	*stack_a;
	t_node	*stack_b;

	if (ac < 2)
		return (0);
	if (ac == 2)
		stack_a = take_single_arg(av[1]);
	else
		stack_a = take_va(ac, av);
	if (!stack_a)
		return (write(2, "Error\n", 6), 1);
	stack_b = NULL;
	sort_stack(&stack_a, &stack_b, get_stack_size(stack_a));
	return (0);
}

t_node	*take_single_arg(char *arg)
{
	char	**parsed_args;
	t_node	*stack;
	int		arg_count;

	parsed_args = ft_split(arg, ' ');
	if (!parsed_args)
		return (NULL);
	arg_count = count_args(parsed_args) + 1;
	if (!val_args(arg_count, parsed_args))
	{
		free_split(parsed_args);
		return (NULL);
	}
	stack = init_node_split(arg_count, parsed_args);
	free_split(parsed_args);
	return (stack);
}

t_node	*take_va(int ac, char **av)
{
	if (!val_args(ac, av))
		return (NULL);
	return (init_node(ac, av));
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
