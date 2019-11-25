/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jomartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/09 20:29:54 by jomartin          #+#    #+#             */
/*   Updated: 2019/11/09 20:41:00 by jomartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_print(int nb, int fd)
{
	if (nb > 9)
	{
		ft_print(nb / 10, fd);
		ft_putchar_fd(nb % 10 + '0', fd);
	}
	else
	{
		ft_putchar_fd(nb + '0', fd);
	}
}

void		ft_putnbr_fd(int n, int fd)
{
	if (n < 0)
	{
		if (n == -2147483648)
		{
			write(fd, "-2147483648", 11);
		}
		else
		{
			ft_putchar_fd('-', fd);
			n = n * -1;
		}
	}
	if (n >= 0)
		ft_print(n, fd);
}
