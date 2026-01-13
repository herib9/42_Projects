/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dash1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmolina <hmolina@student.42malaga.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 11:16:35 by hmolina           #+#    #+#             */
/*   Updated: 2025/11/17 11:16:35 by hmolina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

int		is_lower(char c);
int		is_digit(char c);
int		ft_strlen(char *s);

char	atbash_char(char c)
{
	if (is_lower(c))
		return ('z' - (c - 'a'));
	if (is_digit(c))
		return (c);
	return (0);
}

char	*clean_input(char *s)
{
	int		i;
	int		j;
	int		len;
	char	*out;

	i = 0;
	j = 0;
	len = ft_strlen(s);
	out = malloc(len + 1);
	if (!out)
		return (NULL);
	while (s[i])
	{
		if (is_lower(s[i]) || is_digit(s[i]))
			out[j++] = s[i];
		else if (s[i] >= 'A' && s[i] <= 'Z')
			out[j++] = s[i] + 32;
		i++;
	}
	out[j] = '\0';
	return (out);
}

void	fill_encoded(char *clean, char *encoded)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	j = 0;
	count = 0;
	while (clean[i])
	{
		if (count == 5)
		{
			encoded[j++] = ' ';
			count = 0;
		}
		encoded[j++] = atbash_char(clean[i]);
		count++;
		i++;
	}
	encoded[j] = '\0';
}

char	*encode(char *s)
{
	char	*clean;
	char	*encoded;
	int		len;

	clean = clean_input(s);
	if (!clean || clean[0] == '\0')
	{
		if (clean)
			free(clean);
		return (NULL);
	}
	len = ft_strlen(clean);
	encoded = malloc(len + len / 5 + 2);
	if (!encoded)
	{
		free(clean);
		return (NULL);
	}
	fill_encoded(clean, encoded);
	free(clean);
	return (encoded);
}
