/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmolina <hmolina@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 23:05:48 by hmolina           #+#    #+#             */
/*   Updated: 2025/07/15 22:00:16 by hmolina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*mueve un bloque de memoria desde una ubicación a otra.*/

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*d;
	unsigned char	*s;
	size_t			i;

	d = (unsigned char *)dest;
	s = (unsigned char *)src;
	i = n;
	if (dest == NULL && src == NULL)
		return (NULL);
	if (d > s)
	{
		while (i > 0)
		{
			i--;
			d[i] = s[i];
		}
	}
	if (d < s)
		ft_memcpy(d, s, n);
	return (dest);
}

/*int	main(void)
{
	char	*src;
	char	empty_dest[13];

	src = "Hello World!";
	printf("origin: %s\n", src);
	ft_memmove(empty_dest, src + 2, 6);
	printf("dest: %s\n", empty_dest);
	return (0);
}*/
