/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgarcin <mgarcin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 20:46:20 by mgarcin           #+#    #+#             */
/*   Updated: 2015/03/04 10:46:56 by mgarcin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static char		*ft_revstr(char *str)
{
	int		i;
	int		length;
	char	tmp;

	i = 0;
	length = ft_strlen(str) - 1;
	while (i <= length / 2)
	{
		tmp = str[i];
		str[i] = str[length - i];
		str[length - i] = tmp;
		i++;
	}
	return (str);
}

char			*ft_itoa(int n)
{
	char	str[32 + 1];
	int		i;
	int		signe;

	if (!n)
		return (ft_strdup("0"));
	signe = 1;
	if (n > 0)
	{
		signe = 0;
		n = -n;
	}
	i = 0;
	while (n != 0)
	{
		str[i] = -(n % 10) + '0';
		n = n / 10;
		i++;
	}
	if (signe)
		str[i++] = '-';
	str[i] = '\0';
	return (ft_strdup(ft_revstr(str)));
}
