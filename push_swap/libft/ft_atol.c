/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmolina <<hmolina@student.42.fr>>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 21:42:54 by hmolina           #+#    #+#             */
/*   Updated: 2025/08/19 01:31:18 by hmolina          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

//es igual que atoi, pero contempla numeros mas grandes

#include "libft.h"

long	ft_atol(char *s)
{
	long	i;
	long	sig;
	long	num;

	i = 0;
	sig = 1;
	num = 0;
	while (s[i] == '\t' || s[i] == '\n' || s[i] == '\r' || s[i] == '\f'
		|| s[i] == '\v' || s[i] == ' ')
		i++;
	if (s[i] == '-' || s[i] == '+')
	{
		if (s[i] == '-')
			sig = -1;
		i++;
	}
	while (s[i] >= '0' && s[i] <= '9')
	{
		num = num * 10 + (s[i] - '0');
		i++;
	}
	return (sig * num);
}
