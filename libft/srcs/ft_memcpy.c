/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgarcin <mgarcin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 14:54:51 by mgarcin           #+#    #+#             */
/*   Updated: 2015/03/04 10:47:04 by mgarcin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memcpy(void *dest, const void *src, t_size n)
{
	char					*tmp;
	const char				*tmp2;
	register unsigned int	i;

	tmp = (char *)(dest);
	tmp2 = (char *)(src);
	i = 0;
	while (i < n)
	{
		tmp[i] = tmp2[i];
		i++;
	}
	return (dest);
}
