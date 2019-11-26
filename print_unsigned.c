/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_unsigned.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jomartin < jomartin@student.42madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/24 20:19:59 by jomartin          #+#    #+#             */
/*   Updated: 2019/11/25 15:03:21 by jomartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void ft_unbr_l(t_print *p, unsigned int nbr)
{
	if (p->prec > ft_nb_len((int)nbr))
	{
		ft_print_zeros(p->prec - ft_nb_len((int)nbr), p);
		ft_putnbr_fd((int)nbr, 1);
		p->len = p->len + ft_nb_len((int)nbr);
		if (p->width > p->prec)
		ft_print_spaces(p->width - p->prec, p);
	}
	else
	{
		ft_putnbr_fd((int)nbr, 1);
		p->len = p->len + ft_nb_len((int)nbr);
		if (p->width > ft_nb_len((int)nbr))
		ft_print_spaces(p->width - ft_nb_len((int)nbr), p);
	}
}

void ft_unbr_r(t_print *p, unsigned int nbr)
{
	if (p->prec > ft_nb_len((int)nbr))
	{
		if (p->width > p->prec)
			ft_print_spaces(p->width - p->prec, p);
		ft_print_zeros(p->prec - ft_nb_len((int)nbr), p);
		ft_putnbr_fd((int)nbr, 1);
		p->len = p->len + ft_nb_len((int)nbr);
	}
	else
	{
		if ((p->width > ft_nb_len((int)nbr)) && p->zero && !p->point)
			ft_print_zeros(p->width - ft_nb_len((int)nbr), p);
		else if (p->width > ft_nb_len((int)nbr))
			ft_print_spaces(p->width - ft_nb_len((int)nbr), p);
		ft_putnbr_fd((int)nbr, 1);
		p->len = p->len + ft_nb_len((int)nbr);
	}
}

int ft_print_unsigned(t_print *p)
{
	unsigned int u;

	u = va_arg(p->args, unsigned int);
	if (u == 0 && p->point && !p->prec)
		return (print_nbr_zero(p));
	if (p->left == 0)
		ft_unbr_r(p, u);
	else
		ft_unbr_l(p, u);
	return (1);
}
