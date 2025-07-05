/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmolina <hmolina@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 12:35:38 by hmolina           #+#    #+#             */
/*   Updated: 2024/12/20 17:35:47 by hmolina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalpha(int c)
{
	if ((c >= 65 && c <= 90) || (c >= 97 && c <= 122))
		return (1);
	return (0);
}

/* int	main(void)
{
	printf ("1 true, 0 fail: %d\n", ft_isalpha('h'));
	printf ("1 true, 0 fail: %d\n", ft_isalpha(1));
	return (0);
}  */

/*comprueba  si  el  carácter  es  alfabético*/
