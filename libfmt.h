/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libfmt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-guen <qle-guen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/23 02:52:19 by qle-guen          #+#    #+#             */
/*   Updated: 2016/12/26 18:37:16 by qle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFMT_H
# define LIBFMT_H

# include "../libft/libft.h"
# include "../libft/malloc.h"
# include "../libvect/libvect.h"

# define PRINT(s, __VA_ARGS__)	fmt_print(1, 0, s, sizeof(s) - 1, __VA_ARGS__)
# define ECHO(s, __VA_ARGS__)	fmt_print(1, 0, s "\n", sizeof(s), __VA_ARGS__)
# define ERR(s, r, __VA_ARGS__)	fmt_print(2, r, s "\n", sizeof(s), __VA_ARGS__)

int			fmt_print(int fd, int ret, char *s, size_t n, ...);
void		fmt_fmt(t_vect *a, char *s, size_t n, va_list l);

#endif
