/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   x_ptr.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgarcin <mgarcin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/08/26 06:46:57 by mgarcin           #+#    #+#             */
/*   Updated: 2015/03/04 10:47:55 by mgarcin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void			*xmalloc(int size)
{
	void	*ptr;

	if ((ptr = malloc(size)) == NULL)
		ft_puterr("\033[1;31mError 0x04 Cannot allocate memory !\033[0;37m\n");
	return (ptr);
}

void			xfree(void *ptr)
{
	if (ptr == NULL)
		ft_puterr("\033[1;31mError 0x05 Cannot free this pointer\033[0;37m\n");
	else
		free(ptr);
}
