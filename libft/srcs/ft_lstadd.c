/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgarcin <mgarcin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/28 11:50:11 by mgarcin           #+#    #+#             */
/*   Updated: 2015/03/04 10:46:57 by mgarcin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include "libft.h"

void		ft_lstadd(t_list **alst, t_list *new)
{
	t_list	*tmp;

	if (alst == NULL || *alst == NULL || new == NULL)
		return ;
	tmp = *alst;
	*alst = new;
	new->next = tmp;
}
