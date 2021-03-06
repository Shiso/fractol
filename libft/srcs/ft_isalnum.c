/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgarcin <mgarcin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 15:27:30 by mgarcin           #+#    #+#             */
/*   Updated: 2015/03/04 10:46:53 by mgarcin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int			ft_isalnum(int c)
{
	return ((c >= 'a' && c <= 'z')
	|| (c >= 'A' && c <= 'Z')
	|| (c >= '0' && c <= '9'));
}
