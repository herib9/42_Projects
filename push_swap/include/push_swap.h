/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmolina <<hmolina@student.42.fr>>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 19:01:54 by hmolina           #+#    #+#             */
/*   Updated: 2025/09/08 22:31:16 by hmolina          ###   ########lyon.fr   */
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
	int				index;
	struct s_node	*next;
	struct s_node	*prev;
}	t_node;

int		main(int ac, char **av);
t_node	*parse_args(int ac, char **av);
t_node	*take_single_string(char *s);
t_node	*take_multiple_args(int ac, char **av);
void	radix_sort(t_node **stack_a, t_node **stack_b, int size);

// === validation arguments ===
int		val_numb(char *s);
int		val_args(int ac, char **av);
int		val_simple_args(int count, char **args);
int		val_args_split(char **args);
void	free_args(char **args);

// === check functions ===
int		check_overflow(char *s);
int		check_duplicates(int ac, char **av);
int		check_duplicates_simple(int count, char **args);
int		check_duplicates_split(char **args);
int		get_stack_size(t_node *stack);

// === stack functions ===
t_node	*create_node(int value);
void	add_end_node(t_node **stack, t_node *new);
t_node	*init_node(int ac, char **av);
t_node	*init_node_split(char **args);
void	free_stack(t_node **stack);

// === sort functions ===
int		sort(t_node *node);
void	sort_two(t_node **stack_a);
void	sort_three(t_node **stack_a);
void	sort_five(t_node **stack_a, t_node **stack_b);
void	sort_stack(t_node **stack_a, t_node **stack_b, int size);
void	push_min_2_stack_b(t_node **stack_a, t_node **stack_b);

// === get functions ===
int		get_position(t_node *node, int value);
int		get_min_num(t_node *node);
int		get_max_num(t_node *stack);
int		get_max_bits(int max_num);
void	normalize_stack(t_node *stack);

// === swap functions ===
void	swap(t_node **stack);
void	sa(t_node **stack_a);
void	sb(t_node **stack_b);
void	ss(t_node **stack_a, t_node **stack_b);

// === rotate functions ===
void	rotate(t_node **stack);
void	ra(t_node **stack_a);
void	rb(t_node **stack_b);
void	rr(t_node **stack_a, t_node **stack_b);

// === reverse rotate functions ===
void	reverse_rotate(t_node **stack);
void	rra(t_node **stack_a);
void	rrb(t_node **stack_b);
void	rrr(t_node **stack_a, t_node **stack_b);

// === push functions ===
void	push_node(t_node **from, t_node **to);
void	pa(t_node **stack_a, t_node **stack_b);
void	pb(t_node **stack_a, t_node **stack_b);

#endif
