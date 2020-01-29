/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmolin <gmolin@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 09:25:45 by gmolin            #+#    #+#             */
/*   Updated: 2020/01/29 17:49:50 by gmolin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

int					heat_counter(t_map *map, int start_y, int start_x)
{
	int count;
	int y;
	int x;
	int end_y;
	int end_x;

	(start_y == 0) ? end_y = map->size_y / 2 : 0;
	(start_x == 0) ? end_x = map->size_x / 2 : 0;
	(start_x == map->size_x / 2) ? end_x = map->size_x : 0;
	(start_y == map->size_y / 2) ? end_y = map->size_y : 0;
	count = 0;
	y = start_y;
	while (y < end_y)
	{
		x = start_x;
		while (x < end_x) 
		{
			if (ft_strchr(map->token_en, map->board[y][x]))
				count++;
			x++;
		}
		y++;
	}
	return (count);
}

int					count_pieces(char **area, char *needle, int min_y, int min_x)
{
	int	count;
	int	y;
	int x;

	count = 0;
	y = min_y;
	while (area[y])
	{
		x = min_x;
		while (area[y][x])
		{
			if (ft_strchr(needle, area[y][x]))
				count++;
			x++;
		}
		y++;
	}
	return (count);
}

void				tailor(t_piece *piece)
{
	int x;
	int y;
	int tmp;
	int	flag;

	y = 0;
	tmp = 0;
	flag = 0;
	while (piece->piece[y])
	{
		x = 0;
		while (piece->piece[y][x])
		{
			if (piece->piece[y][x] == '*' && piece->piece[y][x - 1] != '*')
			{
				if (x < piece->size_x)
				{
					if (x > tmp && flag == 0)
					{
						tmp = x;
						flag = 1;
					}	
					(x < tmp && flag == 1) ? piece->trim_x = x : 0;
					(x < piece->size_x && flag == 0) ? piece->trim_x = x : 0;
				}
				(y < piece->size_y) ? piece->trim_y = y : 0;
			}
			x++;
		}
		y++;
	}
	// ft_printf("POS TRIM X: %d\nX: %d\nSIZE X: %d\nPOS TRIM Y: %d\n", piece->trim_x, x, piece->size_x, piece->trim_y);
}
