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
#include <stdint.h>

void	mem_cpy(void *dst, void *src, size_t len)
{
	size_t	n8;
	size_t	n4;
	size_t	n1;

	n8 = len >> 3;
	n4 = (len & 0b100) >> 2;
	n1 = len & 0b11;
	while (n8--)
	{
		*(uint64_t *)dst = *(uint64_t *)src;
		dst += 8;
		src += 8;
	}
	while (n4--)
	{
		*(uint32_t *)dst = *(uint32_t *)src;
		dst += 4;
		src += 4;
	}
	while (n1--)
		*(uint8_t *)dst++ = *(uint8_t *)src++;
}

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
	mem_cpy(s->addr, src, s->len);
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
