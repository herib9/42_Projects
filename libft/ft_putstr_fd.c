/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmolina <hmolina@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 19:26:33 by hmolina           #+#    #+#             */
/*   Updated: 2025/02/23 18:30:46 by hmolina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*escribe una cadena (string) en el descriptor de archivo especificado*/

#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	write(fd, s, ft_strlen(s));
}

int main(void)
{
	ft_putstr_fd("Hello World\n", 1);

	int fd = open("out_str.txt",  O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd != -1)
	{
		ft_putstr_fd("Hello World\n", fd);
		close(fd);
	}
	return (0);
}
