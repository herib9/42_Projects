/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leiamart <leiamart@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 19:31:38 by leiamart          #+#    #+#             */
/*   Updated: 2025/10/15 19:31:40 by leiamart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	env_home_cd(t_minishell *ms, char *c, char *a)
{
	char	*x;
	char	*z;

	if (c)
	{
		z = ft_strjoin("OLDPWD=", c);
		manage_env_export(ms->var, z, 1);
		free(z);
	}
	x = ft_strjoin("PWD=", a);
	manage_env_export(ms->var, x, 1);
	free(x);
}

int	manage_home(t_minishell *ms)
{
	char	*c;
	char	*a;
	char	*z;

	c = giveme_value_env(ms->var, "HOME");
	if (!c)
	{
		printf("minishell: cd: HOME not set\n");
		ms->code = 1;
		return (1);
	}
	z = getcwd(NULL, 0);
	if (chdir(c) < 0)
		return (parsing_error_cd_home(ms, c, z));
	a = getcwd(NULL, 0);
	if (!a)
		a = ft_strdup(c);
	env_home_cd(ms, z, a);
	free(c);
	free(z);
	free(a);
	ms->code = 0;
	return (0);
}

int	cd_builtin(t_minishell *ms, t_command *command)
{
	char	*a;

	if (command->argv[2])
	{
		ft_putstr_fd("minishell: cd: too many arguments\n", 2);
		return (1);
	}
	a = command->argv[1];
	if (!a || !ft_strcmp_two(a, "~"))
		return (manage_home(ms));
	if (!ft_strcmp_two(a, "-"))
		return (backtrack_pwd(ms));
	return (switch_directory_oldpwd(ms, a));
}
