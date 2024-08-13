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

int	main(void)
{
	t_mem		*m;
	t_string	*s1;
	t_string	*s2;

	m = create_mem();
	if (!m)
		return (put("Can't allocate memory!\n"), 1);
	s1 = create_string(m, "hello");
	s2 = create_string(m, "hella");
	if (compare_string(s1, s2) == 0)
		put("same!\n");
	else if (compare_string(s1, s2) == 1)
	{
		print_string(s1);
		put(" is bigger than ");
		print_string(s2);
		put(".\n");
	}
	else
	{
		print_string(s2);
		put(" is bigger than ");
		print_string(s1);
		put(".\n");
	}
	delete_mem(m);
	return (0);
}
