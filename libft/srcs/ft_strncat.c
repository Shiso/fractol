/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgarcin <mgarcin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 14:58:09 by mgarcin           #+#    #+#             */
/*   Updated: 2015/03/04 10:47:31 by mgarcin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strncat(char *s1, const char *s2, t_size n)
{
	char	*tmp;

	tmp = s1;
	while (*s1)
		s1++;
	while (*s2 && n-- > 0)
		*(s1++) = *(s2++);
	*s1 = '\0';
	return (tmp);
}