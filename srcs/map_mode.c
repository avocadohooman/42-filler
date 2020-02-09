/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_mode.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmolin <gmolin@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 13:50:13 by gmolin            #+#    #+#             */
/*   Updated: 2020/02/09 11:29:59 by gmolin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

static void			fetch_map_size(t_map *map, char *line)
{
	int	i;

	map->size_y = ft_atoi(&line[8]);
	i = 8 + ft_len(map->size_y);
	map->size_x = ft_atoi(&line[i]);
}

static void			fetch_map(t_map *map, int fd)
{
	int		k;
	char	*line;

	k = 0;
	ft_get_next_line(fd, &line);
	ft_strdel(&line);
	map->board = (char**)malloc(sizeof(char*) * map->size_y + 1);
	while (k < map->size_y && ft_get_next_line(fd, &line) == 1)
	{
		map->board[k] = ft_strdup((const char*)&line[4]);
		ft_strdel(&line);
		k++;
	}
	map->board[k] = NULL;
	map->check_sum = count_pieces(map->board, map->token_me, 0, 0);
}

static void			fetch_pos(t_map *map)
{
	int		x;
	int		y;

	y = 0;
	while (y < map->size_y && map->board[y])
	{
		x = 0;
		while (x < map->size_x && map->board[y][x])
		{
			if (ft_strchr(map->token_me, map->board[y][x]) && !map->token_pos_me)
			{
				map->pos_me_x = x;
				map->pos_me_y = y;
				map->token_pos_me = 1;
			}
			if (ft_strchr(map->token_en, map->board[y][x]) && !map->token_pos_en)
			{
				map->pos_en_x = x;
				map->pos_en_y = y;
				map->token_pos_en = 1;
			}
			x++;
		}
		y++;
	}
}

void				map_mode(t_map *map, char *line, int fd)
{
	fetch_map_size(map, line);
	fetch_map(map, fd);
	fetch_pos(map);
}
