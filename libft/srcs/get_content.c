/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_content.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgarcin <mgarcin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/24 16:29:57 by mgarcin           #+#    #+#             */
/*   Updated: 2015/03/04 10:47:42 by mgarcin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "get_next_line.h"

char		**get_content(t_fd fd)
{
	char		**content;
	char		*line;
	int			new_size;
	int			count;

	content = NULL;
	count = 0;
	new_size = sizeof(char *) * 2;
	line = NULL;
	while (get_next_line(fd, &line))
	{
		content = ft_realloc_tab(content, new_size);
		content[count++] = line;
		new_size += sizeof(char *);
	}
	xclose(fd);
	return (content);
}
