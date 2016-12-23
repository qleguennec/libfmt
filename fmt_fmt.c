/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fmt_fmt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-guen <qle-guen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/23 02:51:31 by qle-guen          #+#    #+#             */
/*   Updated: 2016/12/23 03:12:18 by qle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static void	fmt(t_vect *a, char d, void *arg)
{
	t_vect	*b;

	if (d == 's')
		vect_str_add(a, arg);
	else if (d == 'v')
	{
		b = arg;
		vect_add(a, b->data, b->size);
	}
}

void		fmt_fmt(t_vect *a, char *s, size_t n, va_list l)
{
	char	*d;
	void	*arg;

	d = ft_memchr(s, '%', n);
	vect_add(a, s, d - s);
	if (!d)
		return ;
	n -= d - s;
	if (n < 2)
		return ;
	d++;
	n--;
	arg = va_arg(l, void *);
	fmt(a, *d, arg);
	fmt_fmt(a, s, n1);
}
