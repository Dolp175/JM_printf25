/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jomartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 10:50:24 by jomartin          #+#    #+#             */
/*   Updated: 2019/11/12 16:32:53 by jomartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*c;
	size_t	i;

	if ((ft_strlen(s) < start))
		return (ft_strdup(""));
	if ((ft_strlen(s) - start < len))
	{
		if (!(c = malloc(sizeof(*c) * (ft_strlen(s) - start))))
			return (NULL);
	}
	else
	{
		if (!(c = malloc(sizeof(*c) * (len + 1))))
			return (NULL);
	}
	i = 0;
	while (i < len && s[start + i])
	{
		c[i] = s[start + i];
		i++;
	}
	c[i] = '\0';
	return (c);
}
