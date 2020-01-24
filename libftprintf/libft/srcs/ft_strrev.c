/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmolin <gmolin@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/06 15:27:57 by gmolin            #+#    #+#             */
/*   Updated: 2020/01/06 15:28:46 by gmolin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrev(char *str)
{
	char	*beg;
	char	*rev;
	char	*end;
	char	temp;

	beg = str;
	rev = str;
	end = str;
	while (*end)
		end++;
	end--;
	while (beg < end)
	{
		temp = *beg;
		*beg = *end;
		*end = temp;
		end--;
		beg++;
	}
	return (rev);
}
