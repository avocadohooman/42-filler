/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strategy_mode.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmolin <gmolin@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 11:35:16 by gmolin            #+#    #+#             */
/*   Updated: 2020/02/07 15:40:48 by gmolin           ###   ########.fr       */
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
	// if (map->size_y >= 25)
	// {
	heat->array[0] = heat_counter_big(map, 0, 0);
	heat->array[1] = heat_counter_big(map, 0, map->start_x);
	heat->array[2] = heat_counter_big(map, map->start_y, 0);
	heat->array[3] = heat_counter_big(map, map->start_y, map->start_x);
	// }
	// else 
	// {
		// heat->array[0] = heat_counter_small(map, 0, 0);
		// heat->array[1] = heat_counter_small(map, 0, map->size_x / 2);
		// heat->array[2] = heat_counter_small(map, map->size_y / 2, 0);
		// heat->array[3] = heat_counter_small(map, map->size_y / 2, map->size_x / 2);
	// }
	heat->hot = heat_level(heat);
	heat->warm = heat_level(heat);
	heat->luke_warm = heat_level(heat);
	heat->cold = heat_level(heat);
}

static	void	big_map(t_map *map, t_heat *heat)
{
	if (map->pos_me_y < map->size_y / 2 && map->pos_me_y < map->pos_en_y)
	{
		map->start_y = map->size_y / 2;
		map->start_x = map->size_x / 2;
	}
	else if (map->pos_me_y > map->start_y / 2 && map->pos_me_y > map->pos_en_y)
	{
		map->start_y = map->pos_en_y + 40;
		map->start_x = 5;
	}
}

static	void	small_map(t_map *map, t_heat *heat)
{
	if (map->pos_me_y > map->size_y / 2 && map->pos_me_y < map->pos_en_y)
	{
		map->start_y = map->pos_en_y - 6;
		map->start_x = map->size_x / 2;
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
			map->start_y = map->pos_en_y - 4;
			map->start_x = map->pos_en_x + 6;
		}
	}
}

void			strategy_mode(t_map *map, t_heat *heat)
{
	if (map->flip == 1)
	{
		map->flip = 0;
	}
	(map->size_y > 24) ? big_map(map, heat) : 0;
	(map->size_y <= 24) ? small_map(map, heat) : 0;
	heat_map(map, heat);
}
