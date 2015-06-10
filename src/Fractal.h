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
# define MANDEL_MAXX 2.4
# define MANDEL_MINX -2.4
# define MANDEL_MAXY 1.5
# define MANDEL_MINY -1.5
# define ITER 200

typedef struct	s_fract t_fract;
typedef	struct	s_aff t_aff;
typedef	struct	s_light t_light;
typedef	struct	s_cplx t_cplx;

struct s_aff
{
	void	*mlx;
	void	*win;
	void	*img;
	char	*data;
	int		size_x;
	int		size_y;
	int		bpp;
	int		size_l;
	int		endian;
	char	*title;
};

struct s_fract
{
	t_aff	*aff;
	double	zoom;
	double	x;
	double	y;
	short	inv;
	int		color;
	void	*fractalgo;
};

struct s_light
{
	int	r;
	int	g;
	int	b;
};

struct s_cplx
{
	double r;
	double i;
};

void	ft_exit(char *s, int fd);

#endif