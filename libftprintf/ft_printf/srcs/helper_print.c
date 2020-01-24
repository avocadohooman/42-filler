/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_print.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmolin <gmolin@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/08 15:52:07 by gmolin            #+#    #+#             */
/*   Updated: 2020/01/21 16:21:33 by gmolin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	printspace(t_menu *menu, int nb)
{
	while (nb > 0)
	{
		ft_putchar(' ');
		nb--;
		menu->printed++;
	}
}

void	printzero(t_menu *menu, int nb)
{
	while (nb > 0)
	{
		ft_putchar('0');
		nb--;
		menu->printed++;
	}
}

void	widthstar(t_menu *menu, const char *fmt, va_list arg)
{
	if (fmt[menu->i] == '*')
	{
		menu->width = va_arg(arg, int);
		if (menu->width < 0)
		{
			menu->minus = 1;
			menu->width *= -1;
		}
		while (fmt[menu->i] == '*')
			menu->i++;
	}
}
