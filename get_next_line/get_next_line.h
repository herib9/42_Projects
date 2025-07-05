/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmolina <hmolina@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 18:04:21 by hmolina           #+#    #+#             */
/*   Updated: 2025/02/21 19:58:45 by hmolina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

size_t	ft_strlen(char *s);
char	*ft_strchr(char *s, int c);
char	*ft_strjoin(char *s1, char *s2);
char	*get_next_line(int fd);

#endif

/*
size_t	ft_strlen(char *s);
** Calcula la longitud de una cadena
** @param s: cadena a medir
** @return: longitud de la cadena
** Complejidad temporal: O(n)
** Complejidad espacial: O(1)
*/
/*
char	*ft_strchr(char *s, int c);
** Busca la primera ocurrencia de un carácter en una cadena
** @param s: cadena donde buscar
** @param c: carácter a buscar
** @return: puntero a la posición del carácter o NULL si no se encuentra
** Complejidad temporal: O(n)
** Complejidad espacial: O(1)
*/
/*
char	*ft_strjoin(char *s1, char *s2);
** Concatena dos strings liberando la primera
** @param s1: primera cadena (será liberada)
** @param s2: segunda cadena
** @return: nueva cadena concatenada o NULL si hay error
** Complejidad temporal: O(n + m) donde n y m son las longitudes de las cadenas
** Complejidad espacial: O(n + m)
*/
/* 
char	*get_next_line(int fd);
** Función principal que lee una línea de un descriptor de archivo
** @param fd: descriptor de archivo a leer
** @return: línea leída o NULL si hay error o EOF
** Complejidad temporal: O(n) donde n es la longitud de la línea
** Complejidad espacial: O(n + BUFFER_SIZE)
 */
