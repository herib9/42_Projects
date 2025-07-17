/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmolina <hmolina@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 19:37:37 by hmolina           #+#    #+#             */
/*   Updated: 2025/07/17 23:57:54 by hmolina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	process_char(char add_char, char *buffer, int *buffer_position)
{
	if (add_char == '\0')
	{
		if (*buffer_position > 0)
		{

			write(1, buffer, *buffer_position);
			write(1, "\n", 1);
			*buffer_position = 0;
		}
	}
	else
	{
		buffer[(*buffer_position)++] = add_char;
		if (*buffer_position >= 1023) // || add_char == '\n')
		{
			write(1, buffer, *buffer_position);
			*buffer_position = 0;
		}
	}
}

void	handle_signal(int signum)
{
	static char	add_char = 0;
	static int	add_bit_count = 0;
	static char	buffer[10000] = {0};
	static int	buffer_position = 0;

	if (signum == SIGUSR1)
		add_char = add_char << 1;
	else if (signum == SIGUSR2)
		add_char = (add_char << 1) | 1;
	add_bit_count++;
	if (add_bit_count == 8)
	{
		process_char(add_char, buffer, &buffer_position);
		add_char = 0;
		add_bit_count = 0;
	}
}

int	main(void)
{
	int	pid;
	
	pid = getpid();
	printf("%s\n", "WELCOME 2 The MINITALK HERIB9\n");
	write(1, "Your PID is: ", 13);
	ft_putnbr_fd(pid, 1);
	write(1, ".\n", 2);
	signal(SIGUSR1, handle_signal);
	signal(SIGUSR2, handle_signal);
	while (1)
		pause();
	return (0);
}