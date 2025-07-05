/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_num_nosign.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmolina <hmolina@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 17:04:30 by hmolina           #+#    #+#             */
/*   Updated: 2025/02/15 21:49:11 by hmolina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_num_nosign(unsigned int n)
{
	int		count;
	char	digit;

	count = 0;
	if (n >= 10)
		count += ft_num_nosign(n / 10);
	digit = (n % 10) + '0';
	count += write(1, &digit, 1);
	return (count);
}
