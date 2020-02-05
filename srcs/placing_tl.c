/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   placing_tl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmolin <gmolin@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 10:09:01 by gmolin            #+#    #+#             */
/*   Updated: 2020/02/05 11:20:43 by gmolin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

static 	int				placing_engine_tl(t_map *map, t_piece *piece, int start_y, int start_x)
{
	int		x;
	int		y;
	int		pos_x;
	char	**area;

	y = piece->trim_size_y - 1;
	// 	ft_printf("TL start x: %d\nTL start y: %d\n", start_x, start_y);
	pos_x = start_x;
	area = ft_2dstrdup(map->board);
	while (start_y >= 0 && y >= 0)
	{
		x = piece->trim_size_x - 1;
		// ft_printf("TL X: %d\n", x);
		// ft_printf("%s\n%c\n", piece->p_trimmed[y], piece->p_trimmed[y][x]);
		while (start_x >= 0 && x >= 0)
		{	
			// ft_printf("TL X: %d\n", x);
			if (!(ft_strchr(map->token_en, area[start_y][start_x])) && area[start_y][start_x] &&
				piece->p_trimmed[y][x] != '.')
				area[start_y][start_x] = piece->p_trimmed[y][x];
			x--;
			start_x--;
		}
		start_x = pos_x + 0;
		y--;
		start_y--;
	}
	// int	i = 0;
	// while (i < map->size_y)
    // {
    //     ft_printf("%2d %s\n", i, map->board_backup[i]);
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


int						placing_tl(t_map *map, t_piece *piece)
{
	int tmp;
	int start_x;
	int start_y;
	
	start_x = map->start_x;
	start_y = map->start_y;
	// ft_printf("TL\n");
	tmp = start_x;
	while (placing_engine_tl(map, piece, start_y, start_x) == 0)
	{
		if (start_x >= 0)
			start_x--;
		if (start_x < 0)
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

// int						placing_tl(t_map *map, t_piece *piece, int start_y, int start_x)
// {
// 	map->board_backup = ft_2dstrdup(map->board);
// 	int tmp;

	// ft_printf("TL\n");
// 	tmp = start_x;
// 	while (placing_engine_tl(map, piece, start_y, start_x) == 0)
// 	{
// 		map->board = ft_2dstrdup(map->board_backup);
// 		if (start_x >= 0)
// 			start_x--;
// 		if (start_x < 0)
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
