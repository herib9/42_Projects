/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmolina <hmolina@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 16:48:51 by hmolina           #+#    #+#             */
/*   Updated: 2025/07/15 19:22:31 by hmolina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*duplica una cadena de caracteres. Toma un string como entrada, asigna
dinámicamente memoria suficiente para copiarla, y devuelve un puntero al nuevo
string duplicado. 
Se usa para trabajar con una copia de un string sin modificar el original.*/

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
