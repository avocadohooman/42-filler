/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   piece_mode.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmolin <gmolin@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 15:41:48 by gmolin            #+#    #+#             */
/*   Updated: 2020/01/25 16:04:35 by gmolin           ###   ########.fr       */
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
}

void                piece_mode(t_piece *piece, char *line, int fd)
{
    fetch_piece_size(piece, line);
    fetch_piece(piece, line, fd);
    //fetch_pos(piece);
}