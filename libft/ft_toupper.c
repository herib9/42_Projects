/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmolina <hmolina@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 16:56:49 by hmolina           #+#    #+#             */
/*   Updated: 2024/12/20 12:17:31 by hmolina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*se utiliza para convertir un carácter en su equivalente en mayúscula, si es
una letra minúscula. Si el carácter ya es una letra mayúscula o no es una letra
del alfabeto, se devuelve sin cambios*/

#include "libft.h"

int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
		c -= 32;
	return (c);
}

/* int	main(void)
{
	printf ("%c\n", ft_toupper('A'));
	return (0);
} */
