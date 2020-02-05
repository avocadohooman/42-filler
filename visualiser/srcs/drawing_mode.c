/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing_mode.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmolin <gmolin@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 14:28:22 by gmolin            #+#    #+#             */
/*   Updated: 2020/02/05 17:53:33 by gmolin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/visualiser.h"

void		draw_background(t_env *p)
{
	int		i;

	i = 0;
	while (i < (HEIGHT * WIDTH * 4))
	{
		(p->ret)[i] = 52;
		(p->ret)[i + 1] = 52;
		(p->ret)[i + 2] = 52;
		(p->ret)[i + 3] = 0;
		i += 4;
	}
}

void		draw_menu(t_env *p)
{
	int		width;

	width = WIDTH;
	p->red = 35;
	p->green = 35;
	p->blue = 35;
	draw_square(WIDTH / 2, 0, WIDTH / 2, p);
	p->red = 25;
	p->green = 25;
	p->blue = 25;
	p->width = 10;
	p->height = HEIGHT;
	draw_rectangle(WIDTH / 2, 0, p);
	draw_rectangle(WIDTH - p->width, 0, p);
	p->width = WIDTH;
	p->height = 50;
	draw_rectangle(0, 0, p);
	draw_rectangle(0, HEIGHT - p->height, p);
	p->width = WIDTH / 2;
	p->height = HEIGHT;
	draw_rectangle(0, 0, p);
}

void		draw_score(t_env *p)
{
	char	*str;

	calc_score(p);
	modif_color(56, 60, 150, p);
	p->width = WIDTH / 3;
	p->height = 20;
	draw_rectangle((WIDTH / 2) + 120, (HEIGHT / 3) + 40, p);
	modif_color(60, 76, 232, p);
	p->width = ((WIDTH / 3) * (p->scorep1 / (p->map_size_x * p->map_size_y)));
	p->height = 20;
	draw_rectangle((WIDTH / 2) + 120, (HEIGHT / 3) + 40, p);
	modif_color(180, 132, 52, p);
	p->width = WIDTH / 3;
	p->height = 20;
	draw_rectangle((WIDTH / 2) + 120, (HEIGHT / 2) + 170, p);
	modif_color(211, 151, 53, p);
	p->width = ((WIDTH / 3) * (p->scorep2 / (p->map_size_x * p->map_size_y)));
	p->height = 20;
	draw_rectangle((WIDTH / 2) + 120, (HEIGHT / 2) + 170, p);
}

void		draw_map(t_env *p)
{
	int		i;
	int		i2;
	int		s;

	s = ((WIDTH / 2) / (p->map_size_x)) - 2;
	i = -1;
	while (++i < p->map_size_y)
	{
		i2 = -1;
		while (++i2 < p->map_size_x)
		{
			if (p->map[i][i2] == '.' && is_aly_adj(p, i, i2) == 2)
				modif_color(50, 50, 50, p);
			else if (p->map[i][i2] == '.' && is_aly_adj(p, i, i2) == 1)
				modif_color(42, 42, 42, p);
			else if (p->map[i][i2] == '.')
				modif_color(55, 55, 55, p);
			else if (p->map[i][i2] == 'X' || p->map[i][i2] == 'x')
				modif_color(60, 76, 232, p);
			else if (p->map[i][i2] == 'O' || p->map[i][i2] == 'o')
				modif_color(211, 151, 53, p);
			draw_square((i2 * s) + (i2 * 2) + 2, (i * s) + (i * 2) +
				((600 - (p->map_size_y * s) - (p->map_size_y * 2)) / 2), s, p);
		}
	}
}

void		draw_mode(t_env *p)
{
	draw_background(p);
	draw_menu(p);
	draw_score(p);
	draw_map(p);
}
