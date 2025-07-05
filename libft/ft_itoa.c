/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heri <heri@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 19:23:33 by hmolina           #+#    #+#             */
/*   Updated: 2025/07/04 03:52:17 by heri             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//convierte un número entero (int) a una cadena de caracteres (char*)

#include "libft.h"

static int	count_c(int num)
{
	int	count;

	count = 0;
	if (num != 0)
	{
		if (num < 0)
		{
			num = -num;
			count++;
		}
		while (num != 0)
		{
			num = num / 10;
			count++;
		}
	}
	else
		count = 1;
	return (count);
}

char	*ft_itoa(int n)
{
	int			len;
	char		*str;
	long int	nbr;

	len = count_c(n);
	nbr = n;
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (0);
	if (nbr < 0)
	{
		str[0] = '-';
		nbr = -nbr;
	}
	if (nbr == 0)
		str[0] = '0';
	str[len] = '\0';
	len--;
	while (nbr)
	{
		str[len] = ((nbr % 10) + '0');
		nbr /= 10;
		len--;
	}
	return (str);
}

/* int	main(void)
{
	int		n;
	char	*str;

	n = -7654321;
	str = ft_itoa(n);
	printf("%s\n", str);
	free(str);
	return (0);
} */
