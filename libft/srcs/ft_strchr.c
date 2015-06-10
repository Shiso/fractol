/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgarcin <mgarcin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 14:58:36 by mgarcin           #+#    #+#             */
/*   Updated: 2015/03/04 10:56:29 by mgarcin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char		*ft_strchr(const char *s, int c)
{
	char	*tmp;

	tmp = (char *)(s);
	while (*tmp && *tmp != (char)(c))
		tmp++;
	return (*tmp == (char)(c) ? tmp : NULL);
}
