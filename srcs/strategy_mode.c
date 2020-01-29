/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strategy_mode.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmolin <gmolin@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 11:35:16 by gmolin            #+#    #+#             */
/*   Updated: 2020/01/29 16:40:17 by gmolin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

// static char		*heat_level(t_heat *heat)
// {

// }

static void		heat_map(t_map *map, t_heat *heat)
{
	heat->tl = heat_counter(map, 0, 0);
	heat->tr = heat_counter(map, 0, map->size_x / 2);
	heat->bl = heat_counter(map, map->size_y / 2, 0);
	heat->br = heat_counter(map, map->size_y / 2, map->size_x / 2);
	// heat->hot = heat_level(heat);
	// heat->warm = heat_level(heat);
	// heat->luke_warm = heat_level(heat);
	// heat->cold = heat_level(heat);
}


void			strategy_mode(t_map *map, t_heat *heat)
{
	heat_map(map, heat);
}
