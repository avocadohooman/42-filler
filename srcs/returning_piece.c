/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   returning_piece.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmolin <gmolin@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 13:50:45 by gmolin            #+#    #+#             */
/*   Updated: 2020/02/10 11:07:25 by gmolin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

void			return_coordinates(t_map *map, t_piece *p)
{
	int y;
	int x;
	int token;

	y = 0;
	x = 0;
	token = 0;
	while (map->board[y] && token != 1)
	{
		x = 0;
		while (map->board[y][x] && token != 1)
		{
			if (map->board[y][x] == '*' && token != 1)
			{
				p->final_x = x;
				p->final_y = y;
				token = 1;
			}
			x++;
		}
		y++;
	}
	p->final_x -= p->distance_x;
	p->final_y -= p->distance_y;
}

void			print_result(t_piece *p, t_map *map)
{
	p->trim_x = 0;
	p->trim_y = 0;
	p->trim_size_x = 0;
	p->trim_size_y = 0;
	cleaner(p->p_trimmed);
	cleaner(map->board);
	ft_printf("%d %d\n", p->final_y, p->final_x);
}
