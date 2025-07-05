/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmolina <hmolina@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 19:24:59 by hmolina           #+#    #+#             */
/*   Updated: 2024/12/20 23:28:33 by hmolina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*aplica una función dada a cada carácter de una cadena, pasando como
parámetros el índice del carácter y un puntero a ese carácter. Es útil para
realizar transformaciones o modificaciones sobre cada carácter de una cadena de
manera iterativa*/

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	int	i;

	if (!s || !f)
		return ;
	i = 0;
	while (s[i] != '\0')
	{
		f(i, &s[i]);
		i++;
	}
}

/* int	main(void)
{
	char	str[] = "Hello World";

	printf("original: %s\n", str);
	ft_striteri(str, ft_tolower);
	printf("mod: %s\n", str);
	return (0);
} */
