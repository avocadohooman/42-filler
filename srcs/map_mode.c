/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_mode.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmolin <gmolin@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 13:50:13 by gmolin            #+#    #+#             */
/*   Updated: 2020/02/05 11:19:29 by gmolin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

static  void        fetch_map_size(t_map *map, char *line)
{
    int     i;

    map->size_y = ft_atoi(&line[8]);
    i = 8 + ft_len(map->size_y);
    map->size_x = ft_atoi(&line[i]);
    // map->start_x = map->size_x / 2;
	// map->start_y = map->size_y / 2;
}

static  void        fetch_map(t_map *map, int fd)
{
    int     k;
    char    *line;

    k = 0;
    // if (map->board != NULL)
    //     cleaner(map->board);
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

static  void        fetch_pos(t_map *map)
{
    int      		x;
    int      		y;
	int				token_me;
	int				token_en;

    y = 0;
	token_me = 0;
	token_en = 0;
    while (y < map->size_y && map->board[y])
    {
        x = 0;
        while (x < map->size_x && map->board[y][x])
        {
            if (ft_strchr(map->token_me, map->board[y][x]) && map->token_pos_me == 0)
			// if (ft_strchr(map->token_me, map->board[y][x]))
            {
                map->pos_me_x = x;
                map->pos_me_y = y;
				map->token_pos_me = 1;
			}
            if (ft_strchr(map->token_en, map->board[y][x]) && map->token_pos_en == 0)
			// if (ft_strchr(map->token_en, map->board[y][x]) && token_en == 0)
            {
                map->pos_en_x = x;
                map->pos_en_y = y;
                map->token_pos_en = 1;
				// token_en = 1;
            }
            x++;
        }
        y++;
    }
	// ft_printf("token; %d\n", token_en);
}

void                map_mode(t_map *map, char *line, int fd)
{
    fetch_map_size(map, line);
    // ft_strdel(&line);
    fetch_map(map, fd);
    fetch_pos(map);
	
	/*
	** ------ Test setup #4 ------
	*/

	// map->start_x = map->pos_me_x;
	// map->start_y = map->pos_me_y;	

	/*
	** ------ Test setup #3 ------
	*/

	// map->start_x = map->pos_en_x;
	// map->start_y = map->pos_en_y;

	/*
	** ------ Test setup #2.7 ------
	*/

	// if (map->pos_me_y > map->size_y / 2 && map->pos_me_y < map->pos_en_y)
	// {
	// 	map->start_y = map->pos_en_y - 5;
	// 	map->start_x = map->size_x / 2;
	// }
	// else if (map->pos_me_y < map->size_y / 2 && map->pos_me_y < map->pos_en_y)
	// {
	// 	map->start_y = map->size_y / 2;
	// 	map->start_x = map->size_x / 2;
	// }
	// else if (map->pos_me_y > map->start_y / 2 && map->pos_me_y > map->pos_en_y)
	// {
	// 	map->start_y = map->pos_en_y;
	// 	map->start_x = map->pos_en_x;
	// }

	/*
	** ------ Test setup #2.6 ------
	*/

	// if (map->pos_me_y > map->size_y / 2 && map->pos_me_y < map->pos_en_y)
	// {
	// 	map->start_y = map->pos_en_y - 7;
	// 	map->start_x = map->size_x / 2;
	// }
	// else if (map->pos_me_y < map->size_y / 2 && map->pos_me_y < map->pos_en_y)
	// {
	// 	map->start_y = map->size_y / 2;
	// 	map->start_x = map->size_x / 2;
	// }
	// else if (map->pos_me_y > map->start_y / 2 && map->pos_me_y > map->pos_en_y)
	// {
	// 	map->start_y = map->pos_en_y;
	// 	map->start_x = map->pos_en_x;
	// }

	/*
	** ------ Test setup #2.5 ------
	*/

	// if (map->pos_me_y > map->size_y / 2 && map->pos_me_y < map->pos_en_y)
	// {
	// 	map->start_y = map->size_y / 2;
	// 	map->start_x = map->pos_me_x;
	// }
	// else if (map->pos_me_y < map->size_y / 2 && map->pos_me_y < map->pos_en_y)
	// {
	// 	map->start_y = map->size_y / 2;
	// 	map->start_x = map->size_x / 2;
	// }
	// else if (map->pos_me_y > map->start_y / 2 && map->pos_me_y > map->pos_en_y)
	// {
	// 	map->start_y = map->pos_en_y;
	// 	map->start_x = map->pos_en_x;
	// }

	/*
	** ------ Test setup #2.4 ------
	*/

	if (map->pos_me_y > map->size_y / 2 && map->pos_me_y < map->pos_en_y)
	{
		map->start_y = map->pos_en_y - 6;
		map->start_x = map->size_x / 2;
	}
	else if (map->pos_me_y < map->size_y / 2 && map->pos_me_y < map->pos_en_y)
	{
		map->start_y = map->size_y / 2;
		map->start_x = map->size_x / 2;
	}

	/*
	** ------ Test setup map 02 #2.0 ------
	*/

	else if (map->pos_me_y > map->start_y / 2 && map->pos_me_y > map->pos_en_y)
	{
		if (map->size_y > 24)
		{
			map->start_y = map->pos_en_y + 30;
			map->start_x = 0;
		}
		else if (map->size_y > 15 && map->size_y <= 24)
			{
				map->start_y = map->pos_en_y + 13;
				map->start_x = 1;
			}
		else 
			{
				map->start_y =  map->pos_en_y - 4;
				map->start_x =  map->pos_en_x + 6;
			}
	}
	/*
	** ------ Test setup map 02 #1.0 ------
	*/

	// else if (map->pos_me_y > map->start_y / 2 && map->pos_me_y > map->pos_en_y)
	// {
	// 	map->start_y = map->size_y / 2;
	// 	map->start_x = map->size_x / 2;
	// }

	/*
	** ------ Test setup #2.3 ------
	*/

	// if (map->pos_me_y > map->size_y / 2 && map->pos_me_y < map->pos_en_y)
	// {
	// 	map->start_y = map->pos_en_y;
	// 	map->start_x = map->size_x / 2;
	// }
	// else if (map->pos_me_y < map->size_y / 2 && map->pos_me_y < map->pos_en_y)
	// {
	// 	map->start_y = map->size_y / 2;
	// 	map->start_x = map->size_x / 2;
	// }
	// else if (map->pos_me_y > map->start_y / 2 && map->pos_me_y > map->pos_en_y)
	// {
	// 	map->start_y = map->pos_en_y;
	// 	map->start_x = map->pos_en_x;
	// }

	/*
	** ------ Test setup #2.2 ------
	*/

	// if (map->pos_me_y > map->size_y / 2 && map->pos_me_y < map->pos_en_y)
	// {
	// 	map->start_y = map->size_y / 2;
	// 	map->start_x = map->pos_en_x;
	// }
	// else if (map->pos_me_y < map->size_y / 2 && map->pos_me_y < map->pos_en_y)
	// {
	// 	map->start_y = map->size_y / 2;
	// 	map->start_x = map->size_x / 2;
	// }
	// else if (map->pos_me_y > map->start_y / 2 && map->pos_me_y > map->pos_en_y)
	// {
	// 	map->start_y = map->pos_en_y;
	// 	map->start_x = map->pos_en_x;
	// }

	/*
	** ------ Test setup #2.1 ------
	*/

	// if (map->pos_me_y > map->size_y / 2 && map->pos_me_y < map->pos_en_y)
	// {
	// 	map->start_y = map->pos_en_y - 3;
	// 	map->start_x = map->pos_en_x;
	// }
	// else if (map->pos_me_y < map->size_y / 2 && map->pos_me_y < map->pos_en_y)
	// {
	// 	map->start_y = map->size_y / 2;
	// 	map->start_x = map->size_x / 2;
	// }
	// else if (map->pos_me_y > map->start_y / 2 && map->pos_me_y > map->pos_en_y)
	// {
	// 	map->start_y = map->pos_en_y;
	// 	map->start_x = map->pos_en_x;
	// }

	/*
	** ------ Test setup #2 ------
	*/

	// ft_printf("\npos y: %d\npos x: %d\nmap size y/2: %d\nmap size x/2: %d\n", map->pos_en_y, map->pos_en_x, map->size_y / 2, map->size_x / 2);
	// if (map->pos_me_y > map->size_y / 2 && map->pos_me_y < map->pos_en_y)
	// {
	// 	map->start_y = map->pos_me_y;
	// 	map->start_x = map->pos_me_x;
	// }
	// else if (map->pos_me_y < map->size_y / 2 && map->pos_me_y < map->pos_en_y)
	// {
	// 	map->start_y = map->size_y / 2;
	// 	map->start_x = map->size_x / 2;
	// }
	// else if (map->pos_me_y > map->start_y / 2 && map->pos_me_y > map->pos_en_y)
	// {
	// 	map->start_y = map->pos_en_y;
	// 	map->start_x = map->pos_en_x;
	// }
	/*
	** ------ Test setup #1 ------
	*/

	// if (map->pos_en_y < map->pos_me_y)
	// {
	// 	map->start_y = map->pos_en_y;
	// 	map->start_x = map->pos_en_x;
	// }
	// if (map->pos_me_y < map->size_y / 2)
	// {
	// 	map->start_y = map->size_y / 2;
	// 	map->start_x = map->size_y / 2;
	// }
	// if (map->pos_en_y > map->size_y / 2 && map->pos_en_y > map->pos_me_y) 
	// {
	// 	map->start_y = map->size_y / 2;
	// 	map->start_x = map->size_y / 2;
	// }

		/*
	** ------ Test setup #0 ------
	*/

	// map->start_x = map->size_x / 2;
	// map->start_y = map->size_y / 2;

    // int i;

	// i = 0;
	// ft_printf("********* CURRENT BOARD: *********\n");
    // while (i < map->size_y)
    // {
    //     ft_printf("%2d %s\n", i, map->board[i]);
    //     i++;
    // }
}
