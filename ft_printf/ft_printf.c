/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmolina <hmolina@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 17:50:05 by hmolina           #+#    #+#             */
/*   Updated: 2025/02/23 18:31:26 by hmolina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	type_var(va_list args, const char c)
{
	if (c == 'c')
		return (ft_put_char(va_arg(args, int)));
	else if (c == 's')
		return (ft_put_str(va_arg(args, char *)));
	else if (c == 'p')
		return (ft_put_ptr(va_arg(args, unsigned long), 1));
	else if (c == 'd' || c == 'i')
		return (ft_put_nbr(va_arg(args, int)));
	else if (c == 'u')
		return (ft_num_nosign(va_arg(args, unsigned int)));
	else if (c == 'x' || c == 'X')
		return (ft_put_hex(va_arg(args, unsigned int), c));
	else if (c == '%')
		return (write(1, "%", 1));
	return (0);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		i;
	int		length;

	i = 0;
	length = 0;
	va_start(args, str);
	while (str[i] != '\0')
	{
		if (str[i] == '%')
		{
			i++;
			length += type_var(args, str[i]);
		}
		else
			length += write(1, &str[i], 1);
		i++;
	}
	va_end(args);
	return (length);
}

int	main()
{
	int	x;
	int	y;
	unsigned int	num = 123456;

	x = 0;
	y = 0;
	x += printf("%X\n", num);
	y += ft_printf("%X\n", num);

	print("x = %d, y = %d", x, y);
	return (0);
}
	