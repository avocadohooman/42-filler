/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   placing_dispatcher.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmolin <gmolin@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 10:09:01 by gmolin            #+#    #+#             */
/*   Updated: 2020/02/10 10:34:39 by gmolin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

static int		hot(t_map *map, t_piece *p, t_heat *heat)
{
	if (ft_strcmp(heat->hot, "br") == 0)
		if (!(placing_br(map, p)))
			return (0);
	if (ft_strcmp(heat->hot, "bl") == 0)
		if (!(placing_bl(map, p)))
			return (0);
	if (ft_strcmp(heat->hot, "tr") == 0)
		if (!(placing_tr(map, p)))
			return (0);
	if (ft_strcmp(heat->hot, "tl") == 0)
		if (!(placing_tl(map, p)))
			return (0);
	return (1);
}

static int		warm(t_map *map, t_piece *p, t_heat *heat)
{
	if (ft_strcmp(heat->warm, "br") == 0)
		if (!(placing_br(map, p)))
			return (0);
	if (ft_strcmp(heat->warm, "bl") == 0)
		if (!(placing_bl(map, p)))
			return (0);
	if (ft_strcmp(heat->warm, "tr") == 0)
		if (!(placing_tr(map, p)))
			return (0);
	if (ft_strcmp(heat->warm, "tl") == 0)
		if (!(placing_tl(map, p)))
			return (0);
	return (1);
}

static int		luke_warm(t_map *map, t_piece *p, t_heat *heat)
{
	if (ft_strcmp(heat->luke_warm, "br") == 0)
		if (!(placing_br(map, p)))
			return (0);
	if (ft_strcmp(heat->luke_warm, "bl") == 0)
		if (!(placing_bl(map, p)))
			return (0);
	if (ft_strcmp(heat->luke_warm, "tr") == 0)
		if (!(placing_tr(map, p)))
			return (0);
	if (ft_strcmp(heat->luke_warm, "tl") == 0)
		if (!(placing_tl(map, p)))
			return (0);
	return (1);
}

static int		cold(t_map *map, t_piece *p, t_heat *heat)
{
	if (ft_strcmp(heat->cold, "br") == 0)
		if (!(placing_br(map, p)))
			return (0);
	if (ft_strcmp(heat->cold, "bl") == 0)
		if (!(placing_bl(map, p)))
			return (0);
	if (ft_strcmp(heat->cold, "tr") == 0)
		if (!(placing_tr(map, p)))
			return (0);
	if (ft_strcmp(heat->cold, "tl") == 0)
		if (!(placing_tl(map, p)))
			return (0);
	return (1);
}

int				placing_dispatcher(t_map *map, t_piece *p, t_heat *heat)
{
	if (!hot(map, p, heat))
		if (!warm(map, p, heat))
			if (!luke_warm(map, p, heat))
				if (!cold(map, p, heat))
					return (0);
	return (1);
}
