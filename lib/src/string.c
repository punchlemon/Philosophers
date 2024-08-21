/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retanaka <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 18:16:48 by retanaka          #+#    #+#             */
/*   Updated: 2024/08/12 18:16:50 by retanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_result	*create_string(t_result *res, t_mem *m, char *src)
{
	t_string	*s;

	if (res->status == ERR)
		return (res);
	append_mem(m, s = malloc(sizeof(t_string)));
	if (!s)
		return (make_error(res, m, "create_string failed to allocate memory1."));
	s->len = ft_strlen(src);
	if (!s->len)
		return (s->addr = NULL, res->v = s, res);
	append_mem(m, s->addr = malloc(sizeof(char) * s->len));
	if (!s->addr)
		return (make_error(res, m, "create_string failed to allocate memory2."));
	copy_bytes(s->addr, src, s->len);
	res->v = s;
	return (res);
}

void	print_string(t_string *str)
{
	int	tmp;

	if (!str)
		tmp = put("str is NULL.\n");
	else if (!str->addr)
		tmp = put(str->addr);
	else
		tmp = write(1, str->addr, str->len);
	if (tmp == -1)
		put("print_string failed to write console string.\n");
}

t_result	*append_string(t_result *res, t_mem *m, t_string *a, t_string *b)
{
	char	*tmp;

	if (!a || !b || !b->len || res->status == ERR)
		return (res->v = a, res);
	append_mem (m, tmp = malloc(sizeof(char) * (a->len + b->len)));
	if (!tmp)
		make_error(res, m, " add_string failed to allocate memory.");
	if (!a->len)
		copy_bytes(tmp, a->addr, a->len);
	copy_bytes(tmp + a->len, b->addr, b->len);
	a->addr = tmp;
	return (res->v = a, res);
}

t_result	*add_string(t_result *res, t_mem *m, t_string *a, char *src)
{
	size_t	src_len;
	char	*tmp;

	src_len = ft_strlen(src);
	if (!a || !src_len || res->status == ERR)
		return (res->v = a, res);
	append_mem (m, tmp = malloc(sizeof(char) * (a->len + src_len)));
	if (!tmp)
		make_error(res, m, " add_string failed to allocate memory.");
	if (!a->len)
		copy_bytes(tmp, a->addr, a->len);
	copy_bytes(tmp + a->len, src, src_len);
	a->addr = tmp;
	return (res->v = a, res);
}

int	compare_string(t_string *a, t_string *b)
{
	if (a->len > b->len)
		return (1);
	else if (a->len < b->len)
		return (-1);
	else
		return (compare_bytes(a->addr, b->addr, a->len));
}
// compare_string is no gard!!!
