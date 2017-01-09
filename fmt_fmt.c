/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fmt_fmt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-guen <qle-guen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/23 02:51:31 by qle-guen          #+#    #+#             */
/*   Updated: 2017/01/09 00:02:56 by qle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libfmt.h"
#include <stdio.h>
#include <limits.h>

static void
	fmt_int_sign_64
	(t_vect *a
	, t_i32 base
	, t_i64 x)
{
	bool	neg;
	char	s[20];
	size_t	i;

	i = 19;
	neg = (x < 0);
	if (!x)
		return ((void)vect_mset_end(a, '0', 1));
	while ((x > 0 || x <= base) && ((x < 0) || (x >= base)))
	{
		s[i] = x % base;
		s[i] = ABS(s[i]);
		s[i] += (s[i] <= 9) ? '0' : 'a' - 10;
		x /= base;
		i--;
	}
	if (x)
		s[i--] = ABS(x) + (x <= 9 ? '0' : 'a' - 10);
	if (neg)
		s[i--] = '-';
	i++;
	vect_add(a, s + i, 20 - i);
}

static void
	fmt_int_sign_32
	(t_vect *a
	, t_i32 base
	, t_i32 x)
{
	bool	neg;
	char	s[11];
	size_t	i;

	i = 10;
	neg = (x < 0);
	if (!x)
		return ((void)vect_mset_end(a, '0', 1));
	while ((x > 0 || x <= base) && ((x < 0) || (x >= base)))
	{
		s[i] = x % base;
		s[i] = ABS(s[i]);
		s[i] += (s[i] <= 9) ? '0' : 'a' - 10;
		x /= base;
		i--;
	}
	if (x)
		s[i--] = ABS(x) + (x <= 9 ? '0' : 'a' - 10);
	if (neg)
		s[i--] = '-';
	i++;
	vect_add(a, s + i, 11 - i);
}

static void
	fmt_int_unsign
	(t_vect *a
	, t_u32 base
	, t_u64 x)
{
	char	s[21];
	size_t	i;

	i = 20;
	while (x >= base)
	{
		s[i] = x % base;
		s[i] += (s[i] <= 9) ? '0' : 'a' - 10;
		x /= base;
		i--;
	}
	if (x)
		s[i--] = x + (x <= 9 ? '0' : 'a' - 10);
	i++;
	vect_add(a, s + i, 21 - i);
}

static void
	fmt_int
	(t_vect *a
	, char **d
	, size_t *n
	, va_list l)
{
	char	*s;
	int		sign;
	t_u64	base;
	t_u64	bytes;

	sign = 0;
	base = 0;
	bytes = 0;
	if (**d == '-')
	{
		(*d)++;
		(*n)--;
		sign = 1;
	}
	s = STRTOB10(*d, base);
	if (*s == '/')
		s = STRTOB10(++s, bytes);
	*n -= s - *d;
	*d = s;
	if (sign)
		bytes == 4 ? fmt_int_sign_32(a, base, va_arg(l, t_i32))
			: fmt_int_sign_64(a, base, va_arg(l, t_i64));
	else
		fmt_int_unsign(a, base, va_arg(l, t_u64));
}

static void
	fmt
	(t_vect *a
	, char **d
	, size_t *n
	, va_list l)
{
	t_vect	*b;
	void	*p;

	if (**d == '-' || ft_isdigit(**d))
		return (fmt_int(a, d, n, l));
	p = va_arg(l, void *);
	if (**d == 's')
		vect_str_add(a, p);
	else if (**d == 'v')
	{
		b = p;
		vect_add(a, b->data, b->used);
	}
	else if (**d == 'a')
		fmt_int_sign_32(a, 10, va_arg(l, t_i32));
	else if (**d == 'b')
		fmt_int_sign_64(a, 10, va_arg(l, t_i32));
	else if (**d == 'c' || **d == 'd')
		fmt_int_unsign(a, 10, va_arg(l, t_i32));
	else if (**d == '%')
		vect_mset_end(a, '%', 1);
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
