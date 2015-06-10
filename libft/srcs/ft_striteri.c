/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgarcin <mgarcin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 17:38:21 by mgarcin           #+#    #+#             */
/*   Updated: 2015/03/04 10:47:24 by mgarcin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void		ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	register unsigned int	i;

	i = 0;
	if (s == NULL || f == NULL)
		return ;
	while (*s)
	{
		f(i, s);
		i++;
		s++;
	}
}
