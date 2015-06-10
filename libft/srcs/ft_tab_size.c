/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tab_size.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgarcin <mgarcin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/07 14:07:22 by mgarcin           #+#    #+#             */
/*   Updated: 2015/03/04 10:47:41 by mgarcin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_tab_size(char **tab)
{
	int	sz;

	sz = 0;
	while (*tab)
	{
		tab++;
		sz++;
	}
	return (sz);
}
