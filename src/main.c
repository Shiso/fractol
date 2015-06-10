/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgarcin <mgarcin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/04 14:56:43 by mgarcin           #+#    #+#             */
/*   Updated: 2015/03/05 17:11:35 by mgarcin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fractal.h"
#include "mlx.h"

#include <stdio.h>

char	ft_color_comp(t_light c, int indian, int byte)
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

void	init_display(t_fract *fract)
{
	int i;
	t_light c;

	i = 0;
	c.r = 255;
	c.g = 0;
	c.b = 0;
	while (i < (fract->aff->size_y * fract->aff->size_x) * 4)
	{
		fract->aff->data[i] = ft_color_comp(c, fract->aff->endian, 0);
		fract->aff->data[i + 1] = ft_color_comp(c, fract->aff->endian, 1);
		fract->aff->data[i + 2] = ft_color_comp(c, fract->aff->endian, 2);
		fract->aff->data[i + 3] = ft_color_comp(c, fract->aff->endian, 3);
		i += 4;
	}
}

int		mandel_point_calc(t_cplx c)
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
		z.r = (e.r * e.r - e.i * e.i) + c.r;
		z.i = (2 * e.r * e.i) + c.i;
		if (((z.r * z.r) + (z.i * z.i)) >= 4)
			return (j);
	}
	return (j);
}
t_light	get_color(t_fract *fract, int i)
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
	else if (fract->color == 2)
	{
		c.r = ((double)255 / (double)ITER) * i + ((i % 8) * (255 / 16));
		c.b = ((double)255 / (double)ITER) * ((i % 9) * (255 / 50));
		c.g = ((double)255 / (double)ITER) * (i * 0.2) + ((i % 3) * (255 / 40));
	}
	if (!fract->inv)
	{
		c.r = 255 - c.r;
		c.g = 255 - c.g;
		c.b = 255 - c.b;
	}
	return (c);
}
t_light	mandel_point(t_fract *fract, int i)
{
	t_cplx	c;
	t_light color;

	c.r =  2 * ((i % fract->aff->size_x) - fract->aff->size_x / 2) / (0.5 * fract->zoom * fract->aff->size_x) + fract->x;
	c.i = ((i / fract->aff->size_x) - fract->aff->size_y / 2) / (0.5 * fract->zoom * fract->aff->size_y) + fract->y;
	i = mandel_point_calc(c);
	color = get_color(fract, i);
	return (color);
}

void	ft_draw_mandel(t_fract *fract)
{
	int		i;
	t_light c;

	i = 0;
	while (i < (fract->aff->size_y * fract->aff->size_x) * 4)
	{
		c = mandel_point(fract, i / 4);
		fract->aff->data[i] = ft_color_comp(c, fract->aff->endian, 0);
		fract->aff->data[i + 1] = ft_color_comp(c, fract->aff->endian, 1);
		fract->aff->data[i + 2] = ft_color_comp(c, fract->aff->endian, 2);
		fract->aff->data[i + 3] = ft_color_comp(c, fract->aff->endian, 3);
		i += 4;
	}
}

int		expose_hook(t_fract *fract)
{
	ft_draw_mandel(fract);
	mlx_put_image_to_window(fract->aff->mlx, fract->aff->win, fract->aff->img, 0, 0);
	return (0);
}

int		key_hook(int keycode, t_fract *fract)
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
	if (keycode == 49)
	{
		if (fract->inv)
			fract->inv = 0;
		else
			fract->inv = 1;
	}
	expose_hook(fract);
	return (0);
}

int buttonpress_hook(int button, int x, int y, t_fract *fract)
{
	if (x >= 0 && x < fract->aff->size_x && y >= 0 && y < fract->aff->size_y)
	{
		if (button == 5)
			fract->zoom *= 1.1;
		if (button == 4)
			fract->zoom /= 1.1;
		expose_hook(fract);
	}
	return (0);
}

int		init_struct(t_fract *fract)
{
	fract->zoom = 1;
	fract->x = 0;
	fract->y = 0;
	fract->inv = 1;
	fract->color = 0;
	fract->aff->size_x = 1000;
	fract->aff->size_y = 600;
	fract->aff->title = ft_strdup("Fractol");
	fract->aff->mlx = mlx_init();
	fract->aff->win = mlx_new_window(fract->aff->mlx, fract->aff->size_x, fract->aff->size_y, fract->aff->title);
	fract->aff->img = mlx_new_image(fract->aff->mlx, fract->aff->size_x, fract->aff->size_y);
	fract->aff->data = (char *)mlx_get_data_addr(fract->aff->img, &fract->aff->bpp, &fract->aff->size_l, &fract->aff->endian);
    return (0);
}

int		main(int ac, char **av)
{
	t_aff	display;
	t_fract	fractal;

	if (ac != 2 || (ABS(ft_strcmp(av[1], "2"))) > 1)
		ft_exit("1. Fractale de machin\n2. Fractale de truc\n3. Fractale des sources chaudes", 1);
	fractal.aff = &display;
	init_struct(&fractal);
	init_display(&fractal);
	mlx_expose_hook(fractal.aff->win, expose_hook, &fractal);
    mlx_key_hook(fractal.aff->win, key_hook, &fractal);
    mlx_mouse_hook(fractal.aff->win, buttonpress_hook, &fractal);
	mlx_loop(fractal.aff->mlx);
	return (0);
}
