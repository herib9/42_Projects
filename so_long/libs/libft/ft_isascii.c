/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmolina <hmolina@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 13:31:31 by hmolina           #+#    #+#             */
/*   Updated: 2024/12/17 17:26:28 by hmolina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*comprueba si c es un valor unsigned char de 7 bits, que encaje dentro del  
conjunto de caracteres ASCII.*/

#include "libft.h"

int	ft_isascii(int c)
{
	if (c >= 00 && c <= 127)
		return (1);
	return (0);
}

/* int	main(void)
{
	printf ("1 si es ascii, 0 si no lo es: %i\n", ft_isascii('!'));
	printf ("1 si es ascii, 0 si no lo es: %i\n", ft_isascii('é'));
	return (0);
} */
