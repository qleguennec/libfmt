/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libfmt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-guen <qle-guen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/23 02:52:19 by qle-guen          #+#    #+#             */
/*   Updated: 2017/05/29 04:22:37 by qle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFMT_H
# define LIBFMT_H

# include <stdarg.h>
# include <unistd.h>
# include "../libvect/libvect.h"

int			fmt_print(int fd, int ret, char *s, size_t n, ...);
void		fmt_fmt(t_vect *a, char *s, size_t n, va_list l);
void		fmt_int(t_vect *a, char **d, size_t *n, va_list l);
void		fmt_int_sign_32(t_vect *a, int base, int x);
void		fmt_int_sign_64(t_vect *a, int base, long x);
void		fmt_int_unsign(t_vect *a, unsigned base, unsigned long x);
void		fmt_vect(t_vect *a, char *s, size_t n, ...);
void		fmt_err(void *arg);

int			echo(int ret, char *s, ...);
int			err(int ret, char *s, ...);
int			vfmt(int ret, t_vect *v, char *s, ...);

#endif
