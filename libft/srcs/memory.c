/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgarcin <mgarcin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/09/03 14:32:27 by mgarcin           #+#    #+#             */
/*   Updated: 2015/03/04 10:47:44 by mgarcin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char			*ft_realloc(char *str, int size)
{
	char		*new;

	if (size == 0)
		return (str);
	if ((new = (char *)xmalloc((ft_strlen(str) + size + 1)
				* sizeof(*str))) == NULL)
		return (NULL);
	*new = '\0';
	ft_strcat(new, str);
	*str = '\0';
	xfree(str);
	return (new);
}

char			**ft_realloc_tab(char **tab, int size)
{
	char		**new;
	char		**free_it;
	char		**sav;

	free_it = tab;
	if ((new = xmalloc(size)) == NULL)
		return (NULL);
	sav = new;
	while (tab != NULL && *tab != NULL)
		*(new++) = *(tab++);
	*(new + 1) = NULL;
	if (free_it != NULL)
		xfree(free_it);
	return (sav);
}

void			*ft_realloc_ptr(char *ptr, int old, int size)
{
	int			i;
	char		*new;
	char		*sav;
	char		*beg;

	i = -1;
	if (size == 0)
		return (ptr);
	beg = ptr;
	if ((new = xmalloc((old + size))) == NULL)
		return (NULL);
	sav = new;
	while (++i < old)
		*(new++) = *(ptr++);
	while (i < size)
	{
		*(new++) = '\0';
		i++;
	}
	xfree(beg);
	return (sav);
}
