/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_2dstrndup.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmolin <gmolin@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 15:03:42 by gmolin            #+#    #+#             */
/*   Updated: 2020/01/24 16:39:13 by gmolin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			**ft_2dstrndup(char **str, int n, int row, int len)
{
	int		i;
	int		j;
	int		k;
	char	**new;

	i = 0;
	k = 0;
	if (!(new = (char**)malloc(sizeof(char*) * row + 1)))
		return (NULL);
	while(str[n])
	{
		j = 0;
		i = 0;
		new[k] = (char*)malloc(sizeof(char) * len + 1);
		while (str[n][i])
			new[k][j++] = str[n][i++];
		new[k][j] = '\0';
		k++;
		n++;
	}
	new[k] = NULL;
	return (new);
}
