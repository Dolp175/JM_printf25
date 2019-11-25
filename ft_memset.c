/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jomartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 11:04:02 by jomartin          #+#    #+#             */
/*   Updated: 2019/11/07 17:22:20 by jomartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	tmp;
	unsigned char	*btmp;
	unsigned int	i;

	tmp = c;
	i = 0;
	btmp = b;
	while (i < len)
	{
		btmp[i] = tmp;
		i++;
	}
	return (btmp);
}
