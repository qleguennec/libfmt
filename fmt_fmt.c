/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fmt_fmt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-guen <qle-guen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/23 02:51:31 by qle-guen          #+#    #+#             */
/*   Updated: 2017/01/09 16:04:15 by qle-guen         ###   ########.fr       */
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

	if (**d == '-' || ft_isdigit(**d))
		return (fmt_int(a, d, n, l));
	else if (**d == 'a')
		fmt_int_sign_32(a, 10, va_arg(l, t_i32));
	else if (**d == 'b')
		fmt_int_sign_64(a, 10, va_arg(l, t_i32));
	else if (**d == 'c' || **d == 'd')
		fmt_int_unsign(a, 10, va_arg(l, t_i32));
	else if (**d == '%')
		vect_mset_end(a, '%', 1);
	if (**d == 's')
		vect_str_add(a, va_arg(l, char *));
	else if (**d == 'v')
	{
		v = va_arg(l, t_vect *);
		vect_add(a, v->data, v->used);
	}
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

	d = ft_memchr(s, '%', n);
	if (!d)
	{
		vect_add(a, s, n);
		return ;
	}
	vect_add(a, s, d - s);
	n -= d - s;
	if (n < 2)
		return ;
	d++;
	n--;
	fmt(a, &d, &n, l);
	fmt_fmt(a, d, n, l);
}
