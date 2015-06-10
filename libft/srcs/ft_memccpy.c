/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgarcin <mgarcin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 14:55:07 by mgarcin           #+#    #+#             */
/*   Updated: 2015/03/04 10:47:01 by mgarcin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void		*ft_memccpy(void *dest, const void *src, int c, t_size n)
{
	unsigned char			*d;
	unsigned char			*s;
	register unsigned int	i;

	d = (unsigned char *)(dest);
	s = (unsigned char *)(src);
	i = 0;
	c &= 0xff;
	while (i < n)
	{
		if ((*d++ = *s++) == c)
			return (d);
		i++;
	}
	return (NULL);
}
