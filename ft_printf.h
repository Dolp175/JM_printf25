/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jomartin < jomartin@student.42madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 10:47:52 by jomartin          #+#    #+#             */
/*   Updated: 2019/11/25 15:21:53 by jomartin         ###   ########.fr       */
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
	int left;
	int zero;
	int point;
	int prec;
	int width;
	char *form;
	int len;
	int tlen;
	va_list args;
} t_print;

int check_type(t_print *p);
int check_zero(t_print *p);
void check_aster(t_print *p);
void check_flags(t_print *p);
void check_arg(t_print *p);
int	ft_printf(const char *format, ...);
int ft_nb_len(int nbr);
void ft_print_zeros(int size, t_print *p);
void ft_print_spaces(int size, t_print *p);
int ft_nbx_len(long long int nbr);
void ft_itoa_x(long long int nbr, int lcase, t_print *p);
int ft_print_char(t_print *p);
int ft_print_percent(t_print *p);
void ft_hexa_l(t_print *p, int lcase, long long int i, int j);
void ft_hexa_r(t_print *p, int lcase, long long int i, int j);
int ft_print_hexa(t_print *p);
void ft_intmin_r(t_print *p);
void ft_print_intmin(t_print *p);
void ft_nbr_l(t_print *p, int nbr, int sign);
void ft_nbr_r(t_print *p, int nbr, int sign);
int ft_print_number(t_print *p);
int print_nbr_zero(t_print *p);
void ft_point_l(t_print *p, long long int i, int j);
void ft_point_r(t_print *p, long long int i, int j);
int ft_print_pointer(t_print *p);
void	ft_str_l(t_print *p, char *c);
void	ft_str_r(t_print *p, char *c);
int ft_print_str(t_print *p);
void ft_unbr_l(t_print *p, unsigned int nbr);
void ft_unbr_r(t_print *p, unsigned int nbr);
int ft_print_unsigned(t_print *p);
int is_valid(t_print *p);
void reset_struct(t_print *p);
void ini_struct(t_print *p);

#endif
