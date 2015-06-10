/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgarcin <mgarcin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 21:57:06 by mgarcin           #+#    #+#             */
/*   Updated: 2015/03/04 10:47:13 by mgarcin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <string.h>
#include "libft.h"

void		ft_putnbr_fd(int n, t_fd fd)
{
	int		modulo;

	modulo = 0;
	if (n == -2147483648)
	{
		ft_putstr_fd("-2147483648", fd);
		return ;
	}
	if (n <= 9 && n >= 0)
		ft_putchar_fd(n + '0', fd);
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		n = n * (-1);
		if (n <= 9 && n >= 0)
			ft_putnbr_fd(n, fd);
	}
	if (n > 9)
	{
		modulo = n % 10;
		ft_putnbr_fd(n / 10, fd);
		ft_putchar_fd(modulo + '0', fd);
	}
}
