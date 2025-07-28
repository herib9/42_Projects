/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexa_mM.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmolina <hmolina@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 19:47:40 by hmolina           #+#    #+#             */
/*   Updated: 2025/02/15 21:48:42 by hmolina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_put_hex(unsigned int n, char format)
{
	const char		*hex_low = "0123456789abcdef";
	const char		*hex_up = "0123456789ABCDEF";
	int				count;

	count = 0;
	if (n >= 16)
		count += ft_put_hex(n / 16, format);
	if (format == 'x')
		count += write(1, &hex_low[n % 16], 1);
	else
		count += write(1, &hex_up[n % 16], 1);
	return (count);
}
