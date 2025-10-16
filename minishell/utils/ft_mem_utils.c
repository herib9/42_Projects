/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mem_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leiamart <leiamart@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 19:37:54 by leiamart          #+#    #+#             */
/*   Updated: 2025/10/15 19:37:56 by leiamart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	*ft_memset(void *v, int i, size_t x)
{
	char	*c;

	c = (char *)v;
	while (x-- > 0)
		c[x] = i;
	return (v);
}

void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, 0, n);
}

void	*ft_calloc(size_t c, size_t i)
{
	size_t	x;
	void	*v;

	x = c * i;
	v = protect_memory(x);
	if (v == NULL)
		return (NULL);
	else
		ft_bzero(v, x);
	return (v);
}
