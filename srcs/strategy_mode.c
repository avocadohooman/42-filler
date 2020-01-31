/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strategy_mode.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmolin <gmolin@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 11:35:16 by gmolin            #+#    #+#             */
/*   Updated: 2020/01/31 17:05:14 by gmolin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

static char		*heat_level(t_heat *heat)
{
	int 	i;
	int		tmp;
	int 	pos;
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
	heat->array[1] = heat_counter(map, 0, map->size_x / 2);
	heat->array[2] = heat_counter(map, map->size_y / 2, 0);
	heat->array[3] = heat_counter(map, map->size_y / 2, map->size_x / 2);
	heat->hot = heat_level(heat);
	heat->warm = heat_level(heat);
	heat->luke_warm = heat_level(heat);
	heat->cold = heat_level(heat);
}

void			strategy_mode(t_map *map, t_heat *heat)
{
	heat_map(map, heat);
}
