/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jomartin < jomartin@student.42madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 12:33:16 by jomartin          #+#    #+#             */
/*   Updated: 2019/11/24 23:53:20 by jomartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_printf(const char *format, ...)
{
	t_print p;

	va_start(p.args, format);
	p.form = ft_strdup(format);
	if (is_valid(p) == 0)
		return (p.len);
	check_arg(p);

	return (p.len);
}
