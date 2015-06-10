/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgarcin <mgarcin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 21:24:23 by mgarcin           #+#    #+#             */
/*   Updated: 2015/03/04 10:47:12 by mgarcin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"

void		ft_putnbr(int n)
{
	int		modulo;

	modulo = 0;
	if (n == -2147483648)
	{
		ft_putstr("-2147483648");
		return ;
	}
	if (n <= 9 && n >= 0)
		ft_putchar(n + '0');
	if (n < 0)
	{
		ft_putchar('-');
		n = n * (-1);
		if (n <= 9 && n >= 0)
			ft_putnbr(n);
	}
	if (n > 9)
	{
		modulo = n % 10;
		ft_putnbr(n / 10);
		ft_putchar(modulo + '0');
	}
}
