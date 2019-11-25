/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jomartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 20:35:52 by jomartin          #+#    #+#             */
/*   Updated: 2019/11/11 22:00:48 by jomartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	size(int n)
{
	int size;

	size = 1;
	while (n > 9)
	{
		n = n / 10;
		size++;
	}
	return (size);
}

static char	*minnb(void)
{
	char *res;

	res = ft_calloc(12, sizeof(char));
	ft_strlcpy(res, "-2147483648", 12);
	return (res);
}

static char	*nbcpy(char *res, int n, int size, int sign)
{
	int i;

	i = size + sign;
	res[i] = '\0';
	while (n > 9)
	{
		res[i - 1] = n % 10 + 48;
		n = n / 10;
		i--;
	}
	res[i - 1] = n % 10 + 48;
	return (res);
}

char		*ft_itoa(int n)
{
	char	*res;
	int		i;

	i = 0;
	if (n < 0)
	{
		if (n == -2147483648)
			return (minnb());
		else
		{
			n = n * -1;
			if (!(res = malloc(sizeof(char) * size(n) + 2)))
				return (NULL);
			res[i++] = '-';
		}
	}
	else
	{
		if (!(res = malloc(sizeof(char) * size(n) + 1)))
			return (NULL);
	}
	res = nbcpy(res, n, size(n), i);
	return (res);
}
