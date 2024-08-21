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

void	test_put_num(t_mem *m, char *str)
{
	t_result	res;

	print_string(ft_itoa(m, ft_atoi(create_string(ir(&res), m, str)->v)));
	put("\n");
}

int	main(void)
{
	t_mem		*m;

	m = create_mem();
	if (!m)
		return (put("Can't allocate memory!\n"), 1);
	test_put_num(m, "9223372036854775807");
	test_put_num(m, "9223372036854775808");
	test_put_num(m, "-9223372036854775808");
	test_put_num(m, "-9223372036854775809");
	test_put_num(m, "42");
	test_put_num(m, "-42");
	test_put_num(m, "0");
	test_put_num(m, "0a");
	test_put_num(m, "2a");
	test_put_num(m, "03");
	test_put_num(m, "+03");
	test_put_num(m, "+3");
	delete_mem(m);
	return (0);
}
