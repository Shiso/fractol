/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdeniset <tdeniset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/04 15:10:28 by tdeniset          #+#    #+#             */
/*   Updated: 2015/03/05 17:10:48 by tdeniset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

int			julia_point_calc(t_cplx c, t_fract *fract, int x, int y)
{
	int		j;
	t_cplx	e;
	t_cplx	z;

	z.r = ((double)fract->aff->size_x / (double)fract->aff->size_y) * \
	(x - fract->aff->size_x / 2) / \
	(0.5 * fract->zoom * fract->aff->size_x) + fract->x;
	z.i = (y - fract->aff->size_y / 2) / (0.5 * fract->zoom * \
		fract->aff->size_y) + fract->y;
	j = -1;
	while (++j < ITER)
	{
		e.r = z.r;
		e.i = z.i;
		z.r = (e.r * e.r - e.i * e.i) + c.r;
		z.i = (2 * e.r * e.i) + c.i;
		if (((z.r * z.r) + (z.i * z.i)) >= 4)
			return (j);
	}
	return (j);
}

t_light		julia_point(t_fract *fract, t_cplx c, int i)
{
	t_light color;

	i = julia_point_calc(c, fract, (i % fract->aff->size_x), \
		(i / fract->aff->size_x));
	color = get_color(fract, i);
	return (color);
}
