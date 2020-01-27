/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_2dstrndup.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmolin <gmolin@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 15:03:42 by gmolin            #+#    #+#             */
/*   Updated: 2020/01/27 14:21:19 by gmolin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			**ft_2dstrdup(char **str)
{
	int		i;
	int		j;
	int		k;
	char	**new;

	i = 0;
	k = 0;
	while (str[k])
		k++;
	if (!(new = (char**)malloc(sizeof(char*) * k + 1)))
		return (NULL);
	k = 0;
	while(str[k])
	{
		j = 0;
		i = 0;
		new[k] = (char*)malloc(sizeof(char) * ft_strlen(str[k]) + 1);
		while (str[k][i])
			new[k][j++] = str[k][i++];
		new[k][j] = '\0';
		k++;
	}
	new[k] = NULL;
	return (new);
}
