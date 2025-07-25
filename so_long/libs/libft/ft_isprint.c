/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmolina <hmolina@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 13:53:39 by hmolina           #+#    #+#             */
/*   Updated: 2024/12/17 17:26:45 by hmolina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//comprueba si el carácter es imprimible, incluyendo el espacio en blanco

#include "libft.h"

int	ft_isprint(int c)
{
	{
		if (c >= 32 && c <= 126)
			return (1);
	}
	return (0);
}

/* int	main(void)
{
	printf ("1 si es imprimible, 0 si no lo es: %d\n", ft_isprint('á'));
	return (0);
} */
