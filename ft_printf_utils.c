/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jomartin < jomartin@student.42madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 09:14:55 by jomartin          #+#    #+#             */
/*   Updated: 2019/11/25 00:17:40 by jomartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_nb_len(int nbr)
{
	int i;

	i = 0;
	if (nbr == 0)
	return (1);

	while (nbr > 0)
	{
		nbr = nbr / 10;
		i++;
	}
	return (i);
}

void ft_print_zeros(int size, t_print *p)
{
	while (size > 0)
	{
	p->len = p->len + write(1, "0", 1);
	size--;
	}
}

void ft_print_spaces(int size, t_print *p)
{
	while (size > 0)
	{
	p->len = p->len + write(1, " ", 1);
	size--;
	}
}

int ft_nbx_len(long long int nbr)
{
	int i;

	i = 0;
	if (nbr == 0)
	return (1);

	while (nbr > 0)
	{
		nbr = nbr / 16;
		i++;
	}
	return (i);
}

void ft_itoa_x(long long int nbr, int case, t_print *p)
{
	int i;
	char *tmp;

	i = ft_nbx_len(nbr);
	tmp = ft_calloc(i + 1; sizeof(char));
	while (i > 0)
	{
		if (nbr % base > 9 && case == 1)
			tmp[i - 1] = (nbr % base) + 'A' - 10;
		else if (nbr % base > 9 && case == 0)
			tmp[i - 1] = (nbr % base) + 'a' - 10;
		else if (nbr % base < 10)
			tmp[i - 1] = (nbr % base) + '0';
		i--;
		nbr = nbr / base;
	}
	p->len = write(1, tmp, ft_strlen(tmp));
	free(tmp);
}
