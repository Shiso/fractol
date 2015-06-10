/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgarcin <mgarcin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 14:57:00 by mgarcin           #+#    #+#             */
/*   Updated: 2015/03/04 10:47:22 by mgarcin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char		*ft_strdup(const char *s1)
{
	register int	i;
	char			*tmp;

	i = 0;
	if ((tmp = (char *)(xmalloc(sizeof(char) * (ft_strlen(s1) + 1)))) == NULL)
		return (NULL);
	while (*s1)
		tmp[i++] = *(s1++);
	tmp[i] = '\0';
	return (tmp);
}
