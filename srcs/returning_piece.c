/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   returning_piece.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmolin <gmolin@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 13:50:45 by gmolin            #+#    #+#             */
/*   Updated: 2020/02/05 11:24:20 by gmolin           ###   ########.fr       */
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
	while (map->board[y] && token != 1)
	{
		x = 0;
		while (map->board[y][x] && token != 1 )
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
	// ft_printf("********* PIECE PLACED: *********\n");
	// int i = 0;
	// while (i < map->size_y)
    // {
    //     ft_printf("%2d %s\n", i, map->board[i]);
    //     i++;
    // }
	cleaner(piece->p_trimmed);
	cleaner(map->board);
	piece->trim_x = 0;
	piece->trim_y = 0;
	piece->trim_size_x = 0;
	piece->trim_size_y = 0;
	// ft_printf("Final x: %d\n Final y: %d\ndistance x: %d\n distance y: %d\n", piece->final_x, piece->final_y, piece->distance_x, piece->distance_y);
	piece->final_x -= piece->distance_x;
	piece->final_y -= piece->distance_y;
}

void            print_result(t_piece *piece, t_map *map)
{
	// ft_putnbr(piece->final_y);
	// ft_putchar(' ');
	// ft_putnbr(piece->final_x);
	// ft_putchar('\n');
	ft_printf("%d %d\n", piece->final_y, piece->final_x);
}
