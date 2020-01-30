/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   returning_piece.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmolin <gmolin@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 13:50:45 by gmolin            #+#    #+#             */
/*   Updated: 2020/01/30 15:28:19 by gmolin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

void			return_coordinates(t_map *map, t_piece *piece)
{
	int y;
	int x;
	int token;

	y = 0;
	x = 0;
	token = 0;
	while (map->board[y])
	{
		x = 0;
		while (map->board[y][x])
		{
			if (map->board[y][x] == '*' && token != 1)
			{
				piece->final_x = x;
				piece->final_y = y;
				token = 1;
			}
			x++;
		}
		y++;
	}
	piece->final_x -= piece->distance_x;
	piece->final_y -= piece->distance_y;
}

void            print_result(t_piece *piece, t_map *map)
{
	
	ft_printf("%d %d\n", piece->final_y, piece->final_x);
	map->pos_me_x = piece->final_x;
	map->pos_me_y = piece->final_y;
}
