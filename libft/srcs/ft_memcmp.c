/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgarcin <mgarcin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 14:56:12 by mgarcin           #+#    #+#             */
/*   Updated: 2015/03/04 10:47:02 by mgarcin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_memcmp(const void *s1, const void *s2, t_size n)
{
	unsigned char	*str1;
	unsigned char	*str2;

	if (!n)
		return (0);
	str1 = (unsigned char*)s1;
	str2 = (unsigned char*)s2;
	while (n-- && *str1++ == *str2++)
		;
	return (*(str1 - 1) - *(str2 - 1));
}
