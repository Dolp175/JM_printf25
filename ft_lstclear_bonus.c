/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jomartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 13:58:54 by jomartin          #+#    #+#             */
/*   Updated: 2019/11/11 21:58:14 by jomartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list *tmp;
	t_list *tmpnext;

	tmp = *lst;
	while (tmp)
	{
		tmpnext = tmp->next;
		del((void*)tmp->content);
		free(tmp);
		tmp = tmpnext;
	}
	*lst = NULL;
}
