/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_mode.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmolin <gmolin@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 13:50:13 by gmolin            #+#    #+#             */
/*   Updated: 2020/02/02 12:46:50 by gmolin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

static  void        fetch_map_size(t_map *map, char *line)
{
    int     i;

    map->size_y = ft_atoi(&line[8]);
    i = 8 + ft_len(map->size_y);
    map->size_x = ft_atoi(&line[i]);
    map->start_x = map->size_x / 2;
	map->start_y = map->size_y / 2;
}

static  void        fetch_map(t_map *map, int fd)
{
    int     k;
    char    *line;

    k = 0;
    if (map->board != NULL)
        free(map->board);
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

// static  void        fetch_pos(t_map *map)
// {
//     int      x;
//     int      y;
//     int      token;

//     y = 0;
//     token = 0;
//     while (y < map->size_y && map->board[y])
//     {
//         x = 0;
//         while (x < map->size_x && map->board[y][x])
//         {
//             if (ft_strchr(map->token_me, map->board[y][x]))
//             {
//                 map->pos_me_x = x;
//                 map->pos_me_y = y;
//             }
//             else if (ft_strchr(map->token_en, map->board[y][x]) && token == 0)
//             {
//                 map->pos_en_x = x;
//                 map->pos_en_y = y;
//                 token = 1;
//             }
//             x++;
//         }
//         y++;
//     }
// }

void                map_mode(t_map *map, char *line, int fd)
{
    fetch_map_size(map, line);
    // ft_strdel(&line);
    fetch_map(map, fd);
    //fetch_pos(map);
    // int i;

	// i = 0;
	// ft_printf("********* CURRENT BOARD: *********\n");
    // while (i < map->size_y)
    // {
    //     ft_printf("%2d %s\n", i, map->board[i]);
    //     i++;
    // }
}
