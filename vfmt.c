/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vfmt.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-guen <qle-guen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/29 04:17:06 by qle-guen          #+#    #+#             */
/*   Updated: 2017/05/29 04:23:14 by qle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libfmt.h"

int
	vfmt
	(int ret
		, t_vect *v
		, char *s
		, ...)
{

	va_list	l;

	va_start(l, s);
	fmt_fmt(v, s, ft_strlen(s), l);
	va_end(l);
	return (ret);
}