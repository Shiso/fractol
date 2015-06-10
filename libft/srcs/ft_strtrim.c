/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgarcin <mgarcin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 19:44:05 by mgarcin           #+#    #+#             */
/*   Updated: 2015/03/04 10:47:40 by mgarcin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static char		*trim_left_ptr(char *str)
{
	if (!*str)
		return (str);
	if (*str == ' ' || *str == '\t' || *str == '\n')
		return (trim_left_ptr(str + 1));
	return (str);
}

static char		*trim_right_ptr(char *str)
{
	char	*ptr;

	if (!*str)
		return (str);
	ptr = trim_right_ptr(str + 1);
	if (*(ptr - 1) == ' ' || *(ptr - 1) == '\t' || *(ptr - 1) == '\n')
		return (ptr - 1);
	return (ptr);
}

char			*ft_strtrim(const char *s)
{
	char			*l_ptr;
	char			*r_ptr;
	char			*tmp;
	unsigned int	size;

	tmp = NULL;
	if (s == NULL)
		return (NULL);
	l_ptr = trim_left_ptr((char *)(s));
	r_ptr = trim_right_ptr((char *)(s));
	size = (unsigned int)(r_ptr - l_ptr);
	if ((int)(size) < 0)
		size = 0;
	if ((tmp = (char *)(xmalloc(size + 1))) == NULL)
		return (NULL);
	if (!size)
	{
		*(tmp + size) = '\0';
		return (tmp);
	}
	ft_memcpy(tmp, (void *)(l_ptr), size);
	*(tmp + size) = '\0';
	return (tmp);
}
