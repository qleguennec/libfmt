/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fmt_fmt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-guen <qle-guen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/23 02:51:31 by qle-guen          #+#    #+#             */
/*   Updated: 2017/05/29 02:50:17 by qle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libfmt.h"

static void
	fmt
	(t_vect *a
	, char **d
	, size_t *n
	, va_list l)
{
	t_vect	*v;
	char	*s;

	if (**d == '-' || ft_isdigit(**d))
		return (fmt_int(a, d, n, l));
	else if (**d == 'a')
		fmt_int_sign_32(a, 10, va_arg(l, int));
	else if (**d == 'b')
		fmt_int_sign_64(a, 10, va_arg(l, long));
	else if (**d == 'd')
		fmt_int_unsign(a, 10, va_arg(l, unsigned long));
	else if (**d == 'c')
		vect_mset_end(a, va_arg(l, int), 1);
	if (**d == 's')
	{
		s = va_arg(l, char *);
		vect_add(a, s, ft_strlen(s));
	}
	else if (**d == 'v')
	{
		v = va_arg(l, t_vect *);
		vect_add(a, v->data, v->used);
	}
	(*d)++;
	(*n)--;
}

static void
	fmt_arr
	(t_vect *a
	, char **d
	, size_t *n
	, va_list l)
{
	size_t	arr_len;
	void	*arr;

	arr_len = va_arg(l, size_t);
	arr = va_arg(l, void *);
	vect_add(a, "{", 1);
	while (arr_len)
	{
		if (**d == 'a')
		{
			fmt_int_sign_32(a, 10, *(int *)arr);
			arr += sizeof(int);
		}
		arr_len--;
		if (arr_len)
			vect_add(a, ", ", 2);
	}
	vect_add(a, "}", 1);
	(*d)++;
	(*n)--;
}

void
	fmt_fmt
	(t_vect *a
	, char *s
	, size_t n
	, va_list l)
{
	char	*d;

	if (!((d = ft_memchr(s, '%', n))
		|| (d = ft_memchr(s, '*', n))))
	{
		vect_add(a, s, n);
		return ;
	}
	vect_add(a, s, d - s);
	n -= d - s;
	d++;
	n--;
	if (*(d - 1) == '%')
		fmt(a, &d, &n, l);
	else if (*(d - 1) == '*')
		fmt_arr(a, &d, &n, l);
	fmt_fmt(a, d, n, l);
}
