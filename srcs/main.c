/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmolin <gmolin@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 15:57:47 by gmolin            #+#    #+#             */
/*   Updated: 2020/01/28 16:53:19 by gmolin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

static void					initiate_struct_map(t_map *map)
{
	map->board = NULL;
	map->board_backup = NULL;
	map->p_name = NULL;
	map->token_me = NULL;
	map->token_en = NULL;
	map->heat = NULL;
	map->player = 0;
	map->pos_me_x = 0;
	map->pos_me_y = 0;
	map->pos_en_x = 0;
	map->pos_en_x = 0;
	map->size_x = 0;
	map->size_y = 0;
	map->check_sum = 0;
}

static void					initiate_struct_piece(t_piece *piece)
{
	piece->piece = NULL;
	piece->size_x = 0;
	piece->size_y = 0;
	piece->check_sum = 0;
	piece->distance_x = 0;
	piece->distance_y = 0;
	piece->final_x = 0;
	piece->final_y = 0;
}

static	void				fetch_player(t_map *map, int fd)
{
	char	*line;

	ft_get_next_line(fd, &line);
	if (line[10] != '1' || !line)
		ft_printf("error: bad player info\n");
	if (ft_strstr(line, "gmolin.filler"))
	{
		map->player = 1;
		map->token_me = "oO";
		map->token_en = "xX";
	}
	else
	{
		map->player = 2;
		map->token_me = "xX";
		map->token_en = "oO";
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
	ft_printf("AMOUNT OF TOKENS:\n%d\n", map->check_sum);	
	ft_printf("********* GAME STATS: *********\n");
	ft_printf("PLAYER: %d\n", map->player);
	ft_printf("TOKENS: %s\n", map->token_me);
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
	ft_printf("AMOUNT OF PIECE BLOCKS:\n%d\n", piece->check_sum);	
	ft_printf("PIECE REAL STARTING POS:\nX %d\nY %d\n", piece->distance_x, piece->distance_y);
	ft_printf("********* PIECE PLACED: *********\n");
	i = 0;
	while (i < map->size_y)
    {
        ft_printf("%2d %s\n", i, map->board[i]);
        i++;
    }
	ft_printf("********* RETURN VALUE: *********\n");
	ft_printf("RETURN VALUE:\nY %d\nX %d\n", piece->final_y, piece->final_x);
}


int						main(int argc, char **argv)
// int							main(void)
{
	t_map	*map;
	t_piece	*piece;
	int		fd; // only for testing purposes

	argc += argc; // only for testing purposes 
	fd = open(argv[1], O_RDONLY); // only for testing purposes
	// fd = 0;
	if (!(map = malloc(sizeof(t_map))))
		return (0);
	if (!(piece = malloc(sizeof(t_piece))))
		return (0);
	initiate_struct_map(map);
	initiate_struct_piece(piece);
	fetch_player(map, fd);
	// while (1)
	// {
		input_scan(map, piece, fd);
		placing_mode(map, piece, 0, 0);
		return_coordinates(map, piece);
		print_result(piece, map);
		//exit(1);
	// }
	test_printing(map, piece);
	free (map);
	free (piece);
	free (piece->piece);
	return (0);
}
