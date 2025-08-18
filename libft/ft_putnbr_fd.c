/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmolina <hmolina@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 19:28:53 by hmolina           #+#    #+#             */
/*   Updated: 2025/07/15 22:00:43 by hmolina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*convierte un número entero a su representación en forma de cadena de
caracteres y lo escribe en el file descriptor especificado*/

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int	nbr;

	if (n < 0)
	{
		write(fd, "-", 1);
		nbr = n * -1;
	}
	else
		nbr = n;
	if (nbr >= 10)
		ft_putnbr_fd(nbr / 10, fd);
	write(fd, &"0123456789"[nbr % 10], 1);
}

/*int	main(void)
{
	int	fd;

	ft_putnbr_fd(42, 1);
	write(1, "\n", 1);
	fd = open("out_nbr.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd != -1)
	{
		ft_putnbr_fd(-42, fd);
		write(fd, "\n", 1);
		close(fd);
	}
	return (0);
}*/
