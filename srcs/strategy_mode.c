/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strategy_mode.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmolin <gmolin@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 11:35:16 by gmolin            #+#    #+#             */
/*   Updated: 2020/02/10 11:22:41 by gmolin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

static char		*heat_level(t_heat *heat)
{
	int		i;
	int		tmp;
	int		pos;
	char	*area;

	i = 1;
	tmp = heat->array[0];
	pos = 0;
	while (i < 4)
	{
		if (heat->array[i] > tmp)
		{
			tmp = heat->array[i];
			pos = i;
		}
		i++;
	}
	(pos == 3) ? area = "br" : 0;
	(pos == 2) ? area = "bl" : 0;
	(pos == 1) ? area = "tr" : 0;
	(pos == 0) ? area = "tl" : 0;
	heat->array[pos] = -1;
	return (area);
}

static void		heat_map(t_map *map, t_heat *heat)
{
	heat->array[0] = heat_counter(map, 0, 0);
	heat->array[1] = heat_counter(map, 0, map->start_x);
	heat->array[2] = heat_counter(map, map->start_y, 0);
	heat->array[3] = heat_counter(map, map->start_y, map->start_x);
	heat->hot = heat_level(heat);
	heat->warm = heat_level(heat);
	heat->luke_warm = heat_level(heat);
	heat->cold = heat_level(heat);
}

static	void	big_map(t_map *map)
{
	if (map->pos_me_y < map->size_y / 2 && map->pos_me_y < map->pos_en_y)
	{
		map->start_y = map->size_y / 2;
		map->start_x = map->size_x / 2;
	}
	else if (map->pos_me_y > map->start_y / 2 && map->pos_me_y > map->pos_en_y)
	{
		map->start_y = map->pos_en_y + 40;
		map->start_x = 2;
	}
}

static	void	small_map(t_map *map)
{
	if (map->pos_me_y > map->size_y / 2 && map->pos_me_y < map->pos_en_y)
	{
		map->start_y = map->pos_en_y - 6;
		map->start_x = map->pos_en_x - 6;
	}
	else if (map->pos_me_y < map->size_y / 2 && map->pos_me_y < map->pos_en_y)
	{
		map->start_y = map->size_y / 2;
		map->start_x = map->size_x / 2;
	}
	else if (map->pos_me_y > map->start_y / 2 && map->pos_me_y > map->pos_en_y)
	{
		if (map->size_y > 15 && map->size_y <= 24)
		{
			map->start_y = map->pos_en_y + 13;
			map->start_x = 1;
		}
		else
		{
			map->start_y = map->size_y / 2 - 3;
			map->start_x = map->size_x / 2 + 3;
		}
	}
}

void			strategy_mode(t_map *map, t_heat *heat)
{
	(map->size_y > 24) ? big_map(map) : 0;
	(map->size_y <= 24) ? small_map(map) : 0;
	heat_map(map, heat);
}
