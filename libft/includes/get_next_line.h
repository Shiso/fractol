/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgarcin <mgarcin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/08/26 06:22:59 by mgarcin           #+#    #+#             */
/*   Updated: 2015/03/04 10:53:17 by mgarcin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFF_SIZE (4096)

typedef struct	s_read
{
	char		*buffer;
	int			i;
	int			pos;
	int			nb_read;
}				t_read;

int				get_next_line(const int fd, char **line);

#endif
