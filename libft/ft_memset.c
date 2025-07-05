/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heri <heri@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 14:17:55 by hmolina           #+#    #+#             */
/*   Updated: 2025/07/04 03:53:20 by heri             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*rellena los primeros n bytes del bloque de memoria apuntada por s con el
byte constante c*/

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*str;
	size_t			i;

	str = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		str[i] = (unsigned char)c;
		i++;
	}
	return (s);
}

/* int	main(void)
{
	char	c[4];

	ft_memset(c, 'z', sizeof(c));
	c[3] = '\0';
	printf("resultado: %s\n", c);
	return (0);
} */
