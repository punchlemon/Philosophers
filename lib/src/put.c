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

int	put_fd(int fd, char *src)
{
	if (!src)
		return (write(fd, "(null)\n", 7));
	return (write(fd, src, str_len(src)));
}

int	put(char *src)
{
	return (put_fd(1, src));
}

int	put_num(int64_t num)
{
	char	buffer[20];
	char	*ptr;
	int		is_negative;

	if (num == INT64_MIN)
		return (write(1, INTMIN_ADDR, 20));
	ptr = buffer + 20;
	is_negative = num < 0;
	if (is_negative)
		num = -num;
	while (1)
	{
		*(--ptr) = '0' + (num % 10);
		num /= 10;
		if (num == 0)
			break ;
	}
	if (is_negative)
		*(--ptr) = '-';
	return (write(1, ptr, buffer + 20 - ptr));
}
