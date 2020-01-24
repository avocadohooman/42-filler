/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmolin <gmolin@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/06 12:57:21 by gmolin            #+#    #+#             */
/*   Updated: 2020/01/24 13:52:16 by gmolin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

/*
** ------ HEADERS ------
*/

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include "../../libft/includes/libft.h"

/*
** ------ FLAGS / MODIFIER / CONVERSION VARIABLES ------
*/

# define L			1
# define LL			2
# define BIGL		3
# define H			4
# define HH			5
# define Z			6

# define CONVERSION	"cspdiouxXf%"
# define FLAGS		"#0-+ .*0123456789hlLz"
# define ALL		"#0-+ .*0123456789hlLzcspdiouxXf%"
# define LENGTH		"lLhz"

/*
** ------ STRUCTS ------
*/

typedef struct	s_menu
{

	char		*fmt;
	int			printed;
	int			i;
	int			len;
	int			plus;
	int			minus;
	int			hash;
	int			space;
	int			zero;
	int			nb;
	char		padding;
	int			width;
	int			length;
	int			precision;
	int			precisionft;
	int			sign;
	int			conv;
	int			conv2;
	int			conv3;
	int			x;

}				t_menu;

/*
** ------ FT_PRINTF.C ------
*/

int				ft_printf(const char *fmt, ...);
int				fmt_parser(t_menu *menu, const char *fmt, va_list arg, int pos);
int				cm_parser(t_menu *menu, const char *fmt, va_list arg, int pos);
void			initiliaze_menu2(t_menu *menu);
void			initiliaze_menu(t_menu *menu);

/*
** ------ CONVERSION_DISTRIBUTOR.C ------
*/

void			conversion_distributor(t_menu *menu, char c, va_list arg);

/*
** ------ MODIFIER_SETUP.C ------
*/

void			modifier(t_menu *menu, const char *fmt, va_list arg);

/*
** ------ C_CONVERSION.C ------
*/

void			conv_c(t_menu *menu, va_list arg);
void			conv_perc(t_menu *menu);

/*
** ------ S_CONVERSION.C ------
*/

void			conv_s(t_menu *menu, va_list arg);

/*
** ------ P_CONVERSION.C ------
*/

void			conv_p(t_menu *menu, va_list arg);

/*
** ------ ID_CONVERSION.C ------
*/

void			conv_id(t_menu *menu, va_list arg);

/*
** ------ O_CONVERSION.C ------
*/

void			conv_o(t_menu *menu, va_list arg);

/*
** ------ U_CONVERSION.C ------
*/

void			conv_u(t_menu *menu, va_list arg);

/*
** ------ X_CONVERSION.C ------
*/

void			conv_x(t_menu *menu, va_list arg);

/*
** ------ F_CONVERSION.C ------
*/

void			conv_f(t_menu *menu, va_list arg);

/*
** ------ HELPER_PRINT.C ------
*/

void			printspace(t_menu *menu, int nb);
void			printzero(t_menu *menu, int nb);
void			widthstar(t_menu *menu, const char *fmt, va_list arg);

/*
** ------ HELPER_CONVERTER.C ------
*/

char			*pre_converter(char *str, t_menu *menu, char c, int check);
char			*converter_l(char *str, size_t nb, t_menu *menu, char c);
char			*converter_r(char *str, size_t nb, t_menu *menu, char c);
char			*leftaligned(t_menu *menu, char *str);
char			*rightaligned(t_menu *menu, char *str);

/*
** ------ HELPER_SWAP.C ------
*/

char			*swap_plus_minus(char *joint, char c, int i);
char			*swap_zero_x_l(char *joint, char c, int i);
char			*swap_zero_x_r(char *joint, char c, int i);
char			*swap_space(char *joint, char c, int i);

#endif
