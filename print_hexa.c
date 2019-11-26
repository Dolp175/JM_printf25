/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hexa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jomartin < jomartin@student.42madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 10:29:09 by jomartin          #+#    #+#             */
/*   Updated: 2019/11/25 15:11:20 by jomartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void ft_hexa_l(t_print *p, int lcase, long long int i, int j)
{
	if (p->prec > j)
	{
		ft_print_zeros(p->prec - j, p);
		ft_itoa_x(i, lcase, p);
		if (p->width > p->prec)
			ft_print_spaces(p->width - p->prec, p);
	}
	else
	{
		ft_itoa_x(i, lcase, p);
		if (p->width > j)
			ft_print_spaces(p->width - j, p);
	}
}

void ft_hexa_r(t_print *p, int lcase, long long int i, int j)
{
	if (!p->prec)
	{
		if (p->width > j)
		{
			if (p->zero)
				ft_print_zeros(p->width - j, p);
			else
				ft_print_spaces(p->width - j, p);
		}
		ft_itoa_x(i, lcase, p);
	}
	else
	{
		if (p->prec > j)
		{
			if (p->width > p->prec)
				ft_print_spaces(p->width - p->prec, p);
			ft_print_zeros(p->prec - j, p);
		}
		else
			ft_print_spaces(p->width - j, p);
		ft_itoa_x(i, lcase, p);
	}
}

int ft_print_hexa(t_print *p)
{
	long long int i;
	int j;
	int lcase;

	i = (long long int)va_arg(p->args, void *);
	j = ft_nbx_len(i);
	lcase = 0;
	if (i == 0 && p->point == 1 && !p->prec)
	{
		if (p->width)
			ft_print_spaces(p->width, p);
		return (1);
	}
	if (p->form[p->tlen] == 'X')
		lcase = 1;
	if (p->left)
		ft_hexa_l(p, lcase, i, j);
	else
		ft_hexa_r(p, lcase, i, j);
	return (1);
}
