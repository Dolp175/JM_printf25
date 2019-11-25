/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_char.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jomartin < jomartin@student.42madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/24 18:09:49 by jomartin          #+#    #+#             */
/*   Updated: 2019/11/24 18:09:49 by jomartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int ft_print_char(t_print *p)
{
	unsigned char c;

	c = (unsigned char)va_arg(p->args, int);
	if (p->left)
	{
		p->len = write(1, &c, 1);
		if (p->width > 1)
			ft_print_spaces(p->width - 1, t_print *p);
	}
	else
	{
		if (p->width > 1)
			ft_print_spaces(p->width - 1, t_print *p);
		p->len = write(1, &c, 1);
	}
	return (1);
}

int ft_print_percent(t_print *p)
{
	if (p->left)
	{
		p->len = write(1, "%", 1);
		if (p->width > 1)
			ft_print_spaces(p->width - 1, t_print *p);
	}
	else
	{
		if (p->width > 1)
			ft_print_spaces(p->width - 1, t_print *p);
		p->len = write(1, "%", 1);
	}
	return (1);

}
