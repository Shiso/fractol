/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgarcin <mgarcin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 14:59:56 by mgarcin           #+#    #+#             */
/*   Updated: 2015/03/04 10:47:35 by mgarcin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char		*ft_strnstr(const char *s1, const char *s2, t_size n)
{
	register unsigned int	i;
	register unsigned int	j;

	i = 0;
	j = 0;
	if (*s1 && !*s2)
		return ((char *)(s1));
	while (s1[i] && i < n)
	{
		if (s1[i] == s2[j])
			j = j + 1;
		else
			j = 0;
		if (!s2[j])
		{
			i = i - (j - 1);
			return ((char *)(s1 + i));
		}
		i = i + 1;
	}
	return (NULL);
}
