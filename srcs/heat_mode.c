/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heat_mode.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmolin <gmolin@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 16:24:40 by gmolin            #+#    #+#             */
/*   Updated: 2020/01/28 16:31:15 by gmolin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"


static int				**represent_int_table(t_map *map)
{
	int			**tab;
	int			y;
	int			x;

	y = 0;
	x = 0;
	if ((tab = (int**)malloc(sizeof(int*) * map->size_y)))
	{
		while (y < map->size_y)
		{
			tab[y] = (int*)malloc(sizeof(int) * map->size_x);
			x = 0;
			while (x < map->size_x)
			{
				if (ft_strchr(map->token_me, map->board[y][x] && map->board[y][x] != '.'))
					tab[y][x] = 0;
				else
					tab[y][x] = -1;
				x++;
			}
			y++;
		}
	}
	return (tab);
}

void        heat_mode(t_map *map, t_piece *piece)
{
    map->heat = represent_int_table(map);
    int i;
    while (i < map->size_y)
    {
        ft_printf("%2 d\n", map->heat[i]);
        i++;
    }
}