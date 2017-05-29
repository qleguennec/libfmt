/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-guen <qle-guen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/29 04:15:18 by qle-guen          #+#    #+#             */
/*   Updated: 2017/05/29 04:35:35 by qle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libfmt.h"

int
	err
	(int ret
		, char *s
		, ...)
{
	t_vect	a;
	va_list	l;

	va_start(l, s);
	vect_init(&a);
	a.malloc_err_f = &fmt_err;
	fmt_fmt(&a, s, ft_strlen(s), l);
	add(0, &a, "\n");
	write(2, a.data, a.used);
	free(a.data);
	va_end(l);
	return (ret);
}
