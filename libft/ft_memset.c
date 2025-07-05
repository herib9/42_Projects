/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmolina <hmolina@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 14:17:55 by hmolina           #+#    #+#             */
/*   Updated: 2024/12/17 17:32:13 by hmolina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*La función memset() rellena los primeros n bytes del área de memoria apuntada 
por s con el byte constante c*/

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
