/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initiate_struct.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmolin <gmolin@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 12:25:16 by gmolin            #+#    #+#             */
/*   Updated: 2020/01/30 13:49:58 by gmolin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

static void					initiate_struct_map(t_map *map)
{
	map->board = NULL;
	map->board_backup = NULL;
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
	map->check_sum = 0;
}

static void					initiate_struct_piece(t_piece *piece)
{
	piece->piece = NULL;
	piece->p_trimmed = NULL;
	piece->size_x = 0;
	piece->size_y = 0;
	piece->check_sum = 0;
	piece->distance_x = 0;
	piece->distance_y = 0;
	piece->start_x = 0;
	piece->start_y = 0;
	piece->trim_x = 0;
	piece->trim_y = 0;
	piece->trim_size_x = 0;
	piece->trim_size_y = 0;
	piece->final_x = 0;
	piece->final_y = 0;
}

static void					initiate_struct_heat(t_heat *heat)
{
	heat->tr = 0;
	heat->tl = 0;
	heat->bl = 0;
	heat->br = 0;
	heat->hot = NULL;
	heat->warm = NULL;
	heat->luke_warm = NULL;
	heat->cold = NULL;
}

void						initiate_structs(t_map *map, t_piece *piece, t_heat *heat)
{
	initiate_struct_map(map);
	initiate_struct_piece(piece);
	initiate_struct_heat(heat);
}