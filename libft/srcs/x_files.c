/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   x_files.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgarcin <mgarcin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/08/24 08:38:38 by mgarcin           #+#    #+#             */
/*   Updated: 2015/03/04 10:48:02 by mgarcin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include "libft.h"

t_fd			xopen(const char *path, int oflag)
{
	int		ret;

	if ((ret = open(path, oflag)) == -1)
		ft_puterr("\033[1;31mError 0x00 Cannot open this file !\033[0;37m\n");
	return (ret);
}

int				xclose(t_fd fd)
{
	int		ret;

	if ((ret = close(fd)) == -1)
		ft_puterr("\033[1;31mError 0x01 File may still be open !\033[0;37m\n");
	return (ret);
}

int				xread(t_fd fd, void *ptr, int size)
{
	int		ret;

	if ((ret = read(fd, ptr, size)) == -1)
		ft_puterr("\033[1;31mError 0x02 Cannot read this input !\033[0;37m\n");
	return (ret);
}

int				xwrite(t_fd fd, void *ptr, int size)
{
	int		ret;

	if ((ret = write(fd, ptr, size)) == -1)
		ft_puterr("\033[1;31mError 0x03 Cannot write on output !\033[0;37m\n");
	return (ret);
}
