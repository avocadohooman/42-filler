/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmolin <gmolin@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 15:57:47 by gmolin            #+#    #+#             */
/*   Updated: 2020/02/01 17:50:43 by gmolin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

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
			// ft_printf("Inside Plateau if\n");
			map_mode(map, line, fd);
			ft_strdel(&line);
		}
		else if (ft_strncmp("Piece", line, 4) == 0)
		{
			// ft_printf("Inside Piece if\n");
		 	piece_mode(piece, line, fd);
		 	return (1);
		}
		else
			ft_strdel(&line);
	}
	return (0);
}

void 	test_printing(t_map *map, t_piece *piece, t_heat *heat)
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
	ft_printf("PIECE SIZE:\nY: %d\nX: %d\n", piece->size_y, piece->size_x);
	ft_printf("AMOUNT OF PIECE BLOCKS:\n%d\n", piece->check_sum);	
	ft_printf("PIECE REAL STARTING POS:\nX %d\nY %d\n", piece->distance_x, piece->distance_y);
	ft_printf("********* TRIMMED PIECE: *********\n");
	ft_printf("Trim size x %d\nTrim size y %d\nPiece start x %d\nPiece start y %d\nPiece end x %d\nPiece end y %d\n", piece->trim_size_x, piece->trim_size_y, piece->start_x, piece->start_y, piece->trim_x, piece->trim_size_y);
	i = 0;
    while (piece->p_trimmed[i])
    {
        ft_printf("%d %s\n", i, piece->p_trimmed[i]);
        i++;
    }
	ft_printf("********* HEAT MAP: *********\n");
    ft_printf("Top left: %11d\n", heat->array[0]);
	ft_printf("Top right: %10d\n", heat->array[1]);
	ft_printf("Bottom left: %8d\n", heat->array[2]);
	ft_printf("Bottom right: %7d\n", heat->array[3]);
	ft_printf("HOT AREA: %s\n", heat->hot);
	ft_printf("WARM AREA: %s\n", heat->warm);
	ft_printf("LUKE WARM AREA: %s\n", heat->luke_warm);
	ft_printf("COLD AREA: %s\n", heat->cold);
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


// int						main(int argc, char **argv)
int							main(void)
{
	t_map	*map;
	t_piece	*piece;
	t_heat	*heat;
	int		fd; // only for testing purposes

	// argc += argc; // only for testing purposes 
	// fd = open(argv[1], O_RDONLY); // only for testing purposes
	fd = 0;
	if (!(map = (t_map*)malloc(sizeof(t_map))))
		return (0);
	if (!(heat = (t_heat*)malloc(sizeof(t_heat))))
		return (0);
	if (!(piece = (t_piece*)malloc(sizeof(t_piece))))
		return (0);
	initiate_structs(map, piece, heat);
	fetch_player(map, fd);
	while (1)
	{
		input_scan(map, piece, fd);
		strategy_mode(map, heat);
		if (!(placing_dispatcher(map, piece, heat)))
			{
				if (!(placing_all(map, piece, 0, 0)))
					exit(1);
			}
		// test_printing(map, piece, heat);
		return_coordinates(map, piece);
		print_result(piece, map);
	}	
	free (map);
	free (piece);
	return (0);
}
