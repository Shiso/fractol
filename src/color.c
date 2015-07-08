/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdeniset <tdeniset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/04 15:10:28 by tdeniset          #+#    #+#             */
/*   Updated: 2015/03/05 17:10:48 by tdeniset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fractal.h"
#include "mlx.h"

char		ft_color_comp(t_light c, int indian, int byte)
{
	c.r = (c.r > 255) ? 255 : c.r;
	c.g = (c.g > 255) ? 255 : c.g;
	c.b = (c.b > 255) ? 255 : c.b;
	if (indian)
	{
		if (byte == 1)
			return ((char)((int)c.r));
		if (byte == 2)
			return ((char)((int)c.g));
		if (byte == 3)
			return ((char)((int)c.b));
		else
			return (0);
	}
	else
	{
		if (byte == 0)
			return ((char)((int)c.b));
		if (byte == 1)
			return ((char)((int)c.g));
		if (byte == 2)
			return ((char)((int)c.r));
		else
			return (0);
	}
}

t_light		get_color_two(t_fract *fract, int i)
{
	t_light c;

	if (fract->color == 2)
	{
		c.r = ((double)255 / (double)ITER) * i + ((8 - (i % 8)) * (255 / 16));
		c.g = ((double)255 / (double)ITER) * (i * 0.2) + ((i % 3) * (255 / 40));
		c.b = ((double)255 / (double)ITER) * ((i % 9) * (255 / 50));
	}
	else if (fract->color == 3)
	{
		c.r = ((double)130 / (double)ITER) * i;
		c.g = ((double)180 / (double)ITER) * i + 20;
		c.b = ((double)200 / (double)ITER) * i * 2 + 50;
	}
	return (c);
}

t_light		get_color(t_fract *fract, int i)
{
	t_light c;

	if (fract->color == 0)
	{
		c.r = ((double)255 / (double)ITER) * i;
		c.g = 0;
		c.b = ((double)255 / (double)ITER) * i / 4;
	}
	else if (fract->color == 1)
	{
		c.r = ((double)255 / (double)ITER) * i + ((i % 8) * (255 / 16));
		c.g = ((double)255 / (double)ITER) * ((i % 3) * (255 / 30));
		c.b = ((double)255 / (double)ITER) * (i * 0.2) + ((i % 5) * (255 / 15));
	}
	else
		c = get_color_two(fract, i);
	if (!fract->inv)
	{
		c.r = 255 - c.r;
		c.g = 255 - c.g;
		c.b = 255 - c.b;
	}
	return (c);
}

void		set_color(t_fract *fract, int i, t_light c)
{
	fract->aff->data[i] = ft_color_comp(c, fract->aff->endian, 0);
	fract->aff->data[i + 1] = ft_color_comp(c, fract->aff->endian, 1);
	fract->aff->data[i + 2] = ft_color_comp(c, fract->aff->endian, 2);
	fract->aff->data[i + 3] = ft_color_comp(c, fract->aff->endian, 3);
}
