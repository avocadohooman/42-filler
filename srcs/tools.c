/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmolin <gmolin@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 09:25:45 by gmolin            #+#    #+#             */
/*   Updated: 2020/02/06 17:04:35 by gmolin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

int					validator(t_map *map, t_piece *piece)
{
	int		goal;
	int		current;
	int		pieces;

	goal = map->check_sum + (piece->check_sum - 1);
	if (map->player == 1)
		current = count_pieces(map->area, "Oo*", 0, 0);
	if (map->player == 2)
		current = count_pieces(map->area, "Xx*", 0, 0);
	pieces = count_pieces(map->area, "*", 0, 0);
	if (goal == current && pieces == piece->check_sum)
		return (1);
	return (0);
}

int					count_pieces(char **area, char *needle, int min_y, int min_x)
{
	int	count;
	int	y;
	int x;

	count = 0;
	y = min_y;
	while (area[y])
	{
		x = min_x;
		while (area[y][x])
		{
			if (ft_strchr(needle, area[y][x]))
				count++;
			x++;
		}
		y++;
	}
	return (count);
}

void				tailor(t_piece *piece)
{
	int		y;
	int		x;

	y = -1;
	piece->start_x = piece->size_x;
	piece->start_y = piece->size_y;
	while (++y < piece->size_y)
	{
		x = -1;
		while (++x < piece->size_x)
			if (piece->piece[y][x] == '*')
			{
				if (x < piece->start_x)
					piece->start_x = x;
				if (x > piece->trim_x)
					piece->trim_x = x;
				if (y < piece->start_y)
					piece->start_y = y;
				if (y > piece->trim_y)
					piece->trim_y = y;
			}
	}
	piece->trim_size_x = (piece->trim_x - piece->start_x) + 1;
	piece->trim_size_y = (piece->trim_y - piece->start_y) + 1;
	(piece->trim_size_x > piece->size_x) ? piece->trim_size_x -= 1 : 0;
	(piece->trim_size_y > piece->size_y) ? piece->trim_size_y -= 1 : 0;}

void				cleaner(char **str)
{
	int		i;

	i = 0;
	while (str[i] != NULL)
	{
		ft_strdel(&str[i]);
		i++;
	}
	free(str);
	str = NULL;
}
