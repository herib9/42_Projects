/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmolina <hmolina@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 16:48:51 by hmolina           #+#    #+#             */
/*   Updated: 2024/12/20 20:03:57 by hmolina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*se utiliza para duplicar una cadena de caracteres. Toma una cadena como
entrada, asigna dinámicamente memoria suficiente para copiarla, y devuelve un
puntero a la nueva cadena duplicada. Es una función muy útil cuando necesitas 
trabajar con una copia de una cadena sin modificar la original.*/

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*str;
	int		i;
	int		len;

	len = ft_strlen(s);
	i = 0;
	str = malloc(sizeof(*str) * (len + 1));
	if (!str)
		return (NULL);
	while (s[i])
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

/* int	main(void)
{
	char	s1[] = "HEllo World";
	printf("%s\n", ft_strdup(s1));
} */
