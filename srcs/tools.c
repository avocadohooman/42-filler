/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmolin <gmolin@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 09:25:45 by gmolin            #+#    #+#             */
/*   Updated: 2020/01/27 16:15:13 by gmolin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

int				count_pieces(char **area, char *needle)
{
	int	k;
	int	i;
	int	count;

	k = 0;
	count = 0;
	while (area[k])
	{
		i = 0;
		while (area[k][i])
		{
			if (ft_strchr(needle, area[k][i]))
				count++;
			i++;
		}
		k++;
	}
	return (count);
}

void			return_coordinates(t_map *map, t_piece *piece)
{
	int y;
	int x;
	int token;

	y = 0;
	x = 0;
	token = 0;
	while (map->board[y])
	{
		x = 0;
		while (map->board[y][x])
		{
			if (map->board[y][x] == '*' && token != 1)
			{
				piece->final_x = x;
				piece->final_y = y;
				token = 1;
			}
			x++;
		}
		y++;
	}
	piece->final_x -= piece->distance_x;
	piece->final_y -= piece->distance_y;
}
