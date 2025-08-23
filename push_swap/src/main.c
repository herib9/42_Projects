/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmolina <<hmolina@student.42.fr>>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/17 23:31:41 by hmolina           #+#    #+#             */
/*   Updated: 2025/08/19 01:25:53 by hmolina          ###   ########lyon.fr   */
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
	return (0);
}
