/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmolin <gmolin@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/08 09:50:00 by gmolin            #+#    #+#             */
/*   Updated: 2020/01/21 16:21:28 by gmolin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	initiliaze_menu(t_menu *menu)
{
	menu->printed = 0;
	menu->i = 0;
	menu->len = 0;
	menu->plus = 0;
	menu->minus = 0;
	menu->hash = 0;
	menu->space = 0;
	menu->zero = 0;
	menu->padding = 0;
	menu->width = 0;
	menu->length = 0;
	menu->precision = 0;
	menu->precisionft = 0;
	menu->sign = 0;
	menu->conv = 0;
	menu->conv2 = 0;
	menu->conv3 = 0;
	menu->x = 0;
}

void	initiliaze_menu2(t_menu *menu)
{
	menu->len = 0;
	menu->plus = 0;
	menu->minus = 0;
	menu->hash = 0;
	menu->space = 0;
	menu->zero = 0;
	menu->padding = 0;
	menu->width = 0;
	menu->length = 0;
	menu->precision = 0;
	menu->precisionft = 0;
	menu->sign = 0;
	menu->conv = 0;
	menu->conv2 = 0;
	menu->conv3 = 0;
	menu->x = 0;
}

int		cm_parser(t_menu *menu, const char *fmt, va_list arg, int pos)
{
	menu->i = pos;
	if (ft_strchr(FLAGS, fmt[pos]))
		modifier(menu, fmt, arg);
	else
	{
		conversion_distributor(menu, fmt[pos], arg);
		initiliaze_menu2(menu);
	}
	pos = menu->i;
	if (fmt[pos] == '\0')
		return (pos);
	return (pos - 1);
}

int		fmt_parser(t_menu *menu, const char *fmt, va_list arg, int pos)
{
	while (fmt[pos])
	{
		if (fmt[pos] != '%')
			menu->printed += write(1, &fmt[pos], 1);
		if (fmt[pos] == '%')
		{
			if (!(ft_strchr(ALL, fmt[pos + 1]) || fmt[pos] == '\0'))
				break ;
			while (ft_strchr(ALL, fmt[pos + 1]) && fmt[pos] != '\0')
			{
				pos++;
				if (ft_strchr(CONVERSION, fmt[pos]))
				{
					pos = cm_parser(menu, fmt, arg, pos) + 2;
					break ;
				}
				else
					pos = cm_parser(menu, fmt, arg, pos);
			}
			continue;
		}
		pos++;
	}
	return (menu->printed);
}

int		ft_printf(const char *fmt, ...)
{
	va_list		arg;
	t_menu		*menu;
	int			c_count;
	int			fmtlen;

	if (!(menu = (t_menu*)malloc(sizeof(t_menu))))
		return (0);
	menu->fmt = (char *)fmt;
	initiliaze_menu(menu);
	va_start(arg, fmt);
	fmtlen = ft_strlen(fmt);
	if (!fmtlen)
		return (0);
	if (fmtlen == 1 && fmt[0] == '%')
		return (0);
	c_count = fmt_parser(menu, fmt, arg, 0);
	va_end(arg);
	free(menu);
	return (c_count);
}
