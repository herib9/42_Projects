/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmolina <<hmolina@student.42.fr>>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 17:19:56 by hmolina           #+#    #+#             */
/*   Updated: 2025/08/18 19:54:27 by hmolina          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

/*convierte un string de char numericos a su equivalente en dato numérico
entero (int)*/

#include "libft.h"

int	ft_atoi(const char *nptr)
{
	int					sign;
	unsigned long int	result;
	int					i;

	sign = 1;
	result = 0;
	i = 0;
	while (nptr[i] == 32 || (nptr[i] >= 9 && nptr[i] <= 13))
		i++;
	if (nptr[i] == '-')
	{
		sign = -1;
		i++;
	}
	else if (nptr[i] == '+')
		i++;
	while (ft_isdigit(nptr[i]))
	{
		result *= 10;
		result += nptr[i] - '0';
		i++;
	}
	return (result * sign);
}

/* int	main(void)
{
	char	number1[] = "42";
	char	number2[] = "-42";
	char	number3[] = "herib9";
	char	number4[] = "9herib";

	printf("%d\n", ft_atoi(number1));
	printf("%d\n", ft_atoi(number2));
	printf("%d\n", ft_atoi(number3));
	printf("%d\n", ft_atoi(number4));
} */
