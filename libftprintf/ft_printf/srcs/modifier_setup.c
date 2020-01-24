/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modifier_setup.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmolin <gmolin@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/08 13:36:17 by gmolin            #+#    #+#             */
/*   Updated: 2020/01/21 16:21:41 by gmolin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static	void	flags(t_menu *menu, const char *fmt)
{
	while (ft_strchr("#0-+ ", fmt[menu->i]))
	{
		if (fmt[menu->i] == '+')
			menu->plus = 1;
		if (fmt[menu->i] == '-')
			menu->minus = 1;
		if (fmt[menu->i] == '#')
			menu->hash = 1;
		if (fmt[menu->i] == ' ')
			menu->space = 1;
		if (fmt[menu->i] == '0')
			menu->zero = 1;
		menu->i++;
	}
	if (menu->plus == 1)
		menu->space = 0;
}

static	void	width(t_menu *menu, const char *fmt, va_list arg)
{
	widthstar(menu, fmt, arg);
	if (fmt[menu->i] >= '0' && fmt[menu->i] <= '9')
		menu->width = ft_atoi(&fmt[menu->i]);
	while (fmt[menu->i] >= '0' && fmt[menu->i] <= '9')
		menu->i++;
}

static	void	precision(t_menu *menu, const char *fmt, va_list arg, int nb)
{
	if (fmt[menu->i] == '.')
	{
		menu->precision = -1;
		menu->precisionft = 0;
		menu->i++;
		if (fmt[menu->i] >= '0' && fmt[menu->i] <= '9')
		{
			menu->precision = ft_atoi(&fmt[menu->i]);
			(menu->precision == 0) ? menu->precision = -1 : 0;
			(menu->precision >= 1) ? menu->precisionft = 1 : 0;
		}
		else if (fmt[menu->i] == '*')
		{
			nb = va_arg(arg, int);
			(nb >= 0) ? menu->precision = nb : 0;
			(nb > 0) ? menu->precisionft = 1 : 0;
			while (fmt[menu->i] == '*')
				menu->i++;
		}
	}
	while (fmt[menu->i] >= '0' && fmt[menu->i] <= '9')
		menu->i++;
}

static	void	length(t_menu *menu, const char *fmt)
{
	if (fmt[menu->i] == 'l')
	{
		if (fmt[menu->i + 1] == 'l')
			menu->length = LL;
		else if (fmt[menu->i - 1] != 'l')
			menu->length = L;
	}
	if (fmt[menu->i] == 'h')
	{
		if (fmt[menu->i + 1] == 'h')
			menu->length = HH;
		else if (fmt[menu->i - 1] != 'h')
			menu->length = H;
	}
	(fmt[menu->i] == 'L') ? menu->length = BIGL : 0;
	(fmt[menu->i] == 'z') ? menu->length = Z : 0;
	while (ft_strchr(LENGTH, fmt[menu->i]) && fmt[menu->i])
		menu->i++;
}

void			modifier(t_menu *menu, const char *fmt, va_list arg)
{
	flags(menu, fmt);
	width(menu, fmt, arg);
	precision(menu, fmt, arg, 0);
	length(menu, fmt);
}
