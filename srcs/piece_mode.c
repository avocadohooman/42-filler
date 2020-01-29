/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   piece_mode.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmolin <gmolin@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 15:41:48 by gmolin            #+#    #+#             */
/*   Updated: 2020/01/29 18:06:49 by gmolin           ###   ########.fr       */
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
	piece->check_sum = count_pieces(piece->piece, "*", 0, 0);
	fetch_pos(piece);
}

static void			trim_piece(t_piece *piece)
{
	int y;
	int x;
	int tmp;

	y = 0;
	tmp = piece->trim_x;
	piece->p_trimmed = (char**)malloc(sizeof(char*) * (piece->size_y - piece->trim_y) + 1);
	while (y < piece->trim_y + 1)
	{
		x = 0;
		piece->trim_x = tmp;
		piece->p_trimmed[y] = (char*)malloc(sizeof(char) * (piece->size_x - piece->trim_x) + 1);
		while (x < piece->size_x && piece->piece[y][piece->trim_x])
			piece->p_trimmed[y][x++] = piece->piece[y][piece->trim_x++];
		piece->p_trimmed[y][x] = '\0';
		y++;
	}
	piece->p_trimmed[y] = NULL;
	free(piece->piece);
}

void                piece_mode(t_piece *piece, char *line, int fd)
{
    fetch_piece_size(piece, line);
    fetch_piece(piece, line, fd);
	tailor(piece);
	trim_piece(piece);
}
