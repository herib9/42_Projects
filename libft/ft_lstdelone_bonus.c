/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmolina <hmolina@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 21:36:59 by hmolina           #+#    #+#             */
/*   Updated: 2025/07/15 21:38:53 by hmolina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//elimina y libera un unico nodo de una lista enlazada

#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	del(lst->content);
	free(lst);
}
