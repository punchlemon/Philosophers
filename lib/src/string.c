/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retanaka <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 18:16:48 by retanaka          #+#    #+#             */
/*   Updated: 2024/08/12 18:16:50 by retanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_string	*create_string(t_mem *m, char *src)
{
	t_string	*s;

	append_mem(m, s = malloc(sizeof(t_string)));
	if (!s)
		return (s);
	s->len = str_len(src);
	if (!s->len)
		return (s->addr = NULL, s);
	append_mem(m, s->addr = malloc(sizeof(char) * s->len));
	copy_bytes(s->addr, src, s->len);
	return (s);
}

void	print_string(t_string *str)
{
	if (!str)
		put("str is NULL.\n");
	else if (!str->addr)
		put(str->addr);
	else
		write(1, str->addr, str->len);
}

int	compare_string(t_string *a, t_string *b)
{
	if (a->len > b->len)
		return (1);
	else if (a->len < b->len)
		return (-1);
	else
		return (compare_bytes(a, b, a->len));
}
