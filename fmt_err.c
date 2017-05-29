/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fmt_err.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-guen <qle-guen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/29 04:09:07 by qle-guen          #+#    #+#             */
/*   Updated: 2017/05/29 04:10:32 by qle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libfmt.h"

void
	fmt_err
	(void *arg)
{
	static const char *msg = "libfmt error: malloc";

	(void)arg;
	write(1, msg, sizeof(msg));
}
