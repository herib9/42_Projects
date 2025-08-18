/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmolina <hmolina@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 12:49:54 by hmolina           #+#    #+#             */
/*   Updated: 2025/07/15 19:25:53 by hmolina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*extrae una subcadena de un string, su propósito es tomar una porción de un
string existente, comenzando desde una posición específica y con una longitud
determinada*/

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned int	i;
	char			*sub;

	i = 0;
	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
		return (ft_calloc(1, 1));
	if (len >= ft_strlen(s + start))
		len = ft_strlen(s + start);
	sub = malloc(sizeof(char) * (len) + 1);
	if (!sub)
		return (NULL);
	while (len > 0)
	{
		sub[i++] = s[start++];
		len--;
	}
	sub[i] = '\0';
	return (sub);
}

/* int	main(void)
{
	char	*a;
	char	test1[] = "01234";

	a = ft_substr(test1, 2, 10);
	printf("%s\n", a);
	return (0);
} */
