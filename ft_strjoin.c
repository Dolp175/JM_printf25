/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jomartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 11:14:36 by jomartin          #+#    #+#             */
/*   Updated: 2019/11/09 21:14:54 by jomartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*res;
	int		i;
	int		j;

	i = ft_strlen(s1);
	j = ft_strlen(s2);
	if (!(res = ft_calloc(i + j + 1, sizeof(*res))))
		return (NULL);
	res = ft_memcpy(res, s1, i);
	ft_strlcat(res, s2, i + j + 1);
	return (res);
}
