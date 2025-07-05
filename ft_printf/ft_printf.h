/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmolina <hmolina@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 18:05:53 by hmolina           #+#    #+#             */
/*   Updated: 2025/02/05 22:45:04 by hmolina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <unistd.h>
# include <stdarg.h>

int		ft_printf(const char *str, ...);
int		ft_put_hex(unsigned int n, char format);
int		ft_put_char(int c);
int		ft_put_nbr(long c);
int		ft_put_str(char *str);
int		ft_put_ptr(unsigned long ptr, int flag);
int		ft_num_nosign(unsigned int n);

#endif
