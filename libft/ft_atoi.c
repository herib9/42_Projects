/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heri <heri@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 17:19:56 by hmolina           #+#    #+#             */
/*   Updated: 2025/07/04 04:14:52 by heri             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*convierte un string de char numericos a su equivalente en dato numérico
entero (int)*/

#include "libft.h"

int	ft_atoi(const char *s)
{
	int     sign;
	int     result;
	int		i;

	sign = 1;
	result = 0;
	i = 0;
	while (s[i] <= 32)
		i++;
	if (s[i] == '-' || s[i] == '+')
	{
        if (s[i] == '-')
		    sign = -1;
		    i++;
	}
	while (ft_isdigit(s[i]))
	{
		result = result * 10 + (s[i] - '0');
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
