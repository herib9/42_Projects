/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmolina <hmolina@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 19:37:20 by hmolina           #+#    #+#             */
/*   Updated: 2025/07/17 23:37:06 by hmolina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	ft_atoi (char *s)
{
	int	i;
	int	num;
	int	signo;

	i = 0;
	num = 0;
	signo = 1;
	while (s[i] <= 32)
		i++;
	if (s[i] == '-' || s[i] == '+')
	{
		if (s[i] == '-')
		{
			signo = -1;
		}
		i++;
	}
	while (s[i] >= '0' && s[i] <= '9')
	{
		num = num * 10 + (s[i] - '0');
		i++;
	}
	return (num * signo);
}

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