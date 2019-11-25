/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jomartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 17:09:29 by jomartin          #+#    #+#             */
/*   Updated: 2019/11/07 18:34:34 by jomartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	int		j;
	char	*s1;

	i = 0;
	j = -1;
	s1 = (char *)s;
	while (s1[i] != '\0')
	{
		if (s1[i] == c)
			j = i;
		i++;
	}
	if (s1[i] == c)
		return (s1 + i);
	if (j >= 0)
		return (s1 + j);
	return (NULL);
}
