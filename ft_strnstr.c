/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jomartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 17:29:03 by jomartin          #+#    #+#             */
/*   Updated: 2019/11/08 11:32:52 by jomartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	k;
	char			*s;

	s = (char *)haystack;
	if (needle[0] == '\0')
		return (s);
	i = ft_strlen(needle);
	k = 0;
	while (s[k] != '\0' && k + i <= len)
	{
		if (s[k] == needle[0])
		{
			j = ft_strncmp(s + k, needle, i);
			if (j == 0)
				return (&s[k]);
		}
		k++;
	}
	return (NULL);
}
