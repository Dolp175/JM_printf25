/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reset_struct.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jomartin < jomartin@student.42madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 12:14:49 by jomartin          #+#    #+#             */
/*   Updated: 2019/11/25 14:51:31 by jomartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void ini_struct(t_print *p)
{
	p->left = 0;
	p->zero = 0;
	p->point = 0;
	p->prec = 0;
	p->width = 0;
	p->len = 0;
	p->tlen = 0;
}

void reset_struct(t_print *p)
{
	p->left = 0;
	p->zero = 0;
	p->point = 0;
	p->prec = 0;
	p->width = 0;
}
