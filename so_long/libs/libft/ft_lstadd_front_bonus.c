/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmolina <hmolina@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 19:55:29 by hmolina           #+#    #+#             */
/*   Updated: 2025/07/15 21:40:51 by hmolina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//agrega un nuevo elemento al principio de una lista enlazada

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	new->next = *lst;
	*lst = new;
}
