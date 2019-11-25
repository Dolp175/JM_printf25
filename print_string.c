/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_string.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jomartin < jomartin@student.42madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/24 16:49:26 by jomartin          #+#    #+#             */
/*   Updated: 2019/11/25 19:50:35 by jomartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_str_l(t_print *p, char *c)
{
	int len;

	len = ft_strlen(c);
	if (p->point && p->prec < len)
	{
		p->len = p->len + write(1, c, p->prec);
		if (p->width > p->prec)
			ft_print_spaces(p->width - p->prec, p);
	}
	else
	{
		p->len = p->len + write(1, c, len);
		if (p->width > len)
			ft_print_spaces(p->width - len, p);
	}
}

void	ft_str_r(t_print *p, char *c)
{
	int len;
	len = ft_strlen(c);
	if (p->point && p->prec < len)
	{
		if (p->width > p->prec)
			ft_print_spaces(p->width - p->prec, p);
		p->len = p->len + write(1, c, p->prec);
	}
	else
	{
		if (p->width > len)
			ft_print_spaces(p->width - len, p);
		p->len = p->len + write(1, c, len);
	}
}

int ft_print_str(t_print *p)
{
	char *c;

	c = va_arg(p->args, char*);
	if (!c)
		c = "(null)";
	if (ft_strlen(c) == 0)
		return (1);
	if (p->left == 0)
		ft_str_r(p, c);
	else
		ft_str_l(p, c);
	return (1);
}
