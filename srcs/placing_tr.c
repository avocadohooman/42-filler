/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   placing_tr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmolin <gmolin@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 10:09:01 by gmolin            #+#    #+#             */
/*   Updated: 2020/02/05 11:20:51 by gmolin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

static 	int				placing_engine_tr(t_map *map, t_piece *piece, int start_y, int start_x)
{
	int		x;
	int		y;
	int		pos_x;
	char	**area;

	y = piece->trim_size_y - 1;
	// ft_printf("TR Y: %d\n", y);
	// ft_printf("START Y: %d\nSTART X: %d\n", start_y, start_x);
	pos_x = start_x;
	area = ft_2dstrdup(map->board);
	while (start_y >= 0 && y >= 0)
	{
		x = 0;
		while (start_x < map->size_x && map->board[start_y][start_x] && piece->p_trimmed[y][x])
		{	
			if (!(ft_strchr(map->token_en, area[start_y][start_x])) && area[start_y][start_x] &&
				piece->p_trimmed[y][x] != '.')
				area[start_y][start_x] = piece->p_trimmed[y][x];
			x++;
			start_x++;
		}
		start_x = pos_x + 0;
		y--;
		start_y--;
	}
	// int	i = 0;
	// while (i < map->size_y)
    // {
    //     ft_printf("%2d %s\n", i, area[i]);
    //     i++;
    // }
	if (validator(map, piece, area) == 0)
	{
		cleaner(area);
		return (0);
	}
	cleaner(map->board);
	map->board = ft_2dstrdup(area);
	cleaner(area);
	return (1);
}

int						placing_tr(t_map *map, t_piece *piece)
{
	int tmp;
	int start_x;
	int start_y;
	
	start_x = map->start_x;
	start_y = map->start_y;
	// ft_printf("TR\n");
	tmp = start_x;
	while (placing_engine_tr(map, piece, start_y, start_x) == 0)
	{
		if (start_x < map->size_x)
			start_x++;
		if (start_x >= map->size_x)
		{
			start_x = tmp;
			start_y--;
		}
		if (start_y < 0)
			return (0);
	}
		// ft_printf("Found Place\n");
	return (1);
}


// int						placing_tr(t_map *map, t_piece *piece, int start_y, int start_x)
// {
// 	map->board_backup = ft_2dstrdup(map->board);
// 	int tmp;

// 	// ft_printf("TR\n");
// 	tmp = start_x;
// 	while (placing_engine_tr(map, piece, start_y, start_x) == 0)
// 	{
// 		map->board = ft_2dstrdup(map->board_backup);
// 		if (start_x < map->size_x)
// 			start_x++;
// 		if (start_x >= map->size_x)
// 		{
// 			start_x = tmp;
// 			start_y--;
// 		}
// 		if (start_y < 0)
// 		{
// 			free(map->board_backup);
// 			return (0);
// 		}	
// 	}
// 		// ft_printf("Found Place\n");

// 	free(map->board_backup);
// 	free(piece->p_trimmed);
// 	return (1);
// }
