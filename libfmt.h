/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libfmt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-guen <qle-guen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/23 02:52:19 by qle-guen          #+#    #+#             */
/*   Updated: 2017/05/29 02:49:15 by qle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFMT_H
# define LIBFMT_H

# include <stdarg.h>
# include "../libvect/libvect.h"

# define FMTECHO(s, ...)	fmt_print(1, 1, s "\n", sizeof(s), __VA_ARGS__)
# define FMTERR(s, r, ...)	fmt_print(2, r, s "\n", sizeof(s), __VA_ARGS__)
# define FMTPRINT(s, ...)	fmt_print(1, 1, s, sizeof(s) - 1, __VA_ARGS__)
# define FMTPUT(s)			fmt_print(1, 1, s, sizeof(s) - 1)
# define FMTPUTNL(s)		fmt_print(1, 1, s "\n", sizeof(s))

# define VFMT(v, s, ...) fmt_vect(v, s, sizeof(s) - 1, __VA_ARGS__)
>>>>>>> 3cbfaff1573ec2f01b2d33e25c46f51e77080ff0

int			fmt_print(int fd, int ret, char *s, size_t n, ...);
void		fmt_fmt(t_vect *a, char *s, size_t n, va_list l);
void		fmt_int(t_vect *a, char **d, size_t *n, va_list l);
void		fmt_int_sign_32(t_vect *a, int base, int x);
void		fmt_int_sign_64(t_vect *a, int base, long x);
void		fmt_int_unsign(t_vect *a, unsigned base, unsigned long x);
void		fmt_vect(t_vect *a, char *s, size_t n, ...);

#endif
