/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgarcin <mgarcin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 14:54:32 by mgarcin           #+#    #+#             */
/*   Updated: 2015/03/04 10:46:51 by mgarcin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_bzero(void *s, t_size n)
{
	unsigned char	*tmp;

	if (n == 0)
		return ;
	tmp = (unsigned char *)(s);
	while (--n > 0)
		tmp[n] = 0;
	tmp[n] = 0;
}
