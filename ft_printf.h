/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jomartin < jomartin@student.42madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 10:47:52 by jomartin          #+#    #+#             */
/*   Updated: 2019/11/24 16:43:08 by jomartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <stddef.h>
# include <limits.h>
# include <wchar.h>
# include "libft.h"

typedef struct s_print
{
	int left : 0;
	int zero : 0;
	int point : 0;
	int prec : 0;
	int width : 0;
	char *form;
	int len : 0;
	int tlen : 0;
	va_list args;
} t_print;


#endif
