/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmolina <hmolina@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 12:35:59 by hmolina           #+#    #+#             */
/*   Updated: 2024/12/17 17:26:35 by hmolina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//comprueba si el carácter es un dígito de 0 a 9

#include "libft.h"

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

/* int	main(void)
{
	int	i;
	int	b;

	i = 'a';
	b = '1';
	printf ("1 si es numerico, 0 si no lo es: %d\n", ft_isdigit(i));
	printf ("1 si es numerico, 0 si no lo es: %d\n", ft_isdigit(b));
	return (0);
} */
