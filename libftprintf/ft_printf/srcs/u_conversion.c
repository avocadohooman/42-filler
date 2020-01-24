/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   u_conversion.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmolin <gmolin@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 17:02:11 by gmolin            #+#    #+#             */
/*   Updated: 2020/01/22 13:23:08 by gmolin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static	char	*length_check_u(unsigned long n, t_menu *menu, va_list arg)
{
	if (menu->length == L)
		n = (unsigned long int)va_arg(arg, long int);
	else if (menu->length == LL)
		n = (unsigned long long int)va_arg(arg, long long int);
	else if (menu->length == H)
		n = (unsigned short int)va_arg(arg, int);
	else if (menu->length == HH)
		n = (unsigned char)va_arg(arg, int);
	else if (menu->length == Z)
		n = (size_t)va_arg(arg, size_t);
	else if (menu->length == 0)
		n = (unsigned int)va_arg(arg, unsigned int);
	return (ft_itoa_base(n, 10));
}

void			conv_u(t_menu *menu, va_list arg)
{
	unsigned long		n;
	char				*str;

	n = 0;
	str = length_check_u(n, menu, arg);
	menu->nb = menu->precision - ft_strlen(str);
	(str[0] == '0' && menu->precision == -1) ? str[0] = '\0' : 0;
	if (menu->precision > 0 && menu->nb > 0)
		str = pre_converter(str, menu, '0', 1);
	if (menu->minus == 1)
		str = leftaligned(menu, str);
	else if (menu->minus == 0)
		str = rightaligned(menu, str);
	ft_putstr(str);
	menu->printed += ft_strlen(str);
	ft_strdel(&str);
}
