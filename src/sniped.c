/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sniped.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdeniset <tdeniset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/04 15:10:28 by tdeniset          #+#    #+#             */
/*   Updated: 2015/03/05 17:10:48 by tdeniset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

t_light		sniped_point(t_fract *fract, t_cplx c, int i)
{
	int		j;
	t_cplx	e;
	t_cplx	z;

	z.r = 0;
	z.i = 0;
	j = -1;
	while (++j < ITER)
	{
		e.r = z.r;
		e.i = z.i;
		z.r = (ft_abs(e.r) * ft_abs(e.r) - ft_abs(e.i) * ft_abs(e.i)) + c.r;
		z.i = (2 * e.r * e.i) + c.i;
		if (((z.r * z.r) + (z.i * z.i)) >= 4)
			return (get_color(fract, j));
	}
	return (get_color(fract, j));
}
