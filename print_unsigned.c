/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_unsigned.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jomartin < jomartin@student.42madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/24 20:19:59 by jomartin          #+#    #+#             */
/*   Updated: 2019/11/24 20:19:59 by jomartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void ft_unbr_l(t_print *p, unsigned int nbr)
{
	if (p->prec > ft_nb_len((int)nbr))
	{
		ft_print_zeros(p->prec - ft_nb_len((int)nbr), t_print *p);
		ft_putnbr_fd((int)nbr, 1);
		p->len = p->len + ft_nb_len((int)nbr);
		if (p->width > p->prec)
		ft_print_spaces(p->width - p->prec, t_print *p);
	}
	else
	{
		ft_putnbr_fd((int)nbr, 1);
		p->len = p->len + ft_nb_len((int)nbr);
		if (p->width > ft_nb_len((int)nbr))
		ft_print_spaces(p->width - ft_nb_len((int)nbr), t_print *p);
	}
}

void ft_unbr_r(t_print *p, unsigned int nbr)
{
	if (p->prec > ft_nb_len((int)nbr))
	{
		if (p->width > p->prec + sign)
			ft_print_spaces(p->width - p->prec, t_print *p);
		ft_print_zeros(p->prec - ft_nb_len((int)nbr), t_print *p);
		ft_putnbr_fd((int)nbr, 1);
		p->len = p->len + ft_nb_len((int)nbr);
	}
	else
	{
		if ((p->width > ft_nb_len((int)nbr)) && p->zero)
			ft_print_zeros(p->prec - ft_nb_len((int)nbr), t_print *p);
		else if (p->width > ft_nb_len((int)nbr))
			ft_print_spaces(p->width - ft_nb_len((int)nbr), t_print *p);
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
