/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heri <heri@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 19:18:33 by hmolina           #+#    #+#             */
/*   Updated: 2025/07/04 03:47:18 by heri             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*reserva memoria dinámica para un bloque de elementos, a diferencia de malloc,
inicializa la memoria asignada a cero. 
- Reserva memoria: La función reserva un bloque de memoria grande suficiente
para contener NUM elementos, cada uno con un tamaño de SIZE bytes.
*/

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	char	*str;
	size_t	i;

	i = 0;
	str = malloc(nmemb * size);
	if (str == NULL)
		return (NULL);
	while (i < nmemb * size)
	{
		str[i] = 0;
		i++;
	}
	return ((void *)str);
}

/* int	main(void)
{
	size_t	nmemb = 10;
	size_t	size = sizeof(int);
	int		*array = (int *)ft_calloc(nmemb, size);

	printf("signed memory error: %zu\n", nmemb, size);
	free(array);
	return (0);
} 
{
	void	*str;

	str = malloc(nmemb * size);
	if (str == NULL)
		return (NULL);
	ft_bzero(str, nmemb * size);
	return (str);
}
*/
