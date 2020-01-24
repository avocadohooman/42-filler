/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_converter.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmolin <gmolin@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/08 15:52:07 by gmolin            #+#    #+#             */
/*   Updated: 2020/01/22 11:10:06 by gmolin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	*pre_converter(char *str, t_menu *menu, char c, int check)
{
	char	*tmp;
	char	*joint;

	if (check == 0)
	{
		(str[0] == '0' && c == '0') ? joint = ft_strdup(str) : 0;
		(str[0] != '0' && c == '0') ? joint = ft_strjoin("0", str) : 0;
		(c == 'x') ? joint = ft_strjoin("0x", str) : 0;
		(c == 'X') ? joint = ft_strjoin("0X", str) : 0;
	}
	if (check == 1 || check == 2)
	{
		tmp = ft_strcnew(menu->nb, c);
		joint = ft_strjoin(tmp, str);
		free(tmp);
	}
	if (check == 3)
		if ((menu->plus && !menu->sign) || menu->sign)
		{
			(menu->plus && !menu->sign) ? joint = ft_strjoin("+", str) : 0;
			(menu->sign) ? joint = ft_strjoin("-", str) : 0;
		}
	free(str);
	return (joint);
}

char	*converter_l(char *str, size_t nb, t_menu *menu, char c)
{
	char	*joint;
	char	*tmp;
	int		i;

	joint = NULL;
	tmp = NULL;
	i = 0;
	tmp = ft_strcnew(nb, c);
	joint = ft_strjoin(str, tmp);
	free(tmp);
	free(str);
	if (menu->hash && menu->conv2 && (menu->width || menu->precision))
		joint = swap_zero_x_l(joint, 'c', i);
	return (joint);
}

char	*converter_r(char *str, size_t nb, t_menu *menu, char c)
{
	char	*joint;
	char	*tmp;
	int		i;

	joint = NULL;
	tmp = NULL;
	tmp = ft_strcnew(nb, c);
	joint = ft_strjoin(tmp, str);
	i = 0;
	free(tmp);
	free(str);
	if (menu->zero && menu->width && (menu->plus || menu->minus)
		&& !menu->precision && !menu->conv)
		joint = swap_plus_minus(joint, c, i);
	else if (menu->zero && menu->width && (menu->sign || menu->plus)
			&& menu->conv3)
		joint = swap_plus_minus(joint, c, i);
	if (menu->hash && menu->conv2 && (menu->width || menu->precision))
		joint = swap_zero_x_r(joint, c, i);
	(menu->space && menu->width) ? joint = swap_space(joint, c, i) : 0;
	return (joint);
}

char	*leftaligned(t_menu *menu, char *str)
{
	int		nb;
	char	*joint;

	joint = NULL;
	nb = menu->width - ft_strlen(str);
	if (nb > 0)
		return (joint = converter_l(str, nb, menu, ' '));
	if (nb < 0 && menu->nb > 0 && menu->conv2)
		return (joint = swap_zero_x_l(str, '0', 0));
	return (str);
}

char	*rightaligned(t_menu *menu, char *str)
{
	int		nb;
	char	*joint;

	joint = NULL;
	nb = menu->width - ft_strlen(str);
	if (nb > 0)
	{
		if (menu->zero == 1 && menu->width > 0 && !menu->sign
			&& !menu->precision)
			return (joint = converter_r(str, nb, menu, '0'));
		else if (menu->zero && menu->width > 0 && menu->conv3)
			return (joint = converter_r(str, nb, menu, '0'));
		else if (menu->zero && !menu->precision)
		{
			joint = converter_r(str, nb, menu, '0');
			return (joint = swap_plus_minus(joint, '+', 0));
		}
		else
			return (joint = converter_r(str, nb, menu, ' '));
	}
	if (nb < 0 && menu->nb > 0 && menu->conv2)
		return (joint = swap_zero_x_r(str, '0', 0));
	return (str);
}
