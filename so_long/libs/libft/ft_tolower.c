/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmolina <hmolina@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 17:39:04 by hmolina           #+#    #+#             */
/*   Updated: 2025/07/15 19:26:14 by hmolina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//convierte un char de mayuscula a minuscula

#include "libft.h"

int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
		c += 32;
	return (c);
}

/* int	main(void)
{
	printf ("%c\n", ft_tolower('H'));
	return (0);
} */
