/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_two.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leiamart <leiamart@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 19:36:58 by leiamart          #+#    #+#             */
/*   Updated: 2025/10/15 19:37:00 by leiamart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

size_t	ft_strlen(const char *c)
{
	size_t	i;

	i = 0;
	while (c[i] != '\0')
		i++;
	return (i);
}

void	ft_putstr_fd(char *c, int i)
{
	write(i, c, ft_strlen(c));
}

void	ft_putchar_fd(char c, int i)
{
	write(i, &c, 1);
}

void	ft_putendl_fd(char *c, int i)
{
	ft_putstr_fd(c, i);
	ft_putchar_fd('\n', i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		x;
	char	*a;

	i = 0;
	x = 0;
	if (!s1 || !s2)
		return (NULL);
	a = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!a)
		return (NULL);
	while (s1[i] != '\0')
	{
		a[i] = s1[i];
		i++;
	}
	while (s2[x] != '\0')
	{
		a[i + x] = s2[x];
		x++;
	}
	a[i + x] = '\0';
	return (a);
}
