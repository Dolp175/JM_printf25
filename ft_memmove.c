/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jomartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 16:00:25 by jomartin          #+#    #+#             */
/*   Updated: 2019/11/11 22:02:10 by jomartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned char	*ft_cpy(unsigned char *dest,
		unsigned char *src, unsigned int n)
{
	unsigned int a;

	a = 0;
	while (a < n)
	{
		dest[a] = src[a];
		a++;
	}
	return (dest);
}

void					*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*s1;
	unsigned char	*s2;

	s1 = (unsigned char *)dst;
	s2 = (unsigned char *)src;
	if (s1 == NULL && s2 == NULL)
		return (NULL);
	if (s2 < s1)
	{
		while (len > 0)
		{
			len--;
			s1[len] = s2[len];
		}
	}
	else
		s1 = ft_cpy(s1, s2, len);
	return (dst);
}
