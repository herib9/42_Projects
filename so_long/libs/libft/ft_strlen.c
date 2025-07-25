/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmolina <hmolina@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 16:38:52 by hmolina           #+#    #+#             */
/*   Updated: 2025/07/15 19:23:55 by hmolina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*calcula la longitud de una cadena de caracteres, excluyendo el carácter 
nulo ('\0) que marca el final del string*/

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
