/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fractal.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgarcin <mgarcin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/04 15:10:28 by mgarcin           #+#    #+#             */
/*   Updated: 2015/03/05 17:10:48 by mgarcin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTAL_H
# define FRACTAL_H

# include "../libft/includes/libft.h"
# include <mlx.h>
# include <stdlib.h>
# include <unistd.h>

# define ABS(x) (x < 0) ? -x : x
# define JMAX 1
# define JMIX -1
# define JMAY 1.2
# define JMIY -1.2
# define ITER 255

# define DR(i) ((double)fract->aff->sx / (double)fract->aff->sy) * (((i / 4) % fract->aff->sx) - fract->aff->sx / 2) / (0.5 * fract->zoom * fract->aff->sx) + fract->x
# define DI(i) (((i / 4) / fract->aff->sx) - fract->aff->sy / 2) / (0.5 * fract->zoom * fract->aff->sy) + fract->y

# define NEWWIN mlx_new_window(fract->aff->mlx, fract->aff->sx, fract->aff->sy, fract->aff->title)
# define NEWIMG mlx_new_image(fract->aff->mlx, fract->aff->sx, fract->aff->sy)
# define NEWDATA (char *)mlx_get_data_addr(fract->aff->img, &fract->aff->bpp, &fract->aff->size_l, &fract->aff->endian)

typedef struct s_fract	t_fract;
typedef	struct s_aff	t_aff;
typedef	struct s_light	t_light;
typedef	struct s_cplx	t_cplx;

struct		s_aff
{
	void	*mlx;
	void	*win;
	void	*img;
	char	*data;
	int		sx;
	int		sy;
	int		bpp;
	int		size_l;
	int		endian;
	char	*title;
};

struct		s_fract
{
	t_aff	*aff;
	double	zoom;
	double	x;
	double	y;
	double	mousex;
	double	mousey;
	int		type;
	short	inv;
	int		color;
	void	*fractalgo;
};

struct		s_light
{
	int	r;
	int	g;
	int	b;
};

struct		s_cplx
{
	double r;
	double i;
};

void		ft_draw(t_fract *fract);

t_light		mandel_point(t_fract *fract, t_cplx c, int i);
t_light		julia_point(t_fract *fract, t_cplx c, int i);
t_light		sniped_point(t_fract *fract, t_cplx c, int i);
t_light		burning_ship_point(t_fract *fract, t_cplx c, int i);

void		ft_exit(char *s, int fd);
double		ft_abs(double x);

int			buttonpress_hook(int button, int x, int y, t_fract *fract);
int			motion_hook(int x, int y, t_fract *fract);
int			expose_hook(t_fract *fract);
int			key_hook(int keycode, t_fract *fract);

t_light		get_color(t_fract *fract, int i);
void		set_color(t_fract *fract, int i, t_light c);

#endif
