/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_valid.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jomartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 11:44:26 by jomartin          #+#    #+#             */
/*   Updated: 2019/11/20 14:07:05 by jomartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int is_valid(t_print *p)
{
	if (ft_strchr(p->form, '%'))
	{
		write(1, p->form, ft_strlen(p->form));
		p->len = ft_strlen(p->form);
		return(0);
	}
}

