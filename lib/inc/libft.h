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
# define INTMIN_ADDR "-9223372036854775808"
# define INT64_MAX_10 922337203685477580
# define OK 0
# define ERR 1

typedef struct s_string
{
	char			*addr;
	size_t			len;
}	t_string;

typedef struct s_num_slice
{
	int64_t			*nums;
	size_t			len;
	size_t			cap;
}	t_num_slice;

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

typedef struct s_byte_slice
{
	int8_t			*bytes;
	size_t			len;
	size_t			cap;
}	t_byte_slice;

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

typedef struct s_result
{
	int			status;
	void		*v;
	t_string	*err_str;
}	t_result;

// typedef struct s_string_err
// {
// 	t_string		*string;
// 	t_error			*err;
// }	t_string_err;

// bytes function
void		copy_bytes(void *dst, void *src, size_t bytes);
int			compare_bytes(void *a, void *b, size_t bytes);

// error function
// t_error		*create_error(t_mem *m, char *src);
// void		print_error(t_error *err);

// ft_itoa function
int64_t		ft_atoi(t_string *str);

// ft_itoa function
t_string	*ft_itoa(t_mem *m, int64_t num);

// mem function
t_mem		*create_mem(void);
void		delete_mem(t_mem *sep);
void		append_mem(t_mem *sep, void *item);

// put function
size_t		ft_strlen(char *src);
int			put_fd(int fd, char *src);
int			put(char *src);
int			put_num(int64_t num);

// result function
t_result	*ir(t_result *res);
t_result	*make_error(t_result *res, t_mem *m, char *err_src);

// string function
t_result	*create_string(t_result *res, t_mem *m, char *src);
void		print_string(t_string *str);
t_result	*append_string(t_result *res, t_mem *m, t_string *a, t_string *b);
t_result	*add_string(t_result *res, t_mem *m, t_string *a, char *src);
int			compare_string(t_string *a, t_string *b);

#endif
