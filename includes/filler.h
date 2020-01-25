/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmolin <gmolin@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 14:42:21 by gmolin            #+#    #+#             */
/*   Updated: 2020/01/25 15:57:28 by gmolin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

/*
** ------ HEADERS ------
*/

# include <stdlib.h>
# include <unistd.h>
# include "../libftprintf/libft/includes/libft.h"
# include "../libftprintf/ft_printf/includes/ft_printf.h"
# include <fcntl.h>
# define BUFF_SIZE 1

/*
** ------ STRUCTS ------
*/

typedef	struct	s_map
{
	char	**board;
	char	*p_name;
	char	*token;
	int 	player;
	int		pos_me_x;
	int		pos_me_y;
	int		pos_en_x;
	int		pos_en_y;
	int		size_x;
	int		size_y;
}				t_map;

typedef	struct	s_piece
{
	char	**piece;
	int		size_x;
	int		size_y;
}				t_piece;

/*
** ------ MAIN.C ------
*/

int					main(int argc, char **argv);


/*
** ------ MAP_MODE.C ------
*/

void       			map_mode(t_map *map, char *line, int fd);

/*
** ------ PIECE_MODE.C ------
*/

void                piece_mode(t_piece *piece, char *line, int fd);

#endif