/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retanaka <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 19:17:47 by retanaka          #+#    #+#             */
/*   Updated: 2024/08/12 19:17:49 by retanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_error	*create_error(t_mem *m, char *src)
{
	t_error	*err;

	append_mem(m, err = malloc(sizeof(t_error)));
	if (err)
		err->error_string = create_string(m, src);
	return (err);
}

void	print_error(t_error *err)
{
	if (!err)
		put("err is NULL.\n");
	else if (!err->error_string)
		put("errorStrint is NULL.\n");
	else
		put(err->error_string);
}
