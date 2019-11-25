/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jomartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 13:00:33 by jomartin          #+#    #+#             */
/*   Updated: 2019/11/11 21:55:21 by jomartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **alst, t_list *new)
{
	t_list *lstend;

	if (!*alst)
		ft_lstadd_front(alst, new);
	lstend = ft_lstlast(*alst);
	lstend->next = new;
	new->next = NULL;
}
