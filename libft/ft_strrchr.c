/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heri <heri@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 00:53:39 by hmolina           #+#    #+#             */
/*   Updated: 2025/07/04 04:09:36 by heri             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//devuelve un puntero a la última coincidencia del carácter c en la cadena s

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	a;

	a = c;
	i = ft_strlen(s);
	if (a == 0)
		return ((char *)&s[i]);
	while (i >= 0)
	{
		if (s[i] == a)
			return ((char *)&s[i]);
		i--;
	}
	return (0);
}

/* int	main(void)
{
	int			c = 'b';
	const char	*s = "hellooooh baby";
	char		*ress = ft_strrchr(s, c);

	printf("%s\n", ress);
	return (0);
} */
