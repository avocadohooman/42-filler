/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   placing_dispatcher.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmolin <gmolin@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 10:09:01 by gmolin            #+#    #+#             */
/*   Updated: 2020/02/05 12:21:43 by gmolin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

int static				hot(t_map *map, t_piece *piece, t_heat *heat)
{
	if (ft_strcmp(heat->hot, "br") == 0)
		if (!(placing_br(map, piece)))
			return (0);
	if (ft_strcmp(heat->hot, "bl") == 0)
		if (!(placing_bl(map, piece)))
			return (0);
	if (ft_strcmp(heat->hot, "tr") == 0)
		if (!(placing_tr(map, piece)))
			return (0);
	if (ft_strcmp(heat->hot, "tl") == 0)
		if (!(placing_tl(map, piece)))
			return (0);
	return (1);
}

int static				warm(t_map *map, t_piece *piece, t_heat *heat)
{
	if (ft_strcmp(heat->warm, "br") == 0)
		if (!(placing_br(map, piece)))
			return (0);
	if (ft_strcmp(heat->warm, "bl") == 0)
		if (!(placing_bl(map, piece)))
			return (0);
	if (ft_strcmp(heat->warm, "tr") == 0)
		if (!(placing_tr(map, piece)))
			return (0);
	if (ft_strcmp(heat->warm, "tl") == 0)
		if (!(placing_tl(map, piece)))
			return (0);
	return (1);
}

int static				luke_warm(t_map *map, t_piece *piece, t_heat *heat)
{
	if (ft_strcmp(heat->luke_warm, "br") == 0)
		if (!(placing_br(map, piece)))
			return (0);
	if (ft_strcmp(heat->luke_warm, "bl") == 0)
		if (!(placing_bl(map, piece)))
			return (0);
	if (ft_strcmp(heat->luke_warm, "tr") == 0)
		if (!(placing_tr(map, piece)))
			return (0);
	if (ft_strcmp(heat->luke_warm, "tl") == 0)
		if (!(placing_tl(map, piece)))
			return (0);
	return (1);
}

int static				cold(t_map *map, t_piece *piece, t_heat *heat)
{
	if (ft_strcmp(heat->cold, "br") == 0)
		if (!(placing_br(map, piece)))
			return (0);
	if (ft_strcmp(heat->cold, "bl") == 0)
		if (!(placing_bl(map, piece)))
			return (0);
	if (ft_strcmp(heat->cold, "tr") == 0)
		if (!(placing_tr(map, piece)))
			return (0);
	if (ft_strcmp(heat->cold, "tl") == 0)
		if (!(placing_tl(map, piece)))
			return (0);
	return (1);
}

int						placing_dispatcher(t_map *map, t_piece *piece, t_heat *heat)
{
	if (!hot(map, piece, heat))
		if (!warm(map, piece, heat))
			if (!luke_warm(map, piece, heat))
				if(!cold(map, piece, heat))
					return (0);
	return (1);
}
