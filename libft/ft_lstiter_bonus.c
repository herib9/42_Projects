/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmolina <hmolina@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 21:42:34 by hmolina           #+#    #+#             */
/*   Updated: 2025/07/15 21:49:55 by hmolina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//itera una lista enlazada y aplica una funcion a cada nodo

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	while (lst)
	{
		f(lst->content);
		lst = lst->next;
	}
}
