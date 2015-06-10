/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgarcin <mgarcin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 14:54:06 by mgarcin           #+#    #+#             */
/*   Updated: 2015/03/04 10:47:07 by mgarcin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memset(void *s, int c, t_size n)
{
	unsigned char			*p_s;
	register unsigned int	i;

	if (n == 0)
		return (s);
	p_s = (unsigned char *)(s);
	i = 0;
	while (i < n)
		p_s[i++] = (unsigned char)(c);
	return (s);
}
