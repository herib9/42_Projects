/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmolina <hmolina@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 19:27:19 by hmolina           #+#    #+#             */
/*   Updated: 2025/02/23 18:30:15 by hmolina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*escribe una cadena de caracteres seguida de un salto de línea (\n) en un
descriptor de archivo específico. Es útil para escribir líneas completas en
archivos o flujos de salida, agregando automáticamente el salto de línea al
final*/

#include "libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	write(fd, s, ft_strlen(s));
	write(fd, "\n", 1);
}

int main(void)
{
	ft_putendl_fd("Hello World", 1);

	int fd = open ("out_endl.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd != -1)
	{
		ft_putendl_fd("Hello World", fd);
		close(fd);
	}
	return (0);
}
