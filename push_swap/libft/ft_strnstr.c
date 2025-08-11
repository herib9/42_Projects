/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmolina <hmolina@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 11:00:09 by hmolina           #+#    #+#             */
/*   Updated: 2024/12/20 18:29:50 by hmolina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*Busca la secuencia de carácteres contenida en la subcadena en una cadena de
texto. Esta función determinará si la cadena contiene a la subcadena (como 
"CASA" contiene "ASA") y, en caso afirmativo, indicará en que posición aparece
la subcadena dentro de la cadena (de 0 en adelante, 1 en el ejemplo anterior).
En caso de aparecer la subcadena varias veces, la función siempre retornará la
posición primera.*/

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	h;
	size_t	i;

	if (little[0] == '\0')
		return ((char *)big);
	i = 0;
	while (big[i] != '\0' && i < len)
	{
		h = 0;
		while (big[i + h] == little[h] && (i + h) < len)
		{
			if (little[h + 1] == '\0')
				return ((char *)&big[i]);
			h++;
		}
		i++;
	}
	return (NULL);
}

/* int	main(void)
{
	const char	str1[] = "hello friend";
	const char	str2[] = "ello deejay";
	size_t		lon = 5;

	char		*ress = ft_strnstr(str1, str2, lon);
	if (ress)
		printf("find: %s\n", ress);
	else
		printf("no find: %zu\n", lon);
	return (0);
} */
