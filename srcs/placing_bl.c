/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   placing_bl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmolin <gmolin@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 10:09:01 by gmolin            #+#    #+#             */
/*   Updated: 2020/02/04 09:20:22 by gmolin           ###   ########.fr       */
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
	while (start_y < map->size_y && y < piece->trim_size_y)
	{
		x = piece->trim_size_x - 1;
		// ft_printf("BL X: %d\n", x);
		while (start_x >= 0 && x >= 0)
		{	
			if (!(ft_strchr(map->token_en, map->board[start_y][start_x])) && map->board[start_y][start_x] &&
				piece->p_trimmed[y][x] != '.' && x >= 0)
				map->board[start_y][start_x] = piece->p_trimmed[y][x];
			x--;
			start_x--;
		}
		start_x = pos_x + 0;
		y++;
		start_y++;
	}
	// int	i = 0;
	// while (i < map->size_y)
    // {
    	// ft_printf("%2d %s\n", i, map->board[i]);
    //     i++;
    // }
	if (validator(map, piece) == 0)
	{
		free(map->board);
		return (0);
	}
	return (1);
}

int						placing_bl(t_map *map, t_piece *piece)
{
	map->board_backup = ft_2dstrdup(map->board);
	int tmp;
	int start_x;
	int start_y;
	
	start_x = map->start_x;
	start_y = map->start_y;
	// ft_printf("BL\n");
	tmp = start_x;
	while (placing_engine_bl(map, piece, start_y, start_x) == 0)
	{
		map->board = ft_2dstrdup(map->board_backup);
		if (start_x >= 0)
			start_x--;
		if (start_x < 0)
		{
			start_x = tmp;
			start_y++;
		}
		if (start_y >= map->size_y)
		{
			free(map->board_backup);
			return (0);
		}	
	}
	// ft_printf("Found Place\n");
	free(map->board_backup);
	free(piece->p_trimmed);
	return (1);
}


// int						placing_bl(t_map *map, t_piece *piece, int start_y, int start_x)
// {
// 	map->board_backup = ft_2dstrdup(map->board);
// 	int tmp;

// 	// ft_printf("BL\n");
// 	tmp = start_x;
// 	while (placing_engine_bl(map, piece, start_y, start_x) == 0)
// 	{
// 		map->board = ft_2dstrdup(map->board_backup);
// 		if (start_x >= 0)
// 			start_x--;
// 		if (start_x < 0)
// 		{
// 			start_x = tmp;
// 			start_y++;
// 		}
// 		if (start_y >= map->size_y)
// 		{
// 			free(map->board_backup);
// 			return (0);
// 		}	
// 	}
// 	// ft_printf("Found Place\n");
// 	free(map->board_backup);
// 	free(piece->p_trimmed);
// 	return (1);
// }
