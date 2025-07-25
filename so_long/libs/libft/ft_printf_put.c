/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_put.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmolina <hmolina@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 20:48:39 by hmolina           #+#    #+#             */
/*   Updated: 2025/07/21 18:15:50 by hmolina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_put_char(int c)
{
	return (write(1, &c, 1));
}

int	ft_put_str(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (write(1, "(null)", 6));
	while (str[i])
		write(1, &str[i++], 1);
	return (i);
}

int	ft_put_nbr(long c)
{
	int		num;

	num = 0;
	if (c < 0)
	{
		num = num + ft_put_char('-');
		c = -c;
	}
	if (c >= 10)
	{
		num = num + ft_put_nbr(c / 10);
		num = num + ft_put_nbr(c % 10);
	}
	if (c < 10)
		num = num + ft_put_char(c + '0');
	return (num);
}

int	ft_unsigned(unsigned int n)
{
	int		count;
	char	digit;

	count = 0;
	if (n >= 10)
		count += ft_unsigned(n / 10);
	digit = (n % 10) + '0';
	count += write(1, &digit, 1);
	return (count);
}

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

int	ft_put_ptr(unsigned long ptr, int flag)
{
	const char		*hex = "0123456789abcdef";
	int				count;

	count = 0;
	if (ptr == 0)
		return (write(1, "(nil)", 5));
	if (flag == 1)
	{
		count = count + 2;
		write(1, "0x", 2);
		flag = 0;
	}
	if (ptr >= 16)
		count += ft_put_ptr(ptr / 16, 0);
	count += write(1, &hex[ptr % 16], 1);
	return (count);
}
