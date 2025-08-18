/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmolina <hmolina@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 21:33:44 by hmolina           #+#    #+#             */
/*   Updated: 2025/07/15 19:22:12 by hmolina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*devuelve un puntero a la primera ocurrencia del carácter c en la cadena de 
caracteres s*/

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == ((char)c))
		{
			return ((char *) &s[i]);
		}
		i++;
	}
	if (s[i] == (char) c)
	{
		return ((char *) &s[i]);
	}
	return (0);
}

/* int	main(void)
{
	const char	*phrase = "salam malicum";
	char		*ress;

	ress = ft_strchr(phrase, ' ');
	if (ress != NULL)
	{
		printf("rest phrase '%s\n", ress);
	}
	return (0);
} */
