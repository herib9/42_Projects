/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmolina <hmolina@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 19:37:20 by hmolina           #+#    #+#             */
/*   Updated: 2025/07/19 23:53:22 by hmolina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	send_signal(int pid, int sig)
{
	if (kill(pid, sig) == -1)
	{
		ft_putstr_fd("Error: No se puedo enviar la señal\n", 2);
		exit(EXIT_FAILURE);
	}
	usleep(100);
}

void	send_char(int pid, char c)
{
	int	bit;
	int	i;

	i = 7;
	while (i >= 0)
	{
		bit = (c >> i) & 1;
		if (bit == 0)
			send_signal(pid, SIGUSR1);
		else
			send_signal(pid, SIGUSR2);
		i--;
	}
}

int	main(int ac, char **av)
{
	int	pid;
	int	i;

	if (ac != 3)
	{
		ft_putstr_fd("Uso: ./client [PID del servidor] [mensaje]\n", 2);
		return (1);
	}
	pid = ft_atoi(av[1]);
	if (pid <= 0)
	{
		ft_putstr_fd("Error: PID incorrecto\n", 2);
		return (1);
	}
	i = 0;
	while (av[2][i])
	{
		send_char(pid, av[2][i]);
		i++;
	}
	send_char(pid, '\0');
	return (0);
}
