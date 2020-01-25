/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmolin <gmolin@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 15:57:47 by gmolin            #+#    #+#             */
/*   Updated: 2020/01/25 16:02:36 by gmolin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

static void					initiate_struct(t_map *map, t_piece *piece)
{
	map->board = NULL;
	map->p_name = NULL;
	map->token = "xX";
	map->player = 2;
	map->pos_me_x = 0;
	map->pos_me_y = 0;
	map->pos_en_x = 0;
	map->pos_en_x = 0;
	map->size_x = 0;
	map->size_y = 0;
	piece->piece = NULL;
	piece->size_x = 0;
	piece->size_y = 0;
}

static	void				fetch_player(t_map *map, int fd)
{
	char	*line;

	ft_get_next_line(fd, &line);
	if (line[10] != '1' || !line)
		ft_printf("error: bad player info\n");
	if (ft_strcmp("gmolin.filler]", &line[23]) == 0)
	{
		map->player = 1;
		map->token = "oO";
	}
	ft_strdel(&line);
}

static	int					input_scan(t_map *map, t_piece *piece, int fd)
{
	char *line;

	while (ft_get_next_line(fd, &line) > 0)
	{
		if (ft_strncmp(line, "Plateau", 6) == 0)
		{
			map_mode(map, line, fd);
			ft_strdel(&line);
		}
		else if (ft_strncmp("Piece", line, 4) == 0)
		{
		 	piece_mode(piece, line, fd);
		 	return (1);
		}
		else
			ft_strdel(&line);
	}
	return (0);
}

void 	test_printing(t_map *map, t_piece *piece)
{
	int i;

	i = 0;
	ft_printf("********* CURRENT BOARD: *********\n");
    while (i < map->size_y)
    {
        ft_printf("%2d %s\n", i, map->board[i]);
        i++;
    }	
	ft_printf("********* GAME STATS: *********\n");
	ft_printf("PLAYER: %d\n", map->player);
	ft_printf("TOKENS: %s\n", map->token);
	ft_printf("MAP SIZE:\nY: %d\nX: %d\n", map->size_y, map->size_x);
    ft_printf("CURRENT POS ME:\nX:%d\nY:%d\n", map->pos_me_x, map->pos_me_y);
    ft_printf("CURRENT POS EN:\nX:%d\nY:%d\n", map->pos_en_x, map->pos_en_y);
	ft_printf("********* CURRENT PIECE: *********\n");
	i = 0;
    while (i < piece->size_y)
    {
        ft_printf("%d %s\n", i, piece->piece[i]);
        i++;
    }
	ft_printf("PIECE SIZE:\nY: %d\nX: %d\n", piece->size_y, piece->size_x);
}

int							main(int argc, char **argv)
{
	t_map	*map;
	t_piece	*piece;
	int		fd; // only for testing purposes

	argc += argc; // only for testing purposes 
	fd = open(argv[1], O_RDONLY); // only for testing purposes
	if (!(map = malloc(sizeof(t_map))))
		return (0);
	if (!(piece = malloc(sizeof(t_piece))))
		return (0);
	initiate_struct(map, piece);
	fetch_player(map, fd);
	// while (1)
	// {
		input_scan(map, piece, fd);
	// }
	test_printing(map, piece);
	free (map);
	free (piece);
	free (piece->piece);
	return (0);
}
