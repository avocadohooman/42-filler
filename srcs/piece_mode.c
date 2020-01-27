/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   piece_mode.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmolin <gmolin@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 15:41:48 by gmolin            #+#    #+#             */
/*   Updated: 2020/01/27 15:34:17 by gmolin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

static  void        fetch_piece_size(t_piece *piece, char *line)
{
    int     i;

    piece->size_y = ft_atoi(&line[6]);
    i = 6 + ft_len(piece->size_y);
    piece->size_x = ft_atoi(&line[i]);
}

static  void        fetch_piece(t_piece *piece, char  *line, int fd)
{
    int     k;

    k = 0;
    piece->piece = (char**)malloc(sizeof(char*) * piece->size_y + 1);
    while (k < piece->size_y)
    {
        ft_get_next_line(fd, &line);
        piece->piece[k] = ft_strdup((const char*)line);
        ft_strdel(&line);
        k++;
    }
    piece->piece[k] = NULL;
	piece->check_sum = count_pieces(piece->piece, "*");
}


static void			fetch_pos(t_piece *piece)
{
	int		x;
	int		y;
	int		token;

	y = 0;
	token = 0;
	while (piece->piece[y])
	{
		x = 0;
		while (piece->piece[y][x])
		{
			if (piece->piece[y][x] == '*' && token == 0)
			{
				token = 1;
				piece->distance_x = x;
				piece->distance_y = y;
			}
			x++;
		}
		y++;
	}
}

void                piece_mode(t_piece *piece, char *line, int fd)
{
    fetch_piece_size(piece, line);
    fetch_piece(piece, line, fd);
    fetch_pos(piece);
}
