/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmolina <hmolina@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 19:37:08 by hmolina           #+#    #+#             */
/*   Updated: 2024/12/17 17:38:53 by hmolina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*compara carácter a carácter dos cadenas hasta un número especificado de 
caracteres. Es útil cuando deseas comparar cadenas pero limitar la comparación
a una cantidad específica de caracteres*/

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	*str1;
	unsigned char	*str2;
	size_t			i;

	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	i = 0;
	while (i < n && (str1[i] != '\0' || str2[i] != '\0'))
	{
		if (str1[i] != str2[i])
			return (str1[i] - str2[i]);
		i++;
	}
	if (n == 0)
		return (0);
	return (0);
}

/* int	main(void)
{
	const char	*str1 = "helloh baby";
	const char	*str2 = "hllo baby";
	const char	*str3 = "salam";

	int	result1 = ft_strncmp(str1, str2, 3);
	int	result2 = ft_strncmp(str2, str3, 2);
	int	result3 = ft_strncmp(str3, str1, 4);

	printf ("result 1 era : %d\n", result1);
	printf ("result 2 era : %d\n", result2);
	printf ("reuslt 3 era : %d\n", result3);
	return (0);
} */
