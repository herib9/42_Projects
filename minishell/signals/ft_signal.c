/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_signal.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leiamart <leiamart@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 19:36:09 by leiamart          #+#    #+#             */
/*   Updated: 2025/10/15 19:36:11 by leiamart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	g_signal_flag;

void	parse_exit_signal(int i, t_minishell *ms)
{
	if (WIFEXITED(i))
		ms->code = WEXITSTATUS(i) % 256;
	else if (WIFSIGNALED(i))
		ms->code = (128 + WTERMSIG(i)) % 256;
}

void	manage_sigquit(void)
{
	if (g_signal_flag == 1)
	{
		write(1, "Quit (core dumped)\n", 20);
		rl_on_new_line();
		rl_replace_line("", 0);
	}
}

void	manage_signal(int i)
{
	if (g_signal_flag == 0 || g_signal_flag == 130)
	{
		g_signal_flag = 128 + i;
		write(1, "\n", 1);
		rl_on_new_line();
		rl_replace_line("", 0);
		rl_redisplay();
	}
	else if (g_signal_flag == 1)
	{
		g_signal_flag = 128 + i;
		write(1, "\n", 1);
		rl_replace_line("", 0);
	}
	else if (g_signal_flag == 2)
	{
		g_signal_flag = 128 + i;
		write(1, "\n", 1);
		exit(130);
	}
}

void	init_signals(void)
{
	g_signal_flag = 0;
	signal(SIGINT, manage_signal);
	signal(SIGQUIT, SIG_IGN);
}
