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
	t_string	*s;

	m = create_mem();
	if (!m)
		return (put("Can't allocate memory!\n"), 1);
	s = create_string(m, "");
	print_string(s);
	delete_mem(m);
	return (0);
}
