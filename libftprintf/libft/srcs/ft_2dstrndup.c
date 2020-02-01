/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_2dstrndup.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmolin <gmolin@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 15:03:42 by gmolin            #+#    #+#             */
/*   Updated: 2020/02/01 17:15:42 by gmolin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			**ft_2dstrdup(char **str)
{
	int		k;
	char	**new;

	k = 0;
	while (str[k] != NULL)
		k++;
	if (!(new = (char**)malloc(sizeof(char*) * k + 1)))
		return (NULL);
	k = 0;
	while(str[k] != NULL)
	{
		new[k] = ft_strdup(str[k]); 
		k++;
	}
	new[k] = NULL;
	return (new);
}
