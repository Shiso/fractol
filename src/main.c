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

void		ft_draw(t_fract *fract)
{
	int		i;
	t_light c;
	t_cplx	d;

	i = 0;
	while (i < (fract->aff->size_y * fract->aff->size_x) * 4)
	{
		d.r = DR(i);
		d.i = DI(i);
		if (fract->type == 1)
			c = mandel_point(fract, d, i / 4);
		else if (fract->type == 2)
		{
			d.r = (JMAX - JMIX) / 2 * (fract->mousex / fract->aff->size_x);
			d.i = (JMAY - JMIY) / 2 * (fract->mousey / fract->aff->size_y);
			c = julia_point(fract, d, i / 4);
		}
		else if (fract->type == 3)
			c = sniped_point(fract, d, i / 4);
		else if (fract->type == 4)
			c = burning_ship_point(fract, d, i / 4);
		set_color(fract, i, c);
		i += 4;
	}
}

int			init_struct(t_fract *fract)
{
	fract->zoom = 1;
	fract->x = 0;
	fract->y = 0;
	fract->mousex = 0;
	fract->mousey = 0;
	fract->inv = 1;
	fract->color = 0;
	fract->aff->size_x = 1000;
	fract->aff->size_y = 600;
	fract->aff->title = ft_strdup("Fractol");
	fract->aff->mlx = mlx_init();
	fract->aff->win = NEWWIN;
	fract->aff->img = NEWIMG;
	fract->aff->data = NEWDATA;
	return (0);
}

int			main(int ac, char **av)
{
	t_aff	display;
	t_fract	fractal;

	if (ac != 2 || av[1][0] < '1' || av[1][0] > '4' || ft_strlen(av[1]) != 1)
		ft_exit("1. Fractale de Mandelbrot\n2. Fractale de Julia\n\
			3. Fractale Sniped\n4. Fractale Burning Ship", 1);
	fractal.aff = &display;
	init_struct(&fractal);
	fractal.type = ft_atoi(av[1]);
	mlx_expose_hook(fractal.aff->win, expose_hook, &fractal);
	mlx_key_hook(fractal.aff->win, key_hook, &fractal);
	mlx_mouse_hook(fractal.aff->win, buttonpress_hook, &fractal);
	mlx_hook(fractal.aff->win, 6, (1L << 6), motion_hook, &fractal);
	mlx_loop(fractal.aff->mlx);
	return (0);
}
