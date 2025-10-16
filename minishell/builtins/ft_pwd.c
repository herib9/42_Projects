/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leiamart <leiamart@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 19:35:44 by leiamart          #+#    #+#             */
/*   Updated: 2025/10/15 19:35:46 by leiamart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	switch_directory_oldpwd(t_minishell *ms, char *c)
{
	char	*z;
	char	*a;

	z = getcwd(NULL, 0);
	if (parsing_error_cd_pwd(ms, z, c))
	{
		ms->code = 1;
		return (1);
	}
	a = getcwd(NULL, 0);
	if (!a)
	{
		manage_env_export(ms->var, "PWD=", 1);
		free (z);
		ms->code = 1;
		return (1);
	}
	if (!refresh_pwd(ms, z, a))
		ms->code = 0;
	else
		ms->code = 1;
	free(z);
	free(a);
	return (0);
}

int	backtrack_pwd(t_minishell *ms)
{
	int		i;
	char	*z;

	z = giveme_value_env(ms->var, "OLDPWD");
	if (!z)
	{
		printf("minishell: cd: OLDPWD not set\n");
		ms->code = 1;
		return (1);
	}
	printf("%s\n", z);
	i = switch_directory_oldpwd(ms, z);
	free(z);
	return (i);
}

int	refresh_pwd(t_minishell *ms, char *z, char *a)
{
	char	*c;

	c = ft_strjoin("OLDPWD=", z);
	if (!c)
		return (1);
	ms->var = manage_env_export(ms->var, c, 1);
	free(c);
	c = ft_strjoin("PWD=", a);
	if (!c)
		return (1);
	ms->var = manage_env_export(ms->var, c, 1);
	free(c);
	return (0);
}

int	pwd_builtin(void)
{
	char	*c;

	c = getcwd(NULL, 0);
	if (!c)
	{
		perror("pwd");
		return (1);
	}
	printf("%s\n", c);
	free(c);
	return (0);
}
