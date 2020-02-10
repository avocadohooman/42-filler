/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initiate_struct.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmolin <gmolin@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 12:25:16 by gmolin            #+#    #+#             */
/*   Updated: 2020/02/10 10:05:01 by gmolin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

static void			initiate_struct_map(t_map *map)
{
	map->board = NULL;
	map->area = NULL;
	map->p_name = NULL;
	map->token_me = NULL;
	map->token_en = NULL;
	map->heat = NULL;
	map->player = 0;
	map->pos_me_x = 0;
	map->pos_me_y = 0;
	map->pos_en_x = 0;
	map->pos_en_x = 0;
	map->size_x = 0;
	map->size_y = 0;
	map->start_x = 0;
	map->start_y = 0;
	map->check_sum = 0;
	map->pos_en = 0;
	map->pos_me = 0;
	map->hot = 1;
}

static void			initiate_struct_piece(t_piece *p)
{
	p->piece = NULL;
	p->p_trimmed = NULL;
	p->size_x = 0;
	p->size_y = 0;
	p->check_sum = 0;
	p->distance_x = 0;
	p->distance_y = 0;
	p->start_x = 0;
	p->start_y = 0;
	p->trim_x = 0;
	p->trim_y = 0;
	p->trim_size_x = 0;
	p->trim_size_y = 0;
	p->final_x = 0;
	p->final_y = 0;
}

static void			initiate_struct_heat(t_heat *heat)
{
	heat->array[0] = 0;
	heat->array[1] = 0;
	heat->array[2] = 0;
	heat->array[3] = 0;
	heat->hot = NULL;
	heat->warm = NULL;
	heat->luke_warm = NULL;
	heat->cold = NULL;
}

void				initiate_structs(t_map *map, t_piece *p, t_heat *heat)
{
	initiate_struct_map(map);
	initiate_struct_piece(p);
	initiate_struct_heat(heat);
}
