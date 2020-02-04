/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_2dstrndup.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmolin <gmolin@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 15:03:42 by gmolin            #+#    #+#             */
/*   Updated: 2020/02/04 17:30:06 by gmolin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			**ft_2dstrdup(char **str)
{
	int		k;
	int		i;
	int 	j;
	char	**new;

	k = 0;
	while (str[k] != NULL)
		k++;
	if (!(new = (char**)malloc(sizeof(char*) * k + 1)))
		return (NULL);
	k = 0;
	while(str[k] != NULL)
	{
		j = 0;
		i = 0;
		new[k] = (char*)malloc(sizeof(char) * ft_strlen(str[k]) + 1);
		while (str[k][j])
			new[k][i++] = str[k][j++];
		new[k][i] = '\0';
		k++;
	}
	new[k] = NULL;
	return (new);
}
