/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgarcin <mgarcin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 18:36:50 by mgarcin           #+#    #+#             */
/*   Updated: 2015/03/04 10:47:39 by mgarcin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char		*ft_strsub(const char *s, unsigned int start, t_size len)
{
	char			*tmp;
	unsigned int	end;
	register int	i;

	i = 0;
	end = start + len;
	if (s == NULL || (tmp = (char *)(xmalloc(sizeof(char) * len + 1))) == NULL)
		return (NULL);
	while (start < end)
		tmp[i++] = s[start++];
	tmp[i] = '\0';
	return (tmp);
}
