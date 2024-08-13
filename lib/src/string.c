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

void	copy_mem(void *dst, void *src, size_t bytes)
{
	size_t	n8;
	size_t	n4;
	size_t	n1;

	n8 = bytes >> 3;
	n4 = bytes & 0b100;
	n1 = bytes & 0b11;
	while (n8--)
	{
		*(uint64_t *)dst = *(uint64_t *)src;
		dst += 8;
		src += 8;
	}
	if (n4)
	{
		*(uint32_t *)dst = *(uint32_t *)src;
		dst += 4;
		src += 4;
	}
	while (n1--)
		*(uint8_t *)dst++ = *(uint8_t *)src++;
}

int	compare_byte(int8_t a, int8_t b, size_t n)
{
	while (n--)
		if (a != b)
			return (((a > b) << 1) - 1);
	return (0);
}

int	compare_mem(void *a, void *b, size_t bytes)
{
	size_t	n8;
	size_t	n4;
	size_t	n1;

	n8 = bytes >> 3;
	n4 = bytes & 0b100;
	n1 = bytes & 0b11;
	while (n8--)
	{
		if (*(uint64_t *)a != *(uint64_t *)b)
			return (((*(uint64_t *)a > *(uint64_t *)b) << 1) - 1);
		a += 8;
		b += 8;
	}
	if (n4)
	{
		if (*(uint32_t *)a != *(uint32_t *)b)
			return (((*(uint32_t *)a > *(uint32_t *)b) << 1) - 1);
		a += 4;
		b += 4;
	}
	return (compare_byte(*(int8_t *)a, *(int8_t *)b, n1));
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
	copy_mem(s->addr, src, s->len);
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
		return (compare_mem(a, b, a->len));
}
