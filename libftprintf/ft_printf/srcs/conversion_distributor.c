/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion_distributor.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmolin <gmolin@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/08 13:34:43 by gmolin            #+#    #+#             */
/*   Updated: 2020/01/22 10:53:06 by gmolin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	conversion_distributor(t_menu *menu, char c, va_list arg)
{
	(c == '%') ? conv_perc(menu) : 0;
	(c == 'c') ? conv_c(menu, arg) : 0;
	(c == 's') ? conv_s(menu, arg) : 0;
	(c == 'p') ? conv_p(menu, arg) : 0;
	(c == 'i' || c == 'd') ? conv_id(menu, arg) : 0;
	if (c == 'o' || c == 'u' || c == 'x' || c == 'X')
	{
		menu->conv = 1;
		(c == 'o') ? conv_o(menu, arg) : 0;
		(c == 'u') ? conv_u(menu, arg) : 0;
		if (c == 'x' || c == 'X')
		{
			menu->conv2 = 1;
			(c == 'X') ? menu->x = 1 : 0;
			conv_x(menu, arg);
		}
	}
	if (c == 'f')
	{
		menu->conv3 = 1;
		conv_f(menu, arg);
	}
}
