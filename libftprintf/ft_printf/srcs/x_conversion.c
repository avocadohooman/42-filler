/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   x_conversion.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmolin <gmolin@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 14:59:47 by gmolin            #+#    #+#             */
/*   Updated: 2020/01/22 16:21:12 by gmolin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static	char	*length_check_x(unsigned long n, t_menu *menu, va_list arg)
{
	if (menu->length == L)
		n = (unsigned long int)va_arg(arg, uintmax_t);
	else if (menu->length == LL)
		n = (unsigned long long int)va_arg(arg, uintmax_t);
	else if (menu->length == H)
		n = (unsigned short)va_arg(arg, int);
	else if (menu->length == HH)
		n = (unsigned char)va_arg(arg, int);
	else if (menu->length == Z)
		n = (size_t)va_arg(arg, size_t);
	else if (menu->length == 0)
		n = (unsigned int)va_arg(arg, unsigned int);
	return (ft_itoa_base(n, 16));
}

void			conv_x(t_menu *menu, va_list arg)
{
	unsigned long		n;
	char				*str;
	int					len;

	n = 0;
	str = length_check_x(n, menu, arg);
	(str[0] == '0' && menu->precision == -1) ? str[0] = '\0' : 0;
	if (menu->x == 1)
		ft_strupper(str);
	if (menu->hash && str[0] != '0' && str[0] != '\0')
	{
		menu->nb = menu->precision - ft_strlen(str);
		(menu->x == 1) ? str = pre_converter(str, menu, 'X', 0) : 0;
		(menu->x == 0) ? str = pre_converter(str, menu, 'x', 0) : 0;
	}
	len = ft_strlen(str);
	(!menu->hash) ? menu->nb = menu->precision - len : 0;
	(menu->hash && str[1] == '\0') ? menu->nb = menu->precision - len : 0;
	if (menu->precision > 0 && menu->nb > 0)
		str = pre_converter(str, menu, '0', 1);
	(menu->minus == 1) ? str = leftaligned(menu, str) : 0;
	(menu->minus == 0) ? str = rightaligned(menu, str) : 0;
	ft_putstr(str);
	menu->printed += ft_strlen(str);
	ft_strdel(&str);
}
