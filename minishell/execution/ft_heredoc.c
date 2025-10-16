/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_heredoc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leiamart <leiamart@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 19:33:58 by leiamart          #+#    #+#             */
/*   Updated: 2025/10/15 19:34:00 by leiamart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*heredoc_line(char *c, char **h, int x)
{
	char	*a;
	char	*v;
	char	*m;
	int		i;

	v = ft_strdup("");
	i = 0;
	while (c[i])
	{
		if (c[i] == '$' && c[i + 1] && (ft_isalpha(c[i + 1])
				|| c[i + 1] == '_' || c[i + 1] == '?'))
			a = manage_env_expansion(&i, c, h, x);
		else
			a = get_literal_segment(&i, c);
		m = ft_strjoin(v, a);
		free(v);
		free(a);
		v = m;
	}
	return (free(c), v);
}

void	set_heredoc_delimiter(t_command *command, t_lexer *lexer)
{
	if (command->split)
		free(command->split);
	command->split = ft_strdup(lexer->next->lxr);
	if (!command->split)
		return ;
	command->here = true;
}

int	redirection_heredoc(t_minishell *ms, t_command *command)
{
	int		i[2];
	char	*c;

	g_signal_flag = 2;
	signal(SIGQUIT, SIG_IGN);
	if (pipe(i) == -1)
		return (perror("Error pipe\n"), 1);
	while (1)
	{
		c = readline("> ");
		if (!c || !ft_strcmp(c, command->split))
		{
			free(c);
			break ;
		}
		c = heredoc_line(c, ms->var, ms->prev_code);
		write(i[1], c, ft_strlen(c));
		write(i[1], "\n", 1);
		free(c);
	}
	close(i[1]);
	if (dup2(i[0], STDIN_FILENO) == -1)
		return (perror("Error heredoc\n"), 1);
	return (close(i[0]), 0);
}
