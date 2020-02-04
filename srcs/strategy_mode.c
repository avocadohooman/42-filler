/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strategy_mode.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmolin <gmolin@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 11:35:16 by gmolin            #+#    #+#             */
/*   Updated: 2020/02/04 14:46:43 by gmolin           ###   ########.fr       */
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
	if (map->size_y >= 25)
	{
		heat->array[0] = heat_counter(map, 0, 0);
		heat->array[1] = heat_counter(map, 0, map->start_x);
		heat->array[2] = heat_counter(map, map->start_y, 0);
		heat->array[3] = heat_counter(map, map->start_x, map->start_y);
	}
	else 
	{
		heat->array[0] = heat_counter(map, 0, 0);
		heat->array[1] = heat_counter(map, 0, map->size_x / 2);
		heat->array[2] = heat_counter(map, map->size_y / 2, 0);
		heat->array[3] = heat_counter(map, map->size_y / 2, map->size_x / 2);
	}
	heat->hot = heat_level(heat);
	heat->warm = heat_level(heat);
	heat->luke_warm = heat_level(heat);
	heat->cold = heat_level(heat);
}

void			strategy_mode(t_map *map, t_heat *heat)
{
	heat_map(map, heat);
	// ft_printf("HOT AREA: %s\n", heat->hot);
	// ft_printf("WARM AREA: %s\n", heat->warm);
	// ft_printf("LUKE WARM AREA: %s\n", heat->luke_warm);
	// ft_printf("COLD AREA: %s\n", heat->cold);
}
