/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmolin <gmolin@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 09:25:45 by gmolin            #+#    #+#             */
/*   Updated: 2020/02/02 12:36:22 by gmolin           ###   ########.fr       */
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
		current = count_pieces(map->board, "Oo*", 0, 0);
	else if (map->player == 2)
		current = count_pieces(map->board, "Xx*", 0, 0);
	pieces = count_pieces(map->board, "*", 0, 0);
	if (goal == current && pieces == piece->check_sum)
		return (1);
	return (0);
}

int					heat_counter(t_map *map, int start_y, int start_x)
{
	int count;
	int y;
	int x;
	int end_y;
	int end_x;

	(start_y == 0) ? end_y = map->size_y / 2 : 0;
	(start_x == 0) ? end_x = map->size_x / 2 : 0;
	(start_x == map->size_x / 2) ? end_x = map->size_x : 0;
	(start_y == map->size_y / 2) ? end_y = map->size_y : 0;
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
	// int i = 0;
	// ft_printf("Trim size x %d\nTrim size y %d\nPiece start x %d\nPiece start y %d\nPiece end x %d\nPiece end y %d\n", piece->trim_size_x, piece->trim_size_y, piece->start_x, piece->start_y, piece->trim_x, piece->trim_y);
    // while (piece->piece[i])
    // {
    //     ft_printf("%d %s\n", i, piece->piece[i]);
    //     i++;
    // }
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
	// if (piece->start_x != 0 && piece->start_y != 0)
	// {
		piece->trim_size_x = (piece->trim_x - piece->start_x) + 1;
		piece->trim_size_y = (piece->trim_y - piece->start_y) + 1;
		(piece->trim_size_x > piece->size_x) ? piece->trim_size_x -= 1 : 0;
		(piece->trim_size_y > piece->size_y) ? piece->trim_size_y -= 1 : 0;
	// }
	// ft_printf("Trim size x %d\nTrim size y %d\nPiece start x %d\nPiece start y %d\nPiece end x %d\nPiece end y %d\n", piece->trim_size_x, piece->trim_size_y, piece->start_x, piece->start_y, piece->trim_x, piece->trim_y);
}
