/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy_bytes.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retanaka <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 16:02:07 by retanaka          #+#    #+#             */
/*   Updated: 2024/08/17 15:16:00 by retanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	copy_bytes(void *dst, void *src, size_t bytes)
{
	size_t	n64;

	n64 = bytes >> 3;
	while (n64--)
	{
		*(uint64_t *)dst = *(uint64_t *)src;
		dst += 8;
		src += 8;
	}
	if (bytes & 0b100)
	{
		*(uint32_t *)dst = *(uint32_t *)src;
		dst += 4;
		src += 4;
	}
	if (bytes & 0b10)
	{
		*(uint16_t *)dst = *(uint16_t *)src;
		dst += 2;
		src += 2;
	}
	if (bytes & 0b1)
		*(uint8_t *)dst = *(uint8_t *)src;
}
