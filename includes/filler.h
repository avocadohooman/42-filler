/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmolin <gmolin@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 14:42:21 by gmolin            #+#    #+#             */
/*   Updated: 2020/01/30 23:16:00 by gmolin           ###   ########.fr       */
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
	char	**board_backup;
	char	*p_name;
	char	*token_me;
	char	*token_en;
	int		**heat;
	int 	player;
	int		pos_me_x;
	int		pos_me_y;
	int		pos_en_x;
	int		pos_en_y;
	int		start_x;
	int		start_y;
	int		end_y;
	int		end_x;
	int		size_x;
	int		size_y;
	int		check_sum;
}				t_map;

typedef	struct	s_heat
{
	int		array[4];
	char	*hot;
	char	*warm;
	char	*luke_warm;
	char	*cold;
	int		br_end_x;
	int		br_end_y;
	int		bl_end_x;
	int		bl_end_y;
	int		tr_end_x;
	int		tr_end_y;
	int		tl_end_x;
	int		tl_end_y;
}				t_heat;


typedef	struct	s_piece
{
	char	**piece;
	char	**p_trimmed;
	int		size_x;
	int		size_y;
	int		check_sum;
	int		distance_x;
	int		distance_y;
	int		start_x;
	int		start_y;
	int		trim_x;
	int		trim_y;
	int		trim_size_x;
	int		trim_size_y;
	int		final_x;
	int		final_y;
}				t_piece;

/*
** ------ MAIN.C ------
*/

int					main(int argc, char **argv); 
// int					main(void);

/*
** ------ INITIATE_STRUCT.C ------
*/

void				initiate_structs(t_map *map, t_piece *piece, t_heat *heat);

/*
** ------ MAP_MODE.C ------
*/

void       			map_mode(t_map *map, char *line, int fd);

/*
** ------ PIECE_MODE.C ------
*/

void                piece_mode(t_piece *piece, char *line, int fd);

/*
** ------ STRATEGY_MODE.C ------
*/

void				strategy_mode(t_map *map, t_heat *heat);

/*
** ------ PLACING_DISPATCHER.C ------
*/

int					placing_dispatcher(t_map *map, t_piece *piece, t_heat *heat);

/*
** ------ PLACING_ENGINE_TOP.C ------
*/

int					placing_tl(t_map *map, t_piece *piece, int start_y, int start_x);
int					placing_tr(t_map *map, t_piece *piece, int start_y, int start_x);


/*
** ------ PLACING_ENGINE_BOTTOM.C ------
*/

int					placing_bl(t_map *map, t_piece *piece, int start_y, int start_x);
int					placing_br(t_map *map, t_piece *piece, int start_y, int start_x);

/*
** ------ RETURNING_PIECES.C ------
*/

void				return_coordinates(t_map *map, t_piece *piece);
void        		print_result(t_piece *piece, t_map *map);


/*
** ------ TOOLS.C ------
*/

int					validator(t_map *map, t_piece *piece);
int					heat_counter(t_map *map, int start_y, int start_x);
int					count_pieces(char **area, char *needle, int min_y, int min_x);
void				tailor(t_piece *pieces);

#endif