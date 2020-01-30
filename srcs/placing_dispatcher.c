/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   placing_dispatcher.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmolin <gmolin@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 10:09:01 by gmolin            #+#    #+#             */
/*   Updated: 2020/01/30 17:57:56 by gmolin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

int						placing_dispatcher(t_map *map, t_piece *piece, t_heat *heat)
{
	(heat->hot = "br") ? placing_br(map, piece, heat->br_end_y, heat->br_end_x) : 0;
	(heat->hot = "bl") ? placing_bl(map, piece, heat->bl_end_y, heat->bl_end_x) : 0;
	(heat->hot = "tr") ? placing_tr(map, piece, heat->tr_end_y, heat->tr_end_x) : 0;
	(heat->hot = "tl") ? placing_tl(map, piece, heat->tl_end_y, heat->tl_end_x) : 0;
}
