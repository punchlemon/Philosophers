/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retanaka <retanaka@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 01:10:49 by retanaka          #+#    #+#             */
/*   Updated: 2024/08/20 01:10:50 by retanaka         ###   ########.fr       */
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
		return (copy_bytes(addr, INTMIN_ADDR, 20));
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
	t_string	*str;
	t_result	res;

	str = create_string(ir(&res), m, NULL)->v;
	str->len = num_len(num);
	append_mem(m, str->addr = malloc(sizeof(char) * str->len));
	if (!str->addr)
		return (str->len = 0, str);
	copy_num(str->addr, num, str->len);
	return (str);
}
