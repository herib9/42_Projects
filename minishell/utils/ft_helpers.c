/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_helpers.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leiamart <leiamart@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 19:33:52 by leiamart          #+#    #+#             */
/*   Updated: 2025/10/15 19:33:53 by leiamart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	printing_exit_error(char *c)
{
	printf("%s\n", c);
	exit (EXIT_FAILURE);
}

void	*protect_memory(size_t i)
{
	void	*v;

	v = malloc(i);
	if (!v)
		printing_exit_error("minishell: Memory error");
	return (v);
}

void	printing_lexer(t_lexer *lexer)
{
	while (lexer)
	{
		printf("Token: [%s]\t", lexer->lxr);
		printf("Type: [%i]\n", lexer->tkn);
		lexer = lexer->next;
	}
}

char	**save_env(char **c)
{
	int		i;
	int		x;
	char	**a;

	i = 0;
	while (c[i])
		i++;
	a = protect_memory(sizeof(char *) * (i + 1));
	i = 0;
	while (c[i])
	{
		a[i] = protect_memory(sizeof (char) * (ft_strlen(c[i]) + 1));
		x = 0;
		while (c[i][x])
		{
			a[i][x] = c[i][x];
			x++;
		}
		a[i][x] = '\0';
		i++;
	}
	a[i] = NULL;
	return (a);
}

void	printing_list_command(t_command *exe)
{
	int	i;

	while (exe)
	{
		i = 0;
		printf("\n  Args: ");
		if (exe->argv)
		{
			while (exe->argv[i])
				printf("[%s], ", exe->argv[i++]);
		}
		else
			printf("[NULL]");
		if (exe->inputf)
			printf("\n  Infile: %s", exe->inputf);
		if (exe->outputf)
			printf("\n  Outfile: %s", exe->outputf);
		if (exe->split)
			printf("\n  Delimiter: %s", exe->split);
		printf("\n  Append: %d", exe->add);
		printf("\n  Heredoc: %d", exe->here);
		printf("\n  Is Built-in: %d\n", exe->core);
		exe = exe->next;
	}
}
