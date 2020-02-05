/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   placing_br.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmolin <gmolin@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 10:09:01 by gmolin            #+#    #+#             */
/*   Updated: 2020/02/05 16:51:54 by gmolin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

static 	int				placing_engine_br(t_map *map, t_piece *piece, int start_y, int start_x)
{
	int		x;
	int		y;
	int		pos_x;

	y = 0;
	pos_x = start_x;
	map->area = ft_2dstrdup(map->board);
	while (start_y < map->size_y && map->area[start_y] && piece->p_trimmed[y])
	{
		x = 0;
		while (start_x < map->size_x && map->area[start_y][start_x] && piece->p_trimmed[y][x])
		{	
			if (!(ft_strchr(map->token_en, map->area[start_y][start_x])) && map->area[start_y][start_x] &&
				piece->p_trimmed[y][x] != '.')
				map->area[start_y][start_x] = piece->p_trimmed[y][x];
			x++;
			start_x++;
		}
		start_x = pos_x + 0;
		y++;
		start_y++;
	}
	if (validator(map, piece) == 0)
		return (0);
	return (1);
}


int						placing_br(t_map *map, t_piece *piece)
{
	int tmp;
	int start_x;
	int start_y;
	
	start_x = map->start_x;
	start_y = map->start_y;
	tmp = start_x;
	while (placing_engine_br(map, piece, start_y, start_x) == 0)
	{
		cleaner(map->area);
		if (start_x < map->size_x)
			start_x++;
		if (start_x >= map->size_x)
		{
			start_x = tmp;
			start_y++;
		}
		if (start_y >= map->size_y)
			return (0);
	}
	cleaner(map->board);
	map->board = ft_2dstrdup(map->area);
	cleaner(map->area);
	return (1);
}
