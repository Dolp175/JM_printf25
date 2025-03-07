/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jomartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 11:47:04 by jomartin          #+#    #+#             */
/*   Updated: 2019/11/07 18:20:22 by jomartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(const char *str)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (*str && ((*str >= 9 && *str <= 13) || (*str == 32)))
		++str;
	if (*str && ((*str == 45) || (*str == 43)))
	{
		if (*str == 45)
			i++;
		++str;
	}
	while (*str && (*str >= '0' && *str <= '9'))
	{
		j = (j * 10) + (*str - '0');
		++str;
	}
	if (i % 2 != 0)
		j = j * -1;
	return (j);
}
