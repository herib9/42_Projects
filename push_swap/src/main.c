/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmolina <hmolina@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/17 23:31:41 by hmolina           #+#    #+#             */
/*   Updated: 2025/09/16 19:08:56 by hmolina          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_node	*stack_a;
	t_node	*stack_b;

	if (ac < 2)
		return (0);
	stack_a = parse_args(ac, av);
	if (!stack_a)
		return (write(2, "Error\n", 6), 1);
	stack_b = NULL;
	sort_stack(&stack_a, &stack_b, get_stack_size(stack_a));
	free_stack(&stack_a);
	free_stack(&stack_b);
	return (0);
}

t_node	*parse_args(int ac, char **av)
{
	if (ac == 2)
		return (take_single_string(av[1]));
	else
		return (take_multiple_args(ac, av));
}

t_node	*take_single_string(char *s)
{
	char	**args;
	t_node	*stack;

	args = ft_split(s, ' ');
	if (!args || !val_args_split(args))
	{
		free_args(args);
		return (NULL);
	}
	stack = init_node_split(args);
	free_args(args);
	return (stack);
}

t_node	*take_multiple_args(int ac, char **av)
{
	if (!val_args(ac, av))
		return (NULL);
	return (init_node(ac, av));
}

void	radix_sort(t_node **stack_a, t_node **stack_b, int size)
{
	int	max_bits;
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

/*
	FUNCIÓN PRINCIPAL

main(int ac, char **av)
- Propósito: Función principal que coordina todo el programa
- Funcionamiento:
	* Verifica que haya al menos 2 argumentos
	* Procesa los argumentos y crea la pila A
	* Inicializa la pila B como NULL
	* Ejecuta el algoritmo de ordenamiento
	* Libera la memoria de ambas pilas

parse_args(int ac, char **av)
- Propósito: Decide cómo procesar los argumentos de entrada
- Funcionamiento: Si hay 2 argumentos, trata el segundo como una cadena con números separados por espacios. Si hay más argumentos, los trata individualmente

	FUNCIONES DE PROCESAMIENTO DE ARGUMENTOS

take_single_string(char *s)
- Propósito: Procesa una cadena que contiene múltiples números separados por espacios
- Funcionamiento:
	* Divide la cadena usando espacios como separadores
	* Valida todos los números resultantes
	* Crea la pila con esos números

take_multiple_args(int ac, char **av)
- Propósito: Procesa argumentos individuales pasados al programa
- Funcionamiento: Valida los argumentos y crea la pila directamente

	FUNCION DE ALGORITMO DE ORDENAMIENTO
	
radix_sort(t_node **stack_a, t_node **stack_b, int size)
- Propósito: Implementa el algoritmo radix sort para pilas grandes
- Funcionamiento:
	* Normaliza la pila (asigna índices 0, 1, 2...)
	* Por cada bit de los índices:
		- Mueve elementos con bit 0 a pila B
		- Deja elementos con bit 1 en pila A (rotándolos)
		- Devuelve todos los elementos de B a A
*/