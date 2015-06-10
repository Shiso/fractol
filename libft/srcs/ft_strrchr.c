/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgarcin <mgarcin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 14:58:46 by mgarcin           #+#    #+#             */
/*   Updated: 2015/03/04 10:47:36 by mgarcin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char		*ft_strrchr(const char *s, int c)
{
	char	*tmp;
	char	*tmp2;

	tmp = NULL;
	tmp2 = (char *)(s);
	while (*tmp2)
	{
		while (*tmp2 && *tmp2 != (char)(c))
			tmp2++;
		if (*tmp2 == (char)(c))
			tmp = tmp2;
		tmp2++;
	}
	return (tmp);
}
