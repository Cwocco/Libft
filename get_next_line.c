/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ada-cunh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/10 22:12:12 by ada-cunh          #+#    #+#             */
/*   Updated: 2017/02/24 23:32:10 by ada-cunh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"
#include "includes/get_next_line.h"
#include <stdlib.h>
#include <unistd.h>

static int			cut_save(char **save, char **line)
{
	char			*s_pos;

	if ((s_pos = ft_strchr(*save, (int)'\n')))
	{
		*line = ft_strsub(*save, 0, s_pos - *save);
		ft_memmove(*save, s_pos + 1, ft_strlen(s_pos));
		s_pos = NULL;
		return (1);
	}
	return (0);
}

static int			read_and_cut(int const fd, char **save, char **line)
{
	char			buf[BUFF_SIZE + 1];
	char			*tmp;
	int				ret;

	while ((ret = read(fd, buf, BUFF_SIZE)))
	{
		if (ret == -1)
			return (-1);
		buf[ret] = '\0';
		tmp = NULL;
		if (*save)
		{
			tmp = ft_strdup(*save);
			ft_strdel(*(&save));
			*save = ft_strjoin(tmp, buf);
			ft_strdel(&tmp);
		}
		else
			*save = ft_strdup(buf);
		if (cut_save(save, line))
			return (1);
	}
	return (0);
}

int					get_next_line(int const fd, char **line)
{
	static char		*save;
	int				ret;

	if (fd < 0 || BUFF_SIZE < 1 || !line)
		return (-1);
	if (save && cut_save(&save, line))
		return (1);
	if ((ret = read_and_cut(fd, &save, line)) != 0)
		return (ret);
	if (save == NULL || save[0] == '\0')
		return (0);
	*line = save;
	save = NULL;
	return (1);
}
