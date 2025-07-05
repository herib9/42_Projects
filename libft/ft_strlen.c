/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmolina <hmolina@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 16:38:52 by hmolina           #+#    #+#             */
/*   Updated: 2024/12/17 17:38:03 by hmolina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*se utiliza para calcular la longitud de una cadena de caracteres (número de 
caracteres que contiene), excluyendo el carácter nulo ('\0) que marca el final
de la cadena*/

#include "libft.h"

size_t	ft_strlen(const char *s)
{
	size_t	l;

	l = 0;
	while (s[l] != '\0')
		l++;
	return (l);
}

/*int	main(void)
{
	//char str[] = "hello baby";
	//const char c;
       	//c = strlen(s);
	printf("%zu\n", ft_strlen("hello baby"));
	return (0);
}*/
