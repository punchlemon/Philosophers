/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retanaka <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 18:53:41 by retanaka          #+#    #+#             */
/*   Updated: 2024/08/12 18:53:43 by retanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	str_len(char *src)
{
	size_t	len;

	if (!src)
		return (0);
	len = -1;
	while (src[++len])
		;
	return (len);
}

int	put(char *src)
{
	if (!src)
		return (write(1, "(null)\n", 7));
	return (write(1, src, str_len(src)));
}
