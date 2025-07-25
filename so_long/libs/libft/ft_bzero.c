/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmolina <hmolina@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 19:32:19 by hmolina           #+#    #+#             */
/*   Updated: 2025/07/15 19:15:47 by hmolina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*inicializa una reserva de memoria con ceros, asegurando que no contenga datos
previos. Garantiza que las estructuras o buffers estén limpios antes de su uso*/

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*str;
	size_t			i;

	str = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		str[i] = 0;
		i++;
	}
}

/* int	main(void)
{
	char	c[5] = "herib";

	ft_bzero(c + 2, 2);
	printf("%s\n", c);
	return (0);
} */
