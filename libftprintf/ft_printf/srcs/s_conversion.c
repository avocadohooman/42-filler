/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_conversion.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmolin <gmolin@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 11:21:38 by gmolin            #+#    #+#             */
/*   Updated: 2020/01/21 16:21:49 by gmolin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static	char	*conv_s_precision(char *str, int n)
{
	char	*tmp;

	if (n > 0 && (size_t)n <= ft_strlen(str))
	{
		tmp = ft_strndup(str, n);
		str = tmp;
		free(tmp);
		return (str);
	}
	if (n == -1)
		str = "";
	return (str);
}

void			conv_s(t_menu *menu, va_list arg)
{
	char	*str;
	int		nb;

	str = va_arg(arg, char *);
	(str == NULL) ? str = "(null)" : 0;
	str = conv_s_precision(str, menu->precision);
	nb = menu->width - ft_strlen(str);
	if (menu->minus == 0 && nb > 0)
	{
		if (menu->zero == 1)
			printzero(menu, nb);
		else
			printspace(menu, nb);
	}
	if (menu->minus == 1 && nb > 0)
	{
		ft_putstr(str);
		printspace(menu, nb);
	}
	else
		ft_putstr(str);
	menu->printed += ft_strlen(str);
}
