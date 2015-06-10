/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgarcin <mgarcin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 16:07:09 by mgarcin           #+#    #+#             */
/*   Updated: 2015/03/04 10:47:00 by mgarcin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void		*ft_memalloc(t_size size)
{
	void	*tmp;

	if ((tmp = xmalloc(size)) == NULL)
		return (NULL);
	ft_bzero(tmp, size);
	return (tmp);
}
