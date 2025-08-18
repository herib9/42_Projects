/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmolina <hmolina@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 15:54:46 by hmolina           #+#    #+#             */
/*   Updated: 2025/07/15 19:23:04 by hmolina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*concatena múltiples strings en uno solo, separándolos con un delimitador, de
forma personalizada*/

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	char	*tab;

	i = 0;
	j = 0;
	tab = ft_calloc((ft_strlen(s1) + ft_strlen(s2) + 1), sizeof(char));
	if (!tab)
		return (NULL);
	while (s1[i])
		tab[j++] = s1[i++];
	i = 0;
	while (s2[i])
		tab[j++] = s2[i++];
	return (tab);
}

/* int	main(void)
{
	char 	*s1 = "techno";
	char	*s2 = " is the ";
	char	*s3 = "answer";
	char	*res;
	res = ft_strjoin(ft_strjoin(s1, s2), s3);
	printf("%s", res);
	return (0);
} */
