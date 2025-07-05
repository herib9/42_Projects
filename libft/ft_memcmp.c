/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heri <heri@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 17:44:51 by hmolina           #+#    #+#             */
/*   Updated: 2025/07/04 03:51:39 by heri             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*compara los primeros n bytes de las areas de memoria s1 y s2. Devuelve un
entero menor, igual a o mayor que cero si s1 es, respectivamente, menor, igual
o mayor que s2*/

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*str1;
	unsigned char	*str2;
	size_t			i;

	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	i = 0;
	while (i < n)
	{
		if (str1[i] != str2[i])
		{
			return (str1[i] - str2[i]);
		}
		i++;
	}
	return (0);
}

/* int	main(void)
{
	char	*str1 = "hello";
	char	*str2 = "hawio";
	int		ress;

	ress = ft_memcmp(str1, str2, 5);
	printf("diferencias: %i\n", ress);
	return (0);
} */
