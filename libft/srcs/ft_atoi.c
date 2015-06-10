/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgarcin <mgarcin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 16:23:54 by mgarcin           #+#    #+#             */
/*   Updated: 2015/03/04 10:46:44 by mgarcin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_ws(const char *str)
{
	register int	i;

	i = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n'
		|| str[i] == '\r' || str[i] == '\f' || str[i] == '\v')
		i++;
	return (i);
}

int				ft_atoi(const char *str)
{
	register t_size	i;
	int				res;
	int				sign;

	i = ft_ws(str);
	res = 0;
	sign = 1;
	if (*(str + i) == '-' || *(str + i) == '+')
		sign = (*(str + i++) == '-') ? -1 : 1;
	while (*(str + i) && *(str + i) >= '0' && *(str + i) <= '9')
	{
		res *= 10;
		res += (*(str + i) - '0');
		i++;
	}
	return (res * sign);
}
