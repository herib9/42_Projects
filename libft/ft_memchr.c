/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heri <heri@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 17:29:07 by hmolina           #+#    #+#             */
/*   Updated: 2025/07/04 03:50:08 by heri             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*busca la primera aparición de un byte específico en un bloque de memoria.
Toma una cadena, un caracter a buscar y un tamaño y devuelve un puntero a la
primera coincidencia del caracter en cadena o NULL si no se encuentra el
caracter*/

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*str;
	unsigned char	to_find;
	size_t			i;

	str = (unsigned char *)s;
	to_find = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		if (str[i] == to_find)
			return ((void *)&str[i]);
		i++;
	}
	return (NULL);
}

/* int	main(void)
{
	char	str[] = "Hello friend";
	char	to_find = 'f';
	char	*ress = ft_memchr(str, to_find, strlen(str));

	printf("caracter encontrado %c\n", to_find, ress);
	return (0);
} */
