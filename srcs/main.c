/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmolin <gmolin@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 15:57:47 by gmolin            #+#    #+#             */
/*   Updated: 2020/02/05 15:37:46 by gmolin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

static	void				fetch_player(t_map *map, int fd)
{
	char	*line;

	ft_get_next_line(fd, &line);
	if (line[9] != 'p' || !line)
		ft_printf("error: bad player info\n");
	if (ft_strncmp(line, "$$$", 2) == 0 && map->player == 0)
	{
		if (ft_strstr(line, "p2"))
		{
			map->player = 2;
			map->token_me = "Xx";
			map->token_en = "Oo";
		}
		if (ft_strstr(line, "p1"))
		{
			map->player = 1;
			map->token_me = "Oo";
			map->token_en = "Xx";
		}
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


int							main(void)
{
	t_map	*map;
	t_piece	*piece;
	t_heat	*heat;
	int		fd;

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
				if (!(placing_all(map, piece, 0, 0)))
					exit(1);
		return_coordinates(map, piece);
		print_result(piece, map);
	} 
	return (0);
}
