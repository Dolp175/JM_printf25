/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jomartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 12:28:37 by jomartin          #+#    #+#             */
/*   Updated: 2019/11/11 21:56:03 by jomartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*tmp;
	int		i;

	tmp = lst;
	i = ft_lstsize(lst) - 1;
	while (i > 0)
	{
		tmp = tmp->next;
		i--;
	}
	return (tmp);
}
