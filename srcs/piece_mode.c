/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   piece_mode.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmolin <gmolin@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 15:41:48 by gmolin            #+#    #+#             */
/*   Updated: 2020/02/09 11:38:22 by gmolin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

static void		fetch_piece_size(t_piece *p, char *line)
{
	int	i;

	p->size_y = ft_atoi(&line[6]);
	i = 6 + ft_len(p->size_y);
	p->size_x = ft_atoi(&line[i]);
	ft_strdel(&line);
}

static void		fetch_pos(t_piece *p)
{
	int		x;
	int		y;
	int		token;

	y = 0;
	token = 0;
	while (p->piece[y])
	{
		x = 0;
		while (p->piece[y][x])
		{
			if (p->piece[y][x] == '*' && token == 0)
			{
				token = 1;
				p->distance_x = x;
				p->distance_y = y;
			}
			x++;
		}
		y++;
	}
}

static void		fetch_piece(t_piece *p, int fd)
{
	int		k;
	char	*line;

	k = 0;
	p->piece = (char**)malloc(sizeof(char*) * p->size_y + 1);
	while (k < p->size_y)
	{
		ft_get_next_line(fd, &line);
		p->piece[k] = ft_strdup((const char*)line);
		k++;
		ft_strdel(&line);
	}
	p->piece[k] = NULL;
	p->check_sum = count_pieces(p->piece, "*", 0, 0);
	fetch_pos(p);
}

static void			trim_piece(t_piece *p)
{
	int y;
	int x;
	int tmp;

	y = 0;
	tmp = p->start_x;
	p->p_trimmed = (char**)malloc(sizeof(char*) * p->trim_size_y + 1);
	while (y < p->trim_size_y)
	{
		x = 0;
		p->start_x = tmp;
		p->p_trimmed[y] = (char*)malloc(sizeof(char) * p->trim_size_x + 1);
		while (x < p->trim_size_x)
			p->p_trimmed[y][x++] = p->piece[p->start_y][p->start_x++];
		p->p_trimmed[y][x] = '\0';
		p->start_y++;
		y++;
	}
	p->p_trimmed[y] = NULL;
	cleaner(p->piece);
}

void				piece_mode(t_piece *p, char *line, int fd)
{
	fetch_piece_size(p, line);
	fetch_piece(p, fd);
	tailor(p, -1, -1);
	trim_piece(p);
}
