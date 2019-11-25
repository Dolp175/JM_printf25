/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jomartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 15:39:51 by jomartin          #+#    #+#             */
/*   Updated: 2019/11/25 19:38:14 by jomartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int main()
{
	int i;
	int j;
	i = ft_printf("%3.3s%7.3s", "hello", "world");

	printf("\n");
	
	j = printf("%3.3s%7.3s", "hello", "world");

	printf("\n %d, %d", i, j);
	return (0);
}
