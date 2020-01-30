/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   placing_mode_bl.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmolin <gmolin@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 10:09:01 by gmolin            #+#    #+#             */
/*   Updated: 2020/01/30 17:55:49 by gmolin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

static 	int				placing_engine_bl(t_map *map, t_piece *piece, int my, int mx)
{
	int		x;
	int		y;
	int		pos_x;

	y = 0;
	pos_x = mx;
	while (map->board[my] && piece->p_trimmed[y])
	{
		x = 0;
		while (map->board[my][mx] && piece->p_trimmed[y][x])
		{
				
			if (!(ft_strchr(map->token_en, map->board[my][mx])) && map->board[my][mx])
				map->board[my][mx] = piece->p_trimmed[y][x];
			x++;
			mx++;
		}
		mx = pos_x + 0;
		y++;
		my++;
	}
	if (validator(map, piece) == 0)
		return (0);
	return (1);
}