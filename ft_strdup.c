/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jomartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 16:34:20 by jomartin          #+#    #+#             */
/*   Updated: 2019/11/07 18:30:59 by jomartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*c;
	int		i;
	int		j;

	i = ft_strlen(s1);
	if (!(c = malloc(sizeof(char) * i + 1)))
		return (NULL);
	j = 0;
	while (s1[j] != '\0')
	{
		c[j] = s1[j];
		j++;
	}
	c[j] = '\0';
	return (c);
}
