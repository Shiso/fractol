/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgarcin <mgarcin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 14:55:54 by mgarcin           #+#    #+#             */
/*   Updated: 2015/03/04 10:55:40 by mgarcin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void		*ft_memchr(const void *s, int c, t_size n)
{
	const unsigned char	*p;

	p = (const unsigned char *)(s);
	while (n-- > 0)
	{
		if (*p == (unsigned char)(c))
			return ((void *)(p));
		p++;
	}
	return (NULL);
}
