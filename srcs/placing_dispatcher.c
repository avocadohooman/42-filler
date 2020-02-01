/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   placing_dispatcher.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmolin <gmolin@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 10:09:01 by gmolin            #+#    #+#             */
/*   Updated: 2020/02/01 17:50:19 by gmolin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

int static				bottom_right(t_map *map, t_piece *piece, int start_y, int start_x)
{
	if (!placing_br(map, piece, start_y, start_x))
		if (!placing_tl(map, piece, start_y, start_x))
			if (!placing_bl(map, piece, start_y, start_x))
				if (!placing_tr(map, piece, start_y, start_x))
					return (0);
	return (1);
}

int static				bottom_left(t_map *map, t_piece *piece, int start_y, int start_x)
{
	if (!placing_bl(map, piece, start_y,  start_x))
		if (!placing_tr(map, piece, start_y, start_x))
			if (!placing_br(map, piece, start_y, start_x))
				if (!placing_tl(map, piece, start_y, start_x))
					return (0);
	return (1);
}

int static				top_right(t_map *map, t_piece *piece, int start_y, int start_x)
{
	if (!placing_tr(map, piece, start_y, start_x))
		if (!placing_bl(map, piece, start_y, start_x))
			if (!placing_tl(map, piece, start_y, start_x))
				if (!placing_br(map, piece, start_y, start_x))
					return (0);
	return (1);
}

int static				top_left(t_map *map, t_piece *piece, int start_y, int start_x)
{
	if (!placing_tl(map, piece, start_y, start_x))
		if (!placing_br(map, piece, start_y, start_x))
			if (!placing_tr(map, piece, start_y, start_x))
				if (!placing_bl(map, piece, start_y, start_x))
					return (0);
	return (1);
}

int						placing_dispatcher(t_map *map, t_piece *piece, t_heat *heat)
{
	// ft_printf("dispatcher\n");
	if (ft_strcmp(heat->hot, "br") == 0 && !(bottom_right(map, piece,map->start_y, map->start_y)))
		return (0);
	else if (ft_strcmp(heat->hot, "bl") == 0 && !(bottom_left(map, piece, map->start_y, map->start_x)))
		return (0);
	else if (ft_strcmp(heat->hot, "tr") == 0 && !(top_right(map, piece, map->start_y, map->start_x)))
		return (0);
	else if (ft_strcmp(heat->hot, "tl") == 0 && !(top_left(map, piece, map->start_y, map->start_x)))
		return (0);
	return (1);
}
