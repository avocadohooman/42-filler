/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   placing_engine_top.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmolin <gmolin@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 10:09:01 by gmolin            #+#    #+#             */
/*   Updated: 2020/01/30 23:32:10 by gmolin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

static 	int				placing_engine_tl(t_map *map, t_piece *piece, int start_y, int start_x)
{
	int		x;
	int		y;
	int		pos_x;

	y = 0;
	pos_x = start_x;
	while (start_y >= 0 && piece->p_trimmed[y])
	{
		x = 0;
		while (start_x > -1 && piece->p_trimmed[y][x])
		{	
			if (!(ft_strchr(map->token_en, map->board[start_y][start_x])) && map->board[start_y][start_x])
				map->board[start_y][start_x] = piece->p_trimmed[y][x];
			x++;
			start_x--;
		}
		start_x = pos_x + 0;
		y++;
		start_y--;
	}
	if (validator(map, piece) == 0)
		return (0);
	return (1);
}

static 	int				placing_engine_tr(t_map *map, t_piece *piece, int start_y, int start_x)
{
	int		x;
	int		y;
	int		pos_x;

	y = 0;
	pos_x = start_x;
	while (start_y > -1 && piece->p_trimmed[y])
	{
		x = 0;
		while (start_x <= map->size_x && piece->p_trimmed[y][x])
		{	
			if (!(ft_strchr(map->token_en, map->board[start_y][start_x])) && map->board[start_y][start_x])
				map->board[start_y][start_x] = piece->p_trimmed[y][x];
			x++;
			start_x++;
		}
		start_x = pos_x + 0;
		y++;
		start_y--;
	}
	if (validator(map, piece) == 0)
		return (0);
	return (1);
}

int						placing_tl(t_map *map, t_piece *piece, int start_y, int start_x)
{
	map->board_backup = ft_2dstrdup(map->board);
	int tmp;

	tmp = start_x;
	while (placing_engine_tl(map, piece, start_y, start_x) == 0)
	{
		map->board = ft_2dstrdup(map->board_backup);
		if (start_x > -1)
			start_x--;
		else
		{
			if (start_x - 1 < map->size_x && start_y - 1 < map->size_y)
				return (0);
			start_x = tmp;
			start_y--;
		}
	}
	map->board_backup = NULL;
	return (1);
}

int						placing_tr(t_map *map, t_piece *piece, int start_y, int start_x)
{
	map->board_backup = ft_2dstrdup(map->board);
	int tmp;

	tmp = start_x;
	while (placing_engine_tr(map, piece, start_y, start_x) == 0)
	{
		map->board = ft_2dstrdup(map->board_backup);
		if (map->board[start_y][start_x] != '\0')
			start_x++;
		else
		{
			if (start_x + 1 > map->size_x && start_y - 1 < map->size_y)
				return (0);
			start_x = start_x;
			start_y--;
		}
	}
	map->board_backup = NULL;
	return (1);
}
