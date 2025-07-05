/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmolina <hmolina@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 02:11:56 by hmolina           #+#    #+#             */
/*   Updated: 2024/12/20 17:35:57 by hmolina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*copia una cadena de caracteres de una fuente (source) a un destino 
(destination), asegurándose de no escribir más allá del límite del búfer del 
destino. También garantiza que el búfer de destino esté siempre terminado con 
un carácter nulo*/

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (size != 0)
	{
		while (i < size -1 && src[i] != '\0')
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (ft_strlen(src));
}

/* int	main(void)
{
	char	c[7];
	size_t	len;

	len = ft_strlcpy(c, "thanks for all", sizeof(c));
	printf ("%s\n tamaño", (c));
	printf ("%zu\n longitud", (len));
	//printf ("%s\n", *dst, *src);
	//printf ("%zu\n", ft_strlcpy("thanks for all", c));
	return (0);
} */
