/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dash2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmolina <hmolina@student.42malaga.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 11:16:35 by hmolina           #+#    #+#             */
/*   Updated: 2025/11/17 11:16:35 by hmolina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

int		ft_strlen(char *s);
int		ft_strcmp(char *s1, char *s2);
void	putstr(char *s);
char	atbash_char(char c);
char	*clean_input(char *s);
void	fill_encoded(char *clean, char *encoded);
char	*encode(char *s);
char	*decode(char *s);
void	free_and_decode(char *clean, char *decoded, int len);

int	validate_input(int argc, char **argv)
{
	if (argc != 3)
	{
		write(1, "Error: Incorrect number of arguments\n", 38);
		return (0);
	}
	if (!argv[2] || argv[2][0] == '\0')
	{
		write(1, "Error\n", 6);
		return (0);
	}
	if (!ft_strlen(argv[1]) || !ft_strlen(argv[2]))
	{
		write(1, "Error\n", 6);
		return (0);
	}
	return (1);
}

char	*get_result(char **argv)
{
	if (argv[1][0] == 'e' && !ft_strcmp(argv[1], "encode"))
		return (encode(argv[2]));
	else if (argv[1][0] == 'd' && !ft_strcmp(argv[1], "decode"))
		return (decode(argv[2]));
	write(1, "Error\n", 6);
	return (NULL);
}

void	free_and_decode(char *clean, char *decoded, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		decoded[i] = atbash_char(clean[i]);
		i++;
	}
	decoded[len] = '\0';
	free(clean);
}

char	*decode(char *s)
{
	char	*clean;
	int		len;
	char	*decoded;

	clean = clean_input(s);
	if (!clean)
	{
		return (NULL);
	}
	if (clean[0] == '\0')
	{
		free(clean);
		return (NULL);
	}
	len = ft_strlen(clean);
	decoded = malloc(len + 1);
	if (!decoded)
	{
		free(clean);
		return (NULL);
	}
	free_and_decode(clean, decoded, len);
	return (decoded);
}

int	main(int argc, char **argv)
{
	char	*result;

	if (!validate_input(argc, argv))
		return (0);
	result = get_result(argv);
	if (!result)
	{
		write(1, "Error\n", 6);
		return (0);
	}
	putstr(result);
	write(1, "\n", 1);
	free(result);
	return (0);
}
