/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retanaka <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 15:39:42 by retanaka          #+#    #+#             */
/*   Updated: 2024/08/10 15:39:43 by retanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>
# include <stdint.h>
# define RUNE int32_t

typedef struct s_string
{
	char			*addr;
	size_t			len;
}	t_string;

typedef struct s_string_slice
{
	t_string		*strings;
	size_t			len;
	size_t			cap;
}	t_string_slice;

typedef struct s_rune_slice
{
	RUNE			*runes;
	size_t			len;
	size_t			cap;
}	t_rune_slice;

typedef struct s_error
{
	t_string		*error_string;
}	t_error;

typedef struct s_mem
{
	void			*addr;
	struct s_mem	*next;
	struct s_mem	*prev;
}	t_mem;

// typedef struct s_string_err
// {
// 	t_string		*string;
// 	t_error			*err;
// }	t_string_err;

// bytes function
void		copy_bytes(void *dst, void *src, size_t bytes);
int			compare_bytes(void *a, void *b, size_t bytes);

// error function
t_error		*create_error(t_mem *m, char *src);
void		print_error(t_error *err);

// mem function
t_mem		*create_mem(void);
void		delete_mem(t_mem *sep);
void		append_mem(t_mem *sep, void *item);

// num function
t_string	*ft_atoi(t_mem *m, int64_t num);

// put function
size_t		str_len(char *src);
int			put_fd(int fd, char *src);
int			put(char *src);
int			put_num(int64_t num);

// string function
t_string	*create_string(t_mem *m, char *src);
void		print_string(t_string *str);
int			compare_string(t_string *a, t_string *b);

#endif
