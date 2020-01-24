/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmolin <gmolin@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 14:42:21 by gmolin            #+#    #+#             */
/*   Updated: 2020/01/24 15:46:06 by gmolin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H


# include <stdlib.h>
# include <unistd.h>
# include "../libftprintf/libft/includes/libft.h"
# include "../libftprintf/ft_printf/includes/ft_printf.h"
# include <fcntl.h>
# define BUFF_SIZE 1

typedef	struct	s_setup
{
	char	**board;
	char	*p_name;
	char	token;
	int 	player;
	int		p1start_x;
	int		p1start_y;
	int		p2start_x;
	int		p2start_y;
	int		size_x;
	int		size_y;
}				t_setup;


#endif