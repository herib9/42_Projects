/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmolina <hmolina@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 18:05:09 by hmolina           #+#    #+#             */
/*   Updated: 2024/12/20 23:54:26 by hmolina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*se utiliza para eliminar los caracteres de espacio en blanco (o cualquier
conjunto de caracteres definidos) del principio y del final de una cadena de
caracteres. Es útil cuando se necesita limpiar una cadena, eliminando los
espacios innecesarios de los extremos*/

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;
	char	*str;

	str = 0;
	if (s1 != 0 && set != 0)
	{
		start = 0;
		end = ft_strlen(s1);
		while (s1[start] && ft_strchr(set, s1[start]))
			start++;
		while (s1[end - 1] && ft_strchr(set, s1[end - 1]) && end > start)
			end--;
		str = (char *)malloc(sizeof(char) * (end - start + 1));
		if (str)
			ft_strlcpy(str, &s1[start], end - start + 1);
	}
	return (str);
}

/* int	main(void)
{
	char	s1[] = "  hello world  ";
	char	set[] = " ";
	printf("%s\n", ft_strtrim(s1, set));
} */