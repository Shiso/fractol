/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdeniset <tdeniset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/04 15:10:28 by tdeniset          #+#    #+#             */
/*   Updated: 2015/03/05 17:10:48 by tdeniset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

int			buttonpress_hook(int button, int x, int y, t_fract *fract)
{
	if (x >= 0 && x < fract->aff->size_x && y >= 0 && y < fract->aff->size_y)
	{
		if (button == 5 || button == 1)
			fract->zoom *= 1.1;
		if (button == 4 || button == 2)
			fract->zoom /= 1.1;
		expose_hook(fract);
	}
	return (0);
}

int			motion_hook(int x, int y, t_fract *fract)
{
	if (x >= 0 && x < fract->aff->size_x && y >= 0 && y < fract->aff->size_y)
	{
		fract->mousex = x;
		fract->mousey = y;
		expose_hook(fract);
	}
	return (0);
}

int			expose_hook(t_fract *fract)
{
	ft_draw(fract);
	mlx_put_image_to_window(fract->aff->mlx, fract->aff->win, \
		fract->aff->img, 0, 0);
	return (0);
}

int			key_hook(int keycode, t_fract *fract)
{
	if (keycode == 53)
		exit(0);
	if (keycode == 123)
		fract->x -= 1 / fract->zoom;
	if (keycode == 124)
		fract->x += 1 / fract->zoom;
	if (keycode == 125)
		fract->y += 1 / fract->zoom;
	if (keycode == 126)
		fract->y -= 1 / fract->zoom;
	if (keycode == 18)
		fract->color = 0;
	if (keycode == 19)
		fract->color = 1;
	if (keycode == 20)
		fract->color = 2;
	if (keycode == 21)
		fract->color = 3;
	if (keycode == 49)
		fract->inv = !(fract->inv);
	expose_hook(fract);
	return (0);
}
