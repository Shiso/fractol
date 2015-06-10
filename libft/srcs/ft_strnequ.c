/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgarcin <mgarcin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 18:24:57 by mgarcin           #+#    #+#             */
/*   Updated: 2015/03/04 10:47:34 by mgarcin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

int			ft_strnequ(const char *s1, const char *s2, t_size n)
{
	register unsigned int	i;

	i = 0;
	if (s1 == NULL || s2 == NULL)
		return (-1);
	while (i < n && s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	if (i > 0)
		i--;
	return (s1[i] == s2[i]);
}
