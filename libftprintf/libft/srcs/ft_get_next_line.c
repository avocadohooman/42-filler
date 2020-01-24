/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_next_line.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmolin <gmolin@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/31 12:34:44 by gmolin            #+#    #+#             */
/*   Updated: 2020/01/23 16:56:17 by gmolin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_trim_static_pos(char **pos, char **line, const int fd)
{
	char	*tmp;
	int		i;

	i = 0;
	while (pos[fd][i] != '\n' && pos[fd][i] != '\0')
		i++;
	if (pos[fd][i] == '\n')
	{
		*line = ft_strsub(pos[fd], 0, i);
		tmp = ft_strdup(pos[fd] + i + 1);
		free(pos[fd]);
		pos[fd] = tmp;
		if (pos[fd][0] == '\0')
			ft_strdel(&pos[fd]);
	}
	else if (pos[fd][i] == '\0')
	{
		*line = ft_strsub(pos[fd], 0, i);
		ft_strdel(&pos[fd]);
	}
	return (1);
}

int				ft_get_next_line(const int fd, char **line)
{
	char			buf[BUFF_SIZE + 1];
	int				bytes;
	char			*tmp;
	static char		*pos[FD_MAX];

	if (fd < 0 || !line)
		return (-1);
	while ((bytes = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[bytes] = '\0';
		if (!pos[fd])
			if (!(pos[fd] = ft_strnew(0)))
				return (-1);
		if (!(tmp = ft_strjoin(pos[fd], buf)))
			return (-1);
		free(pos[fd]);
		pos[fd] = tmp;
		if (ft_strchr(buf, '\n') > 0)
			break ;
	}
	if (bytes < 0)
		return (-1);
	if (bytes == 0 && (pos[fd] == NULL || pos[fd][0] == '\0'))
		return (0);
	return (ft_trim_static_pos(pos, line, fd));
}
