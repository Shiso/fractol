/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgarcin <mgarcin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 21:21:09 by mgarcin           #+#    #+#             */
/*   Updated: 2015/03/04 10:47:10 by mgarcin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

void		ft_putendl(const char *s)
{
	xwrite(1, (void *)(s), ft_strlen(s));
	ft_putchar('\n');
}
