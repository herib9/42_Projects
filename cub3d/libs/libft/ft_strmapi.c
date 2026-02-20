/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmolina <hmolina@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 19:24:09 by hmolina           #+#    #+#             */
/*   Updated: 2025/07/15 19:24:26 by hmolina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*crea una nueva cadena aplicando una función a cada carácter del string
existente, teniendo en cuenta la posicion del carácter*/

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		i;
	char	*str;

	if (!s)
		return (NULL);
	str = malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!str)
		return (NULL);
	i = 0;
	while (s[i] != '\0')
	{
		str[i] = f(i, s[i]);
		i++;
	}
	str[i] = '\0';
	return (str);
}

/* int	main(void)
{
	char	str[] = "Hello World";
	char	*ress = ft_strmapi(str, ft_tolower);

	printf("original: %s\n", str);
	printf("mod: %s\n", ress);
	return (0);
} */