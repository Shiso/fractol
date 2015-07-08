/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgarcin <mgarcin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/05 16:48:06 by mgarcin           #+#    #+#             */
/*   Updated: 2015/03/05 16:52:39 by mgarcin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

double	ft_abs(double x)
{
	if (x < 0)
		return (-x);
	return (x);
}

void	ft_exit(char *s, int fd)
{
	ft_putendl_fd(s, fd);
	exit(0);
}
