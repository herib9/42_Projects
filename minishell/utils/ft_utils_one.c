/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_one.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leiamart <leiamart@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 19:36:40 by leiamart          #+#    #+#             */
/*   Updated: 2025/10/15 19:36:42 by leiamart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_strdup(const char *s1)
{
	size_t	i;
	char	*c;

	i = 0;
	c = (char *)malloc(ft_strlen(s1) + 1);
	if (!c)
		return (NULL);
	while (s1[i])
	{
		c[i] = s1[i];
		i++;
	}
	c[i] = '\0';
	return (c);
}

int	ft_isalpha(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1);
	else
		return (0);
}

int	ft_isalnum(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')
		|| (c >= '0' && c <= '9'))
		return (1);
	else
		return (0);
}

char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if ((char)c == '\0')
		return ((char *)s);
	return (0);
}

char	*ft_strnstr(const char *s, const char *w, size_t c)
{
	size_t	i;
	size_t	x;

	i = 0;
	x = 0;
	if (w[0] == '\0' || w == NULL)
		return ((char *)s);
	while (s[i] != '\0' && i < c)
	{
		if (s[i] == w[x])
		{
			while (s[i + x] == w[x] && i + x < c)
			{
				if (w[x + 1] == '\0')
					return ((char *)s + i);
				x++;
			}
			x = 0;
		}
		i++;
	}
	return (NULL);
}
