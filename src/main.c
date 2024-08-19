/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retanaka <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 18:18:24 by retanaka          #+#    #+#             */
/*   Updated: 2024/08/12 18:18:26 by retanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Philosophers.h"

void	test_put_num(t_mem *m, int64_t num)
{
	print_string(ft_atoi(m, num));
	put("\n");
}

int	main(void)
{
	t_mem		*m;

	m = create_mem();
	if (!m)
		return (put("Can't allocate memory!\n"), 1);
	test_put_num(m, INT64_MAX);
	test_put_num(m, INT64_MIN);
	test_put_num(m, 42);
	test_put_num(m, -42);
	test_put_num(m, 0);
	delete_mem(m);
	return (0);
}
