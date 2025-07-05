/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmolina <hmolina@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 17:39:04 by hmolina           #+#    #+#             */
/*   Updated: 2024/12/17 17:41:29 by hmolina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*se utiliza para convertir un carácter en su equivalente en minúscula, si es
una letra mayúscula. Si el carácter no es una letra mayúscula, se devuelve sin
cambios*/

#include "libft.h"

int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
		c += 32;
	return (c);
}

/* int	main(void)
{
	printf ("%c\n", ft_tolower('H'));
	return (0);
} */
