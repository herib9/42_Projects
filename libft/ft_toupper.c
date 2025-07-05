/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heri <heri@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 16:56:49 by hmolina           #+#    #+#             */
/*   Updated: 2025/07/04 04:13:57 by heri             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//convierte un char de minuscula a mayuscula

#include "libft.h"

int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
		c -= 32;
	return (c);
}

/* int	main(void)
{
	printf ("%c\n", ft_toupper('A'));
	return (0);
} */
