/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heri <heri@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 19:25:33 by hmolina           #+#    #+#             */
/*   Updated: 2025/07/04 03:54:43 by heri             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*escribe un carácter en un archivo de txt. Sus usos son:
1. Enviar mensajes de depuración o errores a stderr
2. Escribir en archivos abiertos mediante file descriptor personalizados
3. Modularizar el código en proyectos más grandes como los realizados en
escuelas que utilizan Libft.*/

#include "libft.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

int	main(void)
{
	int fd = open("output.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
	
	if (fd == -1)
	{
		write(2, "Error to write\n", 26);
		return (1);
	}
	ft_putchar_fd('c', fd);
	write(fd, "\n", 15);

	close(fd);
	
	return (0);
}
