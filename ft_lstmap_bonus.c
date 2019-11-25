/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jomartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 15:47:18 by jomartin          #+#    #+#             */
/*   Updated: 2019/11/11 21:59:09 by jomartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void*))
{
	t_list *newlist;
	t_list *firstnl;

	firstnl = NULL;
	while (lst)
	{
		newlist = ft_lstnew(f((void*)lst->content));
		if (!newlist)
			ft_lstclear(&firstnl, del);
		newlist->next = firstnl;
		firstnl = newlist;
		lst = lst->next;
	}
	return (firstnl);
}
