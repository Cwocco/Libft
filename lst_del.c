/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_del.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ada-cunh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/27 04:48:17 by ada-cunh          #+#    #+#             */
/*   Updated: 2017/02/27 04:52:16 by ada-cunh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void		*del_2dtab(void *content, size_t content_size)
{
	char	**tmp;
	int		i;

	i = 0;
	tmp = (char **)content;
	while (tmp[i])
	{
		free(tmp[i]);
		i++;
	}
	free(tmp);
}
