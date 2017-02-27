/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   del_2dtab.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ada-cunh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/27 05:31:51 by ada-cunh          #+#    #+#             */
/*   Updated: 2017/02/27 05:38:54 by ada-cunh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void		del_2dtab(void *content, size_t content_size)
{
	char	**tmp;
	int		i;

	i = 0;
	tmp = (char **)content;
	content_size++;
	while (tmp[i])
	{
		free(tmp[i]);
		i++;
	}
	free(tmp);
}
