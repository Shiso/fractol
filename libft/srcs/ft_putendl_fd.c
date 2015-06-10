/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgarcin <mgarcin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 21:51:31 by mgarcin           #+#    #+#             */
/*   Updated: 2015/03/04 10:47:10 by mgarcin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <string.h>
#include "libft.h"

void		ft_putendl_fd(const char *s, t_fd fd)
{
	xwrite(fd, (void *)s, ft_strlen(s));
	xwrite(fd, "\n", 1);
}
