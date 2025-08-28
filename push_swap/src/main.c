/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmolina <<hmolina@student.42.fr>>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/17 23:31:41 by hmolina           #+#    #+#             */
/*   Updated: 2025/08/27 22:29:21 by hmolina          ###   ########lyon.fr   */
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
		return (ft_printf("Error\n"), 1);
	stack_a = init_node(ac, av);
	stack_b = NULL;
	if (ac == 4)
		sort_three(&stack_a);
	return (0);
}
