/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmolin <gmolin@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 09:25:45 by gmolin            #+#    #+#             */
/*   Updated: 2020/02/09 13:21:59 by gmolin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

int				heat_counter(t_map *map, int start_y, int start_x)
{
	int count;
	int y;
	int x;
	int end_y;
	int end_x;

	(start_y == 0) ? end_y = map->start_y : 0;
	(start_x == 0) ? end_x = map->start_x : 0;
	(start_x == map->start_x) ? end_x = map->size_x : 0;
	(start_y == map->start_y) ? end_y = map->size_y : 0;
	count = 0;
	y = start_y;
	while (y < end_y)
	{
		x = start_x;
		while (x < end_x)
		{
			if (ft_strchr(map->token_en, map->board[y][x]))
				count++;
			x++;
		}
		y++;
	}
	return (count);
}

int		validator(t_map *map, t_piece *p)
{
	int		goal;
	int		current;
	int		pieces;

	goal = map->check_sum + (p->check_sum - 1);
	if (map->player == 1)
		current = count_pieces(map->area, "Oo*", 0, 0);
	if (map->player == 2)
		current = count_pieces(map->area, "Xx*", 0, 0);
	pieces = count_pieces(map->area, "*", 0, 0);
	if (goal == current && pieces == p->check_sum)
		return (1);
	return (0);
}

int		count_pieces(char **area, char *needle, int min_y, int min_x)
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

void	tailor(t_piece *p, int y, int x)
{
	y = -1;
	p->start_x = p->size_x;
	p->start_y = p->size_y;
	while (++y < p->size_y)
	{
		x = -1;
		while (++x < p->size_x)
			if (p->piece[y][x] == '*')
			{
				if (x < p->start_x)
					p->start_x = x;
				if (x > p->trim_x)
					p->trim_x = x;
				if (y < p->start_y)
					p->start_y = y;
				if (y > p->trim_y)
					p->trim_y = y;
			}
	}
	p->trim_size_x = (p->trim_x - p->start_x) + 1;
	p->trim_size_y = (p->trim_y - p->start_y) + 1;
	(p->trim_size_x > p->size_x) ? p->trim_size_x -= 1 : 0;
	(p->trim_size_y > p->size_y) ? p->trim_size_y -= 1 : 0;
}

void	cleaner(char **str)
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
