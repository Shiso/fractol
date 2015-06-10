/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgarcin <mgarcin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/08/26 06:19:47 by mgarcin           #+#    #+#             */
/*   Updated: 2015/03/04 10:47:43 by mgarcin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include "get_next_line.h"

int				check_line(char *line, char *buff)
{
	int			nb;

	nb = 0;
	while (line[nb] != '\0')
	{
		if (line[nb] == '\n')
		{
			line[nb] = '\0';
			*buff = '\0';
			ft_strcat(buff, &line[nb + 1]);
			return (-1);
		}
		nb++;
	}
	*buff = '\0';
	return (0);
}

int				get_next_line(const int fd, char **line)
{
	int			i;
	static char	buff[BUFF_SIZE];

	if (fd < 0 || (*line = (char *)xmalloc(BUFF_SIZE * sizeof(**line))) == NULL)
		return (-1);
	**line = '\0';
	ft_strcat(*line, buff);
	*buff = '\0';
	i = BUFF_SIZE;
	while (check_line(*line, buff) != -1 && i == BUFF_SIZE)
	{
		if ((i = xread(fd, buff, BUFF_SIZE)) == -1)
		{
			xfree(*line);
			return (-1);
		}
		buff[i] = '\0';
		*line = ft_realloc(*line, i);
		ft_strcat(*line, buff);
	}
	if (**line == '\0' && ft_strlen(buff) == 0 && i != BUFF_SIZE)
		return (0);
	return (1);
}
