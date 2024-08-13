/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compare.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retanaka <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 16:02:07 by retanaka          #+#    #+#             */
/*   Updated: 2024/08/13 16:02:09 by retanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	copy_bytes(void *dst, void *src, size_t bytes)
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

int	compare_n_1byte(int8_t *a, int8_t *b, size_t n)
{
	while (n--)
	{
		if (*a != *b)
			return (((*a > *b) << 1) - 1);
	}
	return (0);
}

int	compare_bytes(void *a, void *b, size_t bytes)
{
	size_t	n8;
	size_t	n4;
	size_t	n1;

	n8 = bytes >> 3;
	n4 = bytes & 0b100;
	n1 = bytes & 0b11;
	while (n8--)
	{
		if ((uint64_t *)a != (uint64_t *)b)
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
	return (compare_n_1byte((int8_t *)a, (int8_t *)b, n1));
}
