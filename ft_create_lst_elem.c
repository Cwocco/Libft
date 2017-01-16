/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_lst_elem.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ada-cunh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/16 12:01:43 by ada-cunh          #+#    #+#             */
/*   Updated: 2017/01/16 13:25:33 by ada-cunh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

t2_list	*ft_create_lst_elem(void *data)
{
	t2_list *elem;

	elem = malloc(sizeof(t2_list));
	elem->next = NULL;
	elem->next = data;
	return (elem);
}
