/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing_tokens.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leiamart <leiamart@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 19:35:25 by leiamart          #+#    #+#             */
/*   Updated: 2025/10/15 19:35:27 by leiamart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	extract_wtoken(t_minishell *ms, int *i)
{
	int		x;
	char	*c;

	x = *i;
	while (ms->line[x] != 34 && ms->line[x] != '<'
		&& ms->line[x] != '>' && ms->line[x] != '|'
		&& ms->line[x] != ' ' && ms->line[x] != '\0')
		x++;
	c = ft_substr(ms->line, *i, (x - *i));
	insert_token_end(&ms->lexer, c, 0);
	if (ms->line[x] != '\0' && ms->line[x] != '<'
		&& ms->line[x] != '>' && ms->line[x] != '|'
		&& ms->line[x] != ' ')
		last_tkn(&ms->lexer);
	free(c);
	*i = x;
}

void	shell_lex_input(t_minishell *ms)
{
	int	i;

	i = 0;
	while (ms->line[i])
	{
		if (ms->line[i] == ' ' || ms->line[i] == '\t')
			i++;
		else if (ms->line[i] == '\'' || ms->line[i] == '"')
		{
			if (!single_or_double_quotes(ms, &i))
				break ;
		}
		else if (ms->line[i] == '<' || ms->line[i] == '>')
			parse_token_redirection(ms, &i);
		else if (ms->line[i] == '|')
		{
			insert_token_end(&ms->lexer, "|", 3);
			i++;
		}
		else
			extract_wtoken(ms, &i);
	}
}

void	parsing_token(t_minishell *ms, t_lexer **aux)
{
	t_lexer	*next;

	if ((*aux)->tkn == PI)
	{
		insert_cmd_end(&ms->exe);
		*aux = (*aux)->next;
	}
	else if ((*aux)->tkn == WORD)
	{
		build_cmd_args(ms, *aux, &next);
		*aux = next;
	}
	else if ((*aux)->tkn == RI1 || (*aux)->tkn == RO1
		|| (*aux)->tkn == RI2 || (*aux)->tkn == RO2)
	{
		manage_redirection(ms, *aux, &next);
		*aux = next;
	}
	else
		*aux = (*aux)->next;
}

void	var_in_token(t_minishell *ms, t_lexer *lexer)
{
	t_var	*v;

	v = start_var_struct();
	while (lexer->lxr[0] && ft_strchr(lexer->lxr, '$')
		&& lexer->lxr[modified_strchr(lexer->lxr, '$')] != ' '
		&& lexer->lxr[modified_strchr(lexer->lxr, '$')] != '\"')
	{
		v->begin = modified_strchr(lexer->lxr, '$');
		if (lexer->lxr[v->begin] == '?')
		{
			manage_status(ms, lexer);
			continue ;
		}
		v->limit = v->begin + get_var_name_len(&lexer->lxr[v->begin]);
		v->env = ft_substr_two(lexer->lxr, v->begin,
				(v->limit - v->begin + 1));
		v->status = giveme_value_env(ms->var, v->env);
		free(v->env);
		v->env = NULL;
		if (!v->status)
			v->status = ft_strdup("");
		put_expand_value_token(v, lexer);
	}
	free_var_exp(v);
}

void	put_expand_value_token(t_var *var, t_lexer *lexer)
{
	char		*a;
	int			i;
	size_t		x;

	a = protect_memory(ft_strlen(lexer->lxr) - (var->limit - var->begin + 1)
			+ ft_strlen(var->status) + 1);
	i = -1;
	x = -1;
	while (++i < var->begin - 1)
		a[i] = lexer->lxr[i];
	while (++x < ft_strlen(var->status))
	{
		a[i] = var->status[x];
		i++;
	}
	x = var->limit;
	while (lexer->lxr[x])
		a[i++] = lexer->lxr[x++];
	free(var->status);
	var->status = NULL;
	a[i] = '\0';
	free(lexer->lxr);
	lexer->lxr = a;
}
