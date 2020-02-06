/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmolin <gmolin@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 09:25:45 by gmolin            #+#    #+#             */
/*   Updated: 2020/02/06 17:04:37 by gmolin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

int					heat_counter_big(t_map *map, int start_y, int start_x)
{
	int count;
	int y;
	int x;
	int end_y;
	int end_x;

	(start_y == 0) ? end_y = map->start_y : 0;
	(start_x == 0) ? end_x = map->start_x : 0;
	(start_x == map->start_x) ? end_x = map->size_x : 0;
	(start_y == map->start_y) ? end_y = map->size_y : 0;
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

int					heat_counter_small(t_map *map, int start_y, int start_x)
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
