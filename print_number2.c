/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_number2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jomartin < jomartin@student.42madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 13:03:19 by jomartin          #+#    #+#             */
/*   Updated: 2019/11/25 13:03:19 by jomartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int print_nbr_zero(t_print *p)
{
		if (p->width)
			ft_print_spaces(p->width, t_print *p);
		return (1);
}
