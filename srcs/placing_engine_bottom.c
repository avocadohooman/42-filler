/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   placing_engine_bottom.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmolin <gmolin@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 10:09:01 by gmolin            #+#    #+#             */
/*   Updated: 2020/01/30 23:51:29 by gmolin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

static 	int				placing_engine_bl(t_map *map, t_piece *piece, int start_y, int start_x)
{
	int		x;
	int		y;
	int		pos_x;

	y = 0;
	pos_x = start_x;
	while (start_y <= map->size_y && piece->p_trimmed[y])
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
		start_y++;
	}
	if (validator(map, piece) == 0)
		return (0);
	return (1);
}

static 	int				placing_engine_br(t_map *map, t_piece *piece, int start_y, int start_x)
{
	int		x;
	int		y;
	int		pos_x;

	y = 0;
	pos_x = start_x;
	while (start_y < map->size_y && piece->p_trimmed[y])
	{
		x = 0;
		while (start_x < map->size_x && piece->p_trimmed[y][x])
		{	
			if (!(ft_strchr(map->token_en, map->board[start_y][start_x])) && map->board[start_y][start_x])
				map->board[start_y][start_x] = piece->p_trimmed[y][x];
			x++;
			start_x++;
		}
		start_x = pos_x + 0;
		y++;
		start_y++;
	}
	int	i = 0;
	while (i < map->size_y)
    {
        ft_printf("%2d %s\n", i, map->board[i]);
        i++;
    }
	if (validator(map, piece) == 0)
		return (0);
	return (1);
}


int						placing_bl(t_map *map, t_piece *piece, int start_y, int start_x)
{
	map->board_backup = ft_2dstrdup(map->board);
	int tmp;
	tmp = start_x;
	while (placing_engine_bl(map, piece, start_y, start_x) == 0)
	{
		map->board = ft_2dstrdup(map->board_backup);
		if (start_x > 0)
			start_x--;
		else
		{
			if (start_x - 1 < 0 && start_y + 1 > map->size_y)
				return (0);
			start_x = tmp;
			start_y++;
		}
	}
	map->board_backup = NULL;
	return (1);
}

int						placing_br(t_map *map, t_piece *piece, int start_y, int start_x)
{
	map->board_backup = ft_2dstrdup(map->board);
	int tmp;

	tmp = start_x;
	while (placing_engine_br(map, piece, start_y, start_x) == 0)
	{
		if (start_x > map->size_x && start_y > map->size_y)
			return (0);
		map->board = ft_2dstrdup(map->board_backup);
		if (start_x + 1 > map->size_x)
		{
			start_x = tmp;
			start_y++;
		}
		ft_printf("%d\n", start_x);
		start_x++;
	}
	map->board_backup = NULL;
	return (1);
}
