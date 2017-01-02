/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fmt_fmt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-guen <qle-guen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/23 02:51:31 by qle-guen          #+#    #+#             */
/*   Updated: 2017/01/02 17:08:10 by qle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libfmt.h"
#include <stdio.h>

static void	fmt_int_sign(t_vect *a, t_u32 base, t_i64 x)
{
	char	s[20];
	int		neg;
	size_t	i;

	i = 19;
	neg = (x < 0);
	while (x)
	{
		s[i] = ABS(x % base);
		s[i] += (s[i] <= 9) ? '0' : 'a' - 10;
		x /= base;
		i--;
	}
	if (neg)
		s[i--] = '-';
	if (i == 19)
		s[i--] = '0';
	i++;
	vect_add(a, s + i, 20 - i);
}

static void	fmt_int_unsign(t_vect *a, t_u32 base, t_u64 x)
{
	char	s[19];
	size_t	i;

	i = 18;
	while (x >= base)
	{
		s[i] = x % base;
		s[i] += (s[i] <= 9) ? '0' : 'a' - 10;
		x /= base;
		i--;
	}
	s[i] = x + (x <= 9 ? '0' : 'a' - 10);
	vect_add(a, s + i, 19 - i);
}

static void	fmt_int(t_vect *a, char **d, size_t *n, va_list l)
{
	char	*s;
	int		sign;
	t_u32	base;

	sign = 0;
	base = 0;
	if (**d == '-')
	{
		(*d)++;
		(*n)--;
		sign = 1;
	}
	s = STRTOB10(*d, base);
	*n -= s - *d;
	*d = s;
	sign ? fmt_int_sign(a, base, va_arg(l, t_i64))
		: fmt_int_unsign(a, base, va_arg(l, t_u64));
}

static void	fmt(t_vect *a, char **d, size_t *n, va_list l)
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
	(*d)++;
	(*n)--;
}

void		fmt_fmt(t_vect *a, char *s, size_t n, va_list l)
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
