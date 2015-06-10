/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   serialize.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgarcin <mgarcin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/14 08:29:45 by mgarcin           #+#    #+#             */
/*   Updated: 2015/03/04 10:48:18 by mgarcin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "libft.h"
#include "get_next_line.h"
#include "serialize.h"

void			*xml_get_value(char *entry, char *var, int type, t_xml *xml)
{
	t_xml	*entry_s;
	void	*value;

	if ((entry_s = get_entry_beg(entry, xml)) == NULL)
		return (NULL);
	if ((value = get_var_value(var, type, entry_s->next)) == NULL)
		return (NULL);
	return (value);
}

static t_xml	*add_line(t_xml *xml, char *line)
{
	if (line == NULL)
		return (NULL);
	if (xml == NULL)
	{
		if ((xml = xmalloc(sizeof(t_xml))) == NULL)
			return (NULL);
		xml->data = ft_strdup(line);
		xml->beg = xml;
		xml->next = xml;
		return (xml);
	}
	while (xml->next != xml->beg)
		xml = xml->next;
	if ((xml->next = xmalloc(sizeof(t_xml))) == NULL)
		return (NULL);
	xml->next->data = ft_strdup(line);
	xml->next->beg = xml->beg;
	xml->next->next = xml->beg;
	return (xml->beg);
}

t_xml			*xml_deserialize(char *file)
{
	t_fd	fd;
	char	*line;
	t_xml	*xml;

	xml = NULL;
	if ((fd = xopen(file, O_RDONLY)) == -1)
		return (NULL);
	while (get_next_line(fd, &line))
	{
		if ((xml = add_line(xml, line)) == NULL)
			return (NULL);
		xfree(line);
	}
	return (xml->beg);
}
