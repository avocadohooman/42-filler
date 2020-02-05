/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   piece_mode.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmolin <gmolin@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 15:41:48 by gmolin            #+#    #+#             */
/*   Updated: 2020/02/05 12:21:11 by gmolin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

static  void        fetch_piece_size(t_piece *piece, char *line)
{
    int     i;

    piece->size_y = ft_atoi(&line[6]);
    i = 6 + ft_len(piece->size_y);
    piece->size_x = ft_atoi(&line[i]);
	ft_strdel(&line);
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

static  void        fetch_piece(t_piece *piece, int fd)
{
    int     k;
	char	*line;

    k = 0;
    piece->piece = (char**)malloc(sizeof(char*) * piece->size_y + 1);
    while (k < piece->size_y)
    {
        ft_get_next_line(fd, &line);
        piece->piece[k] = ft_strdup((const char*)line);
		k++;
        ft_strdel(&line);
    }
    piece->piece[k] = NULL;
	piece->check_sum = count_pieces(piece->piece, "*", 0, 0);
	fetch_pos(piece);
}

static void			trim_piece(t_piece *piece)
{
	int y;
	int x;
	int tmp;

	y = 0;
	tmp = piece->start_x;
	piece->p_trimmed = (char**)malloc(sizeof(char*) * piece->trim_size_y + 1);
	while (y < piece->trim_size_y)
	{
		x = 0;
		piece->start_x = tmp;
		piece->p_trimmed[y] = (char*)malloc(sizeof(char) * piece->trim_size_x + 1);
		while (x < piece->trim_size_x)
			piece->p_trimmed[y][x++] = piece->piece[piece->start_y][piece->start_x++];
		piece->p_trimmed[y][x] = '\0';
		piece->start_y++;
		y++;
	}
	piece->p_trimmed[y] = NULL;
	cleaner(piece->piece);
}

void                piece_mode(t_piece *piece, char *line, int fd)
{
    fetch_piece_size(piece, line);
    fetch_piece(piece, fd);
	tailor(piece);
	trim_piece(piece);
}
