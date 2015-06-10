/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgarcin <mgarcin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/28 10:31:08 by mgarcin           #+#    #+#             */
/*   Updated: 2015/03/04 10:46:58 by mgarcin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void		ft_lstdel(t_list **alst, void (*del)(void *, t_size))
{
	t_list	*sav;
	t_list	*next;

	if (alst == NULL || *alst == NULL)
		return ;
	sav = *alst;
	next = sav;
	while (sav != NULL)
	{
		sav = next;
		next = sav->next;
		del((sav)->content, sav->content_size);
		free(sav);
		sav = NULL;
	}
	*alst = NULL;
}
