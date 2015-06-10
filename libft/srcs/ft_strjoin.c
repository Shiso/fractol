/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgarcin <mgarcin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 19:13:49 by mgarcin           #+#    #+#             */
/*   Updated: 2015/03/04 10:47:25 by mgarcin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char		*ft_strjoin(const char *s1, const char *s2)
{
	int				size;
	register int	i;
	register int	j;
	char			*tmp;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	size = ft_strlen(s1) + ft_strlen(s2) + 1;
	i = 0;
	j = 0;
	if ((tmp = (char *)(xmalloc(sizeof(char) * size))) == NULL)
		return (NULL);
	while (s1[j])
		tmp[i++] = s1[j++];
	j = 0;
	while (s2[j])
		tmp[i++] = s2[j++];
	tmp[i] = '\0';
	return (tmp);
}
