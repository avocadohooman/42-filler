/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmolin <gmolin@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 09:25:45 by gmolin            #+#    #+#             */
/*   Updated: 2020/01/30 14:30:05 by gmolin           ###   ########.fr       */
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
	int		y;
	int		x;

	y = -1;
	piece->start_x = piece->size_x;
	piece->start_y = piece->size_y;
	while (++y < piece->size_y)
	{
		x = -1;
		while (++x < piece->size_x)
			if (piece->piece[y][x] == '*')
			{
				if (x < piece->start_x)
					piece->start_x = x;
				if (x > piece->trim_x)
					piece->trim_x = x;
				if (y < piece->start_y)
					piece->start_y = y;
				if (y > piece->trim_y)
					piece->trim_y = y;
			}
	}
	piece->trim_size_x = (piece->trim_x - piece->start_x) + 1;
	piece->trim_size_y = (piece->trim_y - piece->start_y) + 1;
}
