/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgarcin <mgarcin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 14:56:41 by mgarcin           #+#    #+#             */
/*   Updated: 2015/03/04 10:47:29 by mgarcin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_size		ft_strlen(const char *str)
{
	register t_size	size;

	size = 0;
	while (*str)
	{
		str++;
		size++;
	}
	return (size);
}
