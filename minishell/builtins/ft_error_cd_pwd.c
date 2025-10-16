/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error_cd_pwd.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leiamart <leiamart@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 19:32:41 by leiamart          #+#    #+#             */
/*   Updated: 2025/10/15 19:32:42 by leiamart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	parsing_error_cd_pwd(t_minishell *ms, char *z, char *c)
{
	if (!z)
	{
		ft_putstr_fd("minishell: cd: error retrieving current directory: ", 2);
		ft_putstr_fd("getcwd: cannot access parent directories: ", 2);
		ft_putstr_fd("No such file or directory\n", 2);
		ms->code = 1;
		return (1);
	}
	if (chdir(c) < 0)
	{
		perror("minishell: cd");
		free(z);
		ms->code = 1;
		return (1);
	}
	return (0);
}

int	parsing_error_cd_home(t_minishell *ms, char *c, char *z)
{
	perror("minishell: cd");
	free(z);
	free(c);
	ms->code = 1;
	return (1);
}
