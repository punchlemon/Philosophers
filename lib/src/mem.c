/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mem.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retanaka <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 18:40:31 by retanaka          #+#    #+#             */
/*   Updated: 2024/08/12 18:40:32 by retanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_mem	*create_mem(void)
{
	t_mem	*res;

	res = malloc(sizeof(t_mem));
	if (!res)
		return (NULL);
	res->addr = NULL;
	res->next = res;
	res->prev = res;
	return (res);
}

void	delete_mem(t_mem *sep)
{
	t_mem	*m;
	t_mem	*tmp;

	if (!sep)
		return ;
	m = sep->next;
	while (m != sep)
	{
		if (!m)
			break ;
		tmp = m->next;
		if (m->addr)
			free(m->addr);
		free(m);
		m = tmp;
	}
	free(sep);
}

void	append_mem(t_mem *sep, void *item)
{
	t_mem	*new;

	if (!sep)
		return ((void)put("sep is NULL."));
	new = malloc(sizeof(t_mem));
	if (!new)
		return ((void)put("Can't allocate memory."));
	new->addr = item;
	new->prev = sep->prev;
	new->next = sep;
	sep->prev->next = new;
	sep->prev = new;
}
