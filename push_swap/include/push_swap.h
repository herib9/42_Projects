/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmolina <<hmolina@student.42.fr>>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 19:01:54 by hmolina           #+#    #+#             */
/*   Updated: 2025/08/23 03:03:47 by hmolina          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include "libft.h"

typedef struct s_node
{
	int				value;
	struct s_node	*next;
}	t_node;

int		main(int ac, char **av);

// == validation & parsing ==
int		val_numb(char *s);
int		check_overflow(char *s);
int		check_duplicates(int ac, char **av);
int		val_args(int ac, char **av);

// == stack functions ==
t_node	*create_node(int value);
void	add_end_node(t_node **stack, t_node *new);
t_node	*init_node(int ac, char **av);

// == sort functions ==
int		sort(t_node *node);
int		get_position(t_node *node, int value);
int		get_min_num(t_node *node);
void	sort_three(t_node **stack_a);

// == movements ==
void	sa(t_node **stack_a);
void	rra(t_node **stack_a);

#endif
