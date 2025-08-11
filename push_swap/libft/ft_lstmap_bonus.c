/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmolina <hmolina@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 21:45:17 by hmolina           #+#    #+#             */
/*   Updated: 2025/07/15 21:49:13 by hmolina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*crea una nueva lista enlazada aplicando una funcion de transformacion a cada
  elemento de la lista original*/

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*res;
	t_list	*temp;

	if (!lst || !f || !del)
		return (NULL);
	res = NULL;
	while (lst)
	{
		temp = ft_lstnew(f(lst->content));
		if (!temp)
		{
			ft_lstclear(&res, del);
			return (NULL);
		}
		ft_lstadd_back(&res, temp);
		lst = lst->next;
	}
	return (res);
}
