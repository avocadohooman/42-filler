/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   placing_mode.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmolin <gmolin@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 10:09:01 by gmolin            #+#    #+#             */
/*   Updated: 2020/01/29 11:36:47 by gmolin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

static	int				validator(t_map *map, t_piece *piece)
{
	int		goal;
	int		current;
	int		pieces;

	goal = map->check_sum + (piece->check_sum - 1);
	if (map->player == 1)
		current = count_pieces(map->board, "oO*", 0, 0);
	else if (map->player == 2)
		current = count_pieces(map->board, "xX*", 0, 0);
	pieces = count_pieces(map->board, "*", 0, 0);
	if (goal == current && pieces == piece->check_sum)
		return (1);
	return (0);
}

static 	int				placing(t_map *map, t_piece *piece, int my, int mx)
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
			{
				while (ft_strchr(map->token_me, map->board[my][mx]) && piece->p_trimmed[y][x] == '.')
					mx++;
				map->board[my][mx] = piece->p_trimmed[y][x];
			}
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

int						placing_mode(t_map *map, t_piece *piece, int y, int x)
{
	map->board_backup = ft_2dstrdup(map->board);
	while (placing(map, piece, y, x) == 0)
	{
		map->board = ft_2dstrdup(map->board_backup);
		if (map->board[y][x] != '\0')
			x++;
		else
		{
			x = 0;
			y++;
		}
	}
	map->board_backup = NULL;
	return (1);
}
