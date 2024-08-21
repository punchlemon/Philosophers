/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   result.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retanaka <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 15:19:34 by retanaka          #+#    #+#             */
/*   Updated: 2024/08/21 15:19:35 by retanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_result	*ir(t_result *res)
{
	res->status = OK;
	res->v = NULL;
	res->err_str = NULL;
	return (res);
}

t_result	*make_error(t_result *res, t_mem *m, char *err_src)
{
	t_string	*err_str;

	res->status = ERR;
	res->v = 0;
	err_str = create_string(res, m, err_src)->v;
	if (!err_str)
		return (put("make_error failed to create string.\n"), res);
	err_str = append_string(res, m, err_str, res->err_str)->v;
	if (!err_str)
		return (put("make_error failed to add string.\n"), res);
	res->err_str = err_str;
	return (res);
}

