/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libfmt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-guen <qle-guen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/23 02:52:19 by qle-guen          #+#    #+#             */
/*   Updated: 2017/01/12 14:46:48 by qle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFMT_H
# define LIBFMT_H

# include "../libft/libft.h"
# include "../libft/malloc.h"
# include "../libvect/libvect.h"

# define PRINT(s, ...)	fmt_print(1, 0, s, sizeof(s) - 1, __VA_ARGS__)
# define ECHO(s, ...)	fmt_print(1, 0, s "\n", sizeof(s), __VA_ARGS__)
# define ERR(s, r, ...)	fmt_print(2, r, s "\n", sizeof(s), __VA_ARGS__)

# ifdef T_U32_V2_ECHO
#  define ECHO2_U32(a) ECHO("V2(%c, %c)",(a).x,(a).y)
# endif

# ifdef T_U32_V4_ECHO
#  define ECHO4_U32(x) ECHO("V4(%c, %c, %c, %c)",(x).a,(x).b,(x).c,(x).d)
# endif

int			fmt_print(int fd, int ret, char *s, size_t n, ...);
void		fmt_fmt(t_vect *a, char *s, size_t n, va_list l);
void		fmt_int(t_vect *a, char **d, size_t *n, va_list l);
void		fmt_int_unsign(t_vect *a, t_u32 base, t_u64 x);
void		fmt_int_sign_32(t_vect *a, t_i32 base, t_i32 x);
void		fmt_int_sign_64(t_vect *a, t_i32 base, t_i64 x);

#endif
