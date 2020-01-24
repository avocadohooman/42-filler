/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_conversion.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmolin <gmolin@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/08 14:23:22 by gmolin            #+#    #+#             */
/*   Updated: 2020/01/23 13:00:16 by gmolin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	conv_perc(t_menu *menu)
{
	int				nb;

	nb = menu->width - 1;
	if (menu->minus == 0 && menu->width)
	{
		if (menu->zero == 1)
			printzero(menu, nb);
		else if (!menu->zero)
			printspace(menu, nb);
	}
	if (menu->minus == 1 && menu->width)
	{
		ft_putchar('%');
		printspace(menu, nb);
	}
	else
		ft_putchar('%');
	menu->printed++;
}

void	conv_c(t_menu *menu, va_list arg)
{
	unsigned char	c;
	int				nb;

	nb = menu->width - 1;
	c = (unsigned char)va_arg(arg, int);
	if (menu->minus == 0 && menu->width)
	{
		if (menu->zero == 1)
			printzero(menu, nb);
		else if (!menu->zero)
			printspace(menu, nb);
	}
	if (menu->minus == 1 && menu->width)
	{
		ft_putchar(c);
		printspace(menu, nb);
	}
	else
		ft_putchar(c);
	menu->printed++;
}
