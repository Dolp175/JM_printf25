/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_number.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jomartin < jomartin@student.42madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 17:47:07 by jomartin          #+#    #+#             */
/*   Updated: 2019/11/25 23:27:30 by jomartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void ft_intmin_r(t_print *p)
{
	if (p->prec > 10)
	{
		if (p->width > p->prec + 1)
			ft_print_spaces(p->width - p->prec - 1, p);
		p->len = p->len + write(1, "-", 1);
		ft_print_zeros(p->prec - 10, p);
		ft_putstr_fd("2147483648", 1);
		p->len = p->len + 10;
	}
	else
	{
		if ((p->width > 11) && p->zero)
			ft_print_zeros(p->prec - 10, p);
		else if (p->width > 11)
			ft_print_spaces(p->width - 11, p);
		p->len = p->len + write(1, "-", 1);
		ft_putstr_fd("2147483648", 1);
		p->len = p->len + 10;
	}
}

void ft_print_intmin(t_print *p)
{
	if (p->left == 0)
	{
		p->len = p->len + write(1, "-", 1);
		if (p->prec > 10)
		{
			ft_print_zeros(p->prec - 10, p);
			ft_putstr_fd("2147483648", 1);
			p->len = p->len + 10;
			if (p->width > p->prec + 1)
				ft_print_spaces(p->width - p->prec - 1, p);
		}
		else
		{
			ft_putstr_fd("2147483648", 1);
			p->len = p->len + 10;
			if (p->width > p->prec + 1)
				ft_print_spaces(p->width - p->prec - 1, p);
		}
	}
	else
		ft_intmin_r(p);
}

void ft_nbr_l(t_print *p, int nbr, int sign)
{
	if (sign)
		p->len = p->len + write(1, "-", 1);
	if (p->prec > ft_nb_len(nbr))
	{
		ft_print_zeros(p->prec - ft_nb_len(nbr), p);
		ft_putnbr_fd(nbr, 1);
		p->len = p->len + ft_nb_len(nbr);
		if (p->width > p->prec + sign)
			ft_print_spaces(p->width - p->prec - sign, p);
	}
	else
	{
		ft_putnbr_fd(nbr, 1);
		p->len = p->len + ft_nb_len(nbr);
		if (p->width > ft_nb_len(nbr) + sign)
			ft_print_spaces(p->width - ft_nb_len(nbr) - sign, p);
	}
}

void ft_nbr_r(t_print *p, int nbr, int sign)
{
	if (p->prec > ft_nb_len(nbr))
	{
		if (p->width > p->prec + sign)
			ft_print_spaces(p->width - p->prec - sign, p);
		if (sign)
			p->len = p->len + write(1, "-", 1);
		ft_print_zeros(p->prec - ft_nb_len(nbr), p);
		ft_putnbr_fd(nbr, 1);
		p->len = p->len + ft_nb_len(nbr);
	}
	else
	{
		if ((p->width > ft_nb_len(nbr) + sign) && p->zero && !p->point)
			ft_print_zeros(p->width - ft_nb_len(nbr) - sign, p);
		else if (p->width > ft_nb_len(nbr) + sign)
			ft_print_spaces(p->width - ft_nb_len(nbr) - sign, p);
		if (sign)
			p->len = p->len + write(1, "-", 1);
		ft_putnbr_fd(nbr, 1);
		p->len = p->len + ft_nb_len(nbr);
	}
}


int ft_print_number(t_print *p)
{
	int nbr;
	int sign;

	nbr = va_arg(p->args, int);
	sign = 0;
	if (nbr < 0)
	{
		if (nbr == -2147483648)
		{
			ft_print_intmin(p);
			return (1);
		}
		sign = 1;
		nbr = nbr * (-1);
	}
	if (nbr == 0 && p->point && !p->prec)
		return (print_nbr_zero(p));
	if (p->left == 0)
		ft_nbr_r(p, nbr, sign);
	else
		ft_nbr_l(p, nbr, sign);
	return (1);
}
