/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmolina <hmolina@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 20:54:26 by hmolina           #+#    #+#             */
/*   Updated: 2024/12/17 20:05:02 by hmolina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//copia un bloque de memoria de una ubicación a otra

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned int	i;
	char			*d;
	const char		*s;

	i = 0;
	d = (char *)dest;
	s = (const char *)src;
	if (dest == NULL && src == NULL)
		return (NULL);
	while (i < n)
	{
		d[i] = s[i];
		i++;
	}
	return (dest);
}

/* int	main(void)
{
	char	*src = "Hello World!";
	char	empty_dest[10];

	printf("origin: %s\n", src);
	ft_memcpy(empty_dest, src + 6, 6);
	printf("copied %s\n", empty_dest);
	return (0);
} */
