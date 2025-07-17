/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmolina <hmolina@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 19:38:25 by hmolina           #+#    #+#             */
/*   Updated: 2025/07/17 19:58:39 by hmolina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

#include <unistd.h>
#include <signal.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

void	ft_putchar_fd (char s, int fd);
void	ft_putstr_fd (char *s, int fd);
void		ft_putnbr_fd(int n, int fd);
int		ft_atoi(char *s);

#endif  