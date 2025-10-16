/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leiamart <leiamart@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 19:36:17 by leiamart          #+#    #+#             */
/*   Updated: 2025/10/15 19:36:19 by leiamart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_substr(char const *s, unsigned int b, size_t l)
{
	size_t	i;
	size_t	x;
	char	*c;

	i = 0;
	x = 0;
	if (b > ft_strlen(s))
		l = 0;
	else if (l > (ft_strlen(s) - b))
		l = ft_strlen(s) - b;
	c = malloc(l + 1);
	if (!c)
		return (NULL);
	while (s[i])
	{
		if (i >= b && x < l)
		{
			c[x] = s[i];
			x++;
		}
		i++;
	}
	c[x] = '\0';
	return (c);
}

static size_t	counting_w(char *a, char c)
{
	size_t	x;
	size_t	i;

	if (!a)
		return (0);
	if (!ft_strlen(a))
		return (0);
	i = 0;
	x = a[i] != c;
	while (a[i])
	{
		x += (a[i] == c && a[i + 1] != c && a[i + 1] != '\0');
		i++;
	}
	return (x);
}

static int	until_delimit(char const *a, int i, char c)
{
	int	x;

	x = 0;
	while (a[i])
	{
		if (a[i] == c || a[i] == '\0')
			return (x);
		i++;
		x++;
	}
	return (x);
}

char	**ft_split(char const *a, char c)
{
	size_t	i;
	size_t	x;
	char	**y;

	y = ft_calloc(counting_w((char *)a, c) + 1, sizeof(char *));
	if (!y || !a)
		return (NULL);
	i = 0;
	x = 0;
	while (x < counting_w((char *)a, c))
	{
		while (a[i] == c)
			i++;
		y[x] = ft_substr(a, i, until_delimit(a, i, c));
		if (!y[x])
		{
			while (x > 0)
				free(y[--x]);
			free(y);
			return (NULL);
		}
		i = i + until_delimit(a, i, c) + 1;
		x++;
	}
	return (y);
}
