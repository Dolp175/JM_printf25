/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_arg.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jomartin < jomartin@student.42madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 17:36:12 by jomartin          #+#    #+#             */
/*   Updated: 2019/11/25 19:50:21 by jomartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int check_type(t_print *p)
{
	if (p->form[p->tlen] == 'd' || p->form[p->tlen] == 'i')
	   return(ft_print_number(p));
	if (p->form[p->tlen] == 'c')
		return(ft_print_char(p));
	if (p->form[p->tlen] == 's')
		return(ft_print_str(p));
	if (p->form[p->tlen] == 'p')
		return(ft_print_pointer(p));
	if (p->form[p->tlen] == 'u')
		return(ft_print_unsigned(p));
	if (p->form[p->tlen] == 'x' || p->form[p->tlen] == 'X')
		return(ft_print_hexa(p));
	if (p->form[p->tlen] == '%')
		return(ft_print_percent(p));
	return (0);
}

int check_zero(t_print *p)
{
	if (p->form[p->tlen] == '0' && (!(ft_isdigit(p->form[p->tlen -1]))) && (p->point == 0))
	{
		p->zero = 1;
		p->tlen++;
		return (1);
	}
return (0);
}

void check_aster(t_print *p)
{
	if (p->point == 0)
	{
		p->width = va_arg(p->args, int);
		if (p->width < 0)
		{
			p->left = 1;
			p->width = p->width * -1;
		}
	}
	if (p->point == 1)
	{
		p->prec = va_arg(p->args, int);
		if (p->prec < 0)
		{
			p->left = 1;
			p->prec = p->prec * -1;
		}
	}
}

void check_flags(t_print *p)
{
	p->tlen++;
	while (check_type(p) != 1)
	{
		check_zero(p);
		if (p->form[p->tlen] == '-')
			p->left = 1;
		if (p->form[p->tlen] == '.')
			p->point = 1;
		if (p->form[p->tlen] == '*')
			check_aster(p);
		if (ft_isdigit(p->form[p->tlen]))
		{
			if (!p->point)
				p->width = (p->width * 10) + (p->form[p->tlen] - '0');
			else
				p->prec = (p->prec * 10) + (p->form[p->tlen] - '0');
		}
		p->tlen++;
	}
	p->tlen++;
	reset_struct(p);
}

void check_arg(t_print *p)
{
	while (p->form[p->tlen])
	{
		if (p->form[p->tlen] == '%')
			check_flags(p);
		if (p->form[p->tlen] && p->form[p->tlen] != '%')
		{
			ft_putchar_fd(p->form[p->tlen], 1);
			p->len++;
			p->tlen++;

		}
	}
}
