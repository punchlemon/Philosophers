/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retanaka <retanaka@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 01:10:41 by retanaka          #+#    #+#             */
/*   Updated: 2024/08/20 01:10:42 by retanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int64_t	ft_atoi(t_string str)
{
	int64_t	res;
	char	c;
	size_t	i;

	if (str.len > 20 || str.len == 0)
		return (0);
	if (str.len == 20 && !compare_bytes(str.addr, INTMIN_ADDR, 20))
		return (INT64_MIN);
	res = 0;
	i = -1;
	if (*str.addr == '+' || *str.addr == '-')
		i++;
	if (*(str.addr + i + 1) == '0')
		return (0);
	while (++i < str.len)
	{
		c = *(str.addr + i);
		if (res > INT64_MAX_10 || (res == INT64_MAX_10 && c > '7'))
			return (0);
		if (c < '0' || c > '9')
			return (0);
		res *= 10;
		res += c - '0';
	}
	return (((*str.addr != '-') * 2 - 1) * res);
}
