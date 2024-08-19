/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   num.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retanaka <retanaka@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 21:58:25 by retanaka          #+#    #+#             */
/*   Updated: 2024/08/19 21:58:26 by retanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	num_len(int64_t num)
{
	size_t	res;

	res = 0;
	res += num < 0;
	while (1)
	{
		res++;
		num /= 10;
		if (num == 0)
			return (res);
	}
}

void	copy_num(char *addr, int64_t num, size_t len)
{
	if (!addr || len > 20)
		return ;
	if (num == INT64_MIN)
		return (copy_bytes(addr, "-9223372036854775808", 20));
	if (num < 0)
	{
		*addr = '-';
		num = -num;
	}
	while (1)
	{
		*(addr + --len) = '0' + (num % 10);
		num /= 10;
		if (num == 0)
			return ;
	}
}

t_string	*ft_itoa(t_mem *m, int64_t num)
{
	t_string	*res;

	res = create_string(m, NULL);
	res->len = num_len(num);
	append_mem(m, res->addr = malloc(sizeof(char) * res->len));
	if (!res->addr)
		return (res->len = 0, res);
	copy_num(res->addr, num, res->len);
	return (res);
}
