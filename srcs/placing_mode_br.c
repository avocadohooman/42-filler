/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   placing_mode_br.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmolin <gmolin@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 10:09:01 by gmolin            #+#    #+#             */
/*   Updated: 2020/01/30 18:02:18 by gmolin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

static 	int				placing_engine_br(t_map *map, t_piece *piece, int end_y, int end_x)
{
	int		x;
	int		y;
	int		pos_x;

	y = 0;
	pos_x = end_x;
	while (map->board[end_y] && piece->p_trimmed[y])
	{
		x = 0;
		while (map->board[end_y][end_x] && piece->p_trimmed[y][x])
		{
				
			if (!(ft_strchr(map->token_en, map->board[end_y][end_x])) && map->board[end_y][end_x])
				map->board[end_y][end_x] = piece->p_trimmed[y][x];
			x++;
			end_x++;
		}
		end_x = pos_x + 0;
		y++;
		end_y++;
	}
	if (validator(map, piece) == 0)
		return (0);
	return (1);
}

int						placing_br(t_map *map, t_piece *piece, int end_y, int end_x)
{
	map->board_backup = ft_2dstrdup(map->board);
	while (placing_engine_br(map, piece, end_y, end_x) == 0)
	{
		map->board = ft_2dstrdup(map->board_backup);
		if (map->board[end_y][end_x] != '\0')
			end_x++;
		else
		{
			end_x = 0;
			end_y++;
		}
	}
	map->board_backup = NULL;
	return (1);
}
