/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_pointer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jomartin < jomartin@student.42madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/24 20:03:57 by jomartin          #+#    #+#             */
/*   Updated: 2019/11/25 15:05:15 by jomartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void ft_point_l(t_print *p, long long int i, int j)
{
	p->len = p->len + write(1, "0x", 2);
	if (p->prec > (j - 2))
	{
		ft_print_zeros(p->prec - j - 2, p);
		ft_itoa_x(i, 0, p);
		if (p->width > p->prec + 2)
			ft_print_spaces(p->width - (p->prec + 2), p);
	}
	else
	{
		ft_itoa_x(i, 0, p);
		if (p->width > j)
			ft_print_spaces(p->width - j, p);
	}
}

void ft_point_r(t_print *p, long long int i, int j)
{
	if (p->prec > (j - 2))
	{
		if (p->width > p->prec + 2)
			ft_print_spaces(p->width - (p->prec + 2), p);
		p->len = p->len + write(1, "0x", 2);
		ft_print_zeros(p->prec - j - 2, p);
		ft_itoa_x(i, 0, p);
	}
	else
	{
		if (p->width > j)
			ft_print_spaces(p->width - j, p);
		p->len = p->len + write(1, "0x", 2);
		ft_itoa_x(i, 0, p);
	}
}

int ft_print_pointer(t_print *p)
{
	long long int i;
	int j;

	i = (long long int)va_arg(p->args, void *);
		j = ft_nbx_len(i) + 2;
	if (p->left)
		ft_point_l(p, i, j);
	else
		ft_point_r(p, i, j);
	return (1);
}
