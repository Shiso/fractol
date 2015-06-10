/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   match.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgarcin <mgarcin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/08/25 05:13:13 by mgarcin           #+#    #+#             */
/*   Updated: 2015/03/04 10:47:44 by mgarcin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		match(const char *s1, const char *s2)
{
	if (*s2 == '*')
	{
		if (*(s2 + 1) == '*')
			return (match(s1, s2 + 1));
		if (!*(s2 + 1))
			return (1);
		if (!*s1)
			return (*(s2 + 1) == 0);
		if (*(s2 + 1) != *s1)
			return (match(s1 + 1, s2));
		return (match(s1 + 1, s2 + 2));
	}
	if (*s1 == *s2)
		return (*s1 ? match(s1 + 1, s2 + 1) : 1);
	else
	{
		if (*s1)
			return (match(s1 + 1, s2 - 2));
		else
			return (0);
	}
}
