/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_more_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leiamart <leiamart@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 19:34:20 by leiamart          #+#    #+#             */
/*   Updated: 2025/10/15 19:34:21 by leiamart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;

	i = 0;
	if (dstsize == 0)
	{
		while (src[i])
			i++;
		return (i);
	}
	while (i < dstsize - 1 && src[i] != '\0')
	{
		dst[i] = src[i];
		i++;
	}
	if (i < dstsize)
		dst[i] = '\0';
	while (src[i] != '\0')
		i++;
	return (i);
}

static unsigned int	ft_len_n(int i)
{
	unsigned int	x;

	x = 0;
	if (i == 0)
		return (1);
	if (i < 0)
		x += 1;
	while (i != 0)
	{
		i /= 10;
		x++;
	}
	return (x);
}

char	*ft_itoa(int n)
{
	char			*c;
	unsigned int	i;
	unsigned int	x;

	x = ft_len_n(n);
	c = (char *)malloc(sizeof(char) * (x + 1));
	if (!c)
		return (NULL);
	if (n < 0)
	{
		c[0] = '-';
		i = -n;
	}
	else
		i = n;
	if (i == 0)
		c[0] = '0';
	c[x] = '\0';
	while (i != 0)
	{
		c[x - 1] = (i % 10) + '0';
		i = i / 10;
		x--;
	}
	return (c);
}

int	ft_atoi(const char *c)
{
	int	i;
	int	x;
	int	m;

	i = 0;
	x = 1;
	m = 0;
	while (c[i] == ' ' || (c[i] >= 9 && c[i] <= 13))
		i++;
	if (c[i] == '-' || c[i] == '+')
	{
		if (c[i] == '-')
			x *= -1;
		i++;
	}
	while (c[i] >= '0' && c[i] <= '9')
	{
		m = (c[i] - '0') + (m * 10);
		i++;
	}
	return (m * x);
}

int	ft_strncmp(const char *s1, const char *s2, size_t i)
{
	while (*s1 != '\0' && *s1 == *s2 && i > 0)
	{
		s1++;
		s2++;
		i--;
	}
	if (i == 0)
		return (0);
	return (*(unsigned char *)s1 - *(unsigned char *)s2);
}
