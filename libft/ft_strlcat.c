/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmolina <hmolina@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 12:43:56 by hmolina           #+#    #+#             */
/*   Updated: 2024/12/20 12:45:04 by hmolina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*concatena o une dos cadenas, src al final de dst, pero con un control 
explícito de la longitud total del resultado*/

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dst_len;
	size_t	src_len;
	size_t	i;

	dst_len = ft_strlen(dst);
	src_len = ft_strlen(src);
	if (dst_len >= size)
		return (src_len + size);
	else if (dst_len + 1 < size)
	{
		i = 0;
		while ((src[i] != '\0') && (dst_len + i < size - 1))
		{
			dst[dst_len + i] = src[i];
			i++;
		}
		dst[dst_len + i] = '\0';
	}
	return (src_len + dst_len);
}

/* int	main(void)
{
	char	dst[20] = "technics";
	const char	*src = " for life";
	size_t	size = 18 ;
	size_t	ress = ft_strlcat(dst, src, size);

	printf("result: %s\n", dst);
	printf("long %zu\n", ress);
	return (0);
} */
