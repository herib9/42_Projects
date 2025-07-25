/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmolina <hmolina@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 12:05:34 by hmolina           #+#    #+#             */
/*   Updated: 2025/07/15 22:00:04 by hmolina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//comprueba si un carácter int es un dígito decimal, del '0' al '9'

#include "libft.h"

int	ft_isalnum(int c)
{
	if ((c >= 65 && c <= 90) || (c >= 97 && c <= 122) || (c >= 48 && c <= 57))
		return (1);
	return (0);
}

/*int	main(void)
{
	printf ("1 si es alfanumerico: %i\n", ft_isalnum('9'));
	printf ("1 si es alfanumerico: %i\n", ft_isalnum('!'));
	return (0);
}*/
