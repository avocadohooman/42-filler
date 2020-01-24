/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmolin <gmolin@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 15:57:47 by gmolin            #+#    #+#             */
/*   Updated: 2020/01/24 17:26:45 by gmolin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

static void		initiate_setup(t_setup *setup)
{
	setup->board = NULL;
	setup->p_name = NULL;
	setup->token = 'X';
	setup->player = 2;
	setup->p1start_x = 0;
	setup->p1start_y = 0;
	setup->p2start_x = 0;
	setup->p2start_y = 0;
	setup->size_x = 0;
	setup->size_y = 0;
}

static	void		starting_pos(t_setup *setup, int i, int k, char token)
{

	while (setup->board[k])
	{
		i = 0;
		while (setup->board[k][i])
		{
			if (setup->board[k][i] == token)
			{
				if (token == 'O')
				{
					setup->p1start_x = i - 4;
					setup->p1start_y = k - 1;
				}
				else 
				{
					setup->p2start_x = i - 4;
					setup->p2start_y = k - 1;
				}
			}
			i++;
		}
		k++;
	}
}

static	void		fetch_setup(t_setup *setup, char *file)
{
	int		i;
	int 	k;

	k = 0;
	i = 0;
	setup->board = ft_strsplit(file, '\n');
	// ft_printf("P%c \n", setup->board[6][10]);
	// ft_printf("Name: %s\n", &setup->board[6][23]);
	if (ft_strcmp("gmolin.filler]", &setup->board[6][23]) == 0)
	{
		setup->player = 1;
		setup->token = 'O';
	}
	// ft_printf("Player number: %d\n", setup->player);
	// ft_printf("%s\n", &setup->board[9][8]);
	setup->size_x = ft_atoi(&setup->board[9][8]);
	i = 8 + ft_len(setup->size_x);
	setup->size_y = ft_atoi(&setup->board[9][i]);
	// ft_printf("Board size:\nX %d\nY %d\n", setup->size_x, setup->size_y);
	setup->board = ft_2dstrndup(setup->board, 10, setup->size_y + 1, setup->size_x + 4);
	// k = 0;
	// while(setup->board[k])
	// {
	// 	ft_printf("%s %d\n", setup->board[k], k);
	// 	k++;
	// }
	starting_pos(setup, 0, 0, setup->token);
	starting_pos(setup, 0, 0, 'X');
	// ft_printf("START POSITION:\nX: %d\nY: %d\n", setup->p1start_x, setup->p1start_y);
	// ft_printf("START POSITION:\nX: %d\nY: %d\n", setup->p2start_x, setup->p2start_y);
}

static char		*read_file(int fd)
{
	char		rline[BUFF_SIZE + 1];
	char		*file;
	char		*tmp;
	int			count;
	size_t		i;

	i = 0;
	if (!(file = ft_strnew(0)))
		return (NULL);
	while ((count = read(fd, rline, BUFF_SIZE)) > 0)
	{
		rline[count] = '\0';
		i += count;
		tmp = file;
		file = ft_strjoin(file, rline);
		free(tmp);
	}
	if (count < 0)
		return (NULL);
	return (file);
}

int				main(int argc, char **argv)
{
	int		fd;
	char	*file;
	t_setup *setup;
	int		k;

	k = 0;
	if (!(setup = malloc(sizeof(t_setup))))
		return (0);
	initiate_setup(setup);
	fd = open(argv[1], O_RDONLY);
	if (!(file = read_file(fd)))
		ft_printf("error\n");
	fetch_setup(setup, file);
	ft_strdel(&file);
	close(fd);
	free(setup);
	return (0);
}
