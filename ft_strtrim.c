/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jomartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 13:39:25 by jomartin          #+#    #+#             */
/*   Updated: 2019/11/12 13:39:10 by jomartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	checkbeg(char const *s1, char const *set)
{
	int k;
	int i;
	int j;

	k = ft_strlen(set);
	i = 0;
	j = 0;
	while (s1[i] && j <= k)
	{
		if (s1[i] == set[j])
		{
			i++;
			j = -1;
		}
		j++;
	}
	return (i);
}

static int	checkend(char const *s1, char const *set)
{
	int k;
	int i;
	int j;

	k = ft_strlen(set);
	i = ft_strlen(s1);
	j = 0;
	while (j <= k)
	{
		if (s1[i] == set[j])
		{
			i--;
			j = -1;
		}
		j++;
	}
	return (i);
}

char		*ft_strtrim(char const *s1, char const *set)
{
	char	*res;
	int		i;
	int		j;
	int		k;

	i = ft_strlen(s1);
	j = checkbeg(s1, set);
	if (i != j)
	{
		k = i - checkend(s1, set);
		if (!(res = malloc(sizeof(*res) * (i - j - k + 1))))
			return (NULL);
		res = ft_substr(s1, j, (i - j - k + 1));
	}
	else
	{
		if (!(res = malloc(sizeof(*res) * 1)))
			return (NULL);
		res[0] = '\0';
	}
	return (res);
}
