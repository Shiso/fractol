/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   serialize_variable.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgarcin <mgarcin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/14 08:42:46 by mgarcin           #+#    #+#             */
/*   Updated: 2015/03/04 10:52:00 by mgarcin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "get_next_line.h"
#include "serialize.h"

static char	*format_check(const char *var)
{
	char	*tmp;
	char	*sav;

	tmp = ft_strjoin("\t<", var);
	sav = tmp;
	tmp = ft_strjoin(tmp, ">*</");
	xfree(sav);
	sav = tmp;
	tmp = ft_strjoin(tmp, var);
	xfree(sav);
	sav = tmp;
	tmp = ft_strjoin(tmp, ">");
	xfree(sav);
	return (tmp);
}

static int	find_var(const char *format, t_xml *entry)
{
	if (match(entry->data, format))
		return (1);
	else
		return (0);
}

static char	*var_dup(char *var)
{
	int		size;
	char	*tmp;
	char	*beg;
	char	*val;

	tmp = var;
	size = 0;
	while (*(tmp++) != '<')
		size++;
	if ((val = xmalloc(sizeof(char) * size + 1)) == NULL)
		return (NULL);
	beg = val;
	while (*var != '<')
		*(val++) = *(var++);
	*(val) = '\0';
	return (beg);
}

static void	*get_value(int type, t_xml *entry)
{
	char	*var;
	void	*val;

	var = entry->data + 1;
	val = NULL;
	while (*var && *(var++) != '>')
		;
	if (type == sizeof(int))
	{
		if ((val = xmalloc(sizeof(int))) == NULL)
			return (NULL);
		*((int *)(val)) = ft_atoi(var);
	}
	if (type == sizeof(char *))
		val = var_dup(var);
	return (val);
}

void		*get_var_value(char *var, int type, t_xml *entry)
{
	int		found;
	char	*format;
	void	*value;

	found = 0;
	format = format_check(var);
	while (!match(entry->data, "</*>"))
	{
		if ((found = find_var(format, entry)))
			break ;
		entry = entry->next;
	}
	if (!found)
	{
		ft_puterr("\033[31mError\033[0m: \033[38;5;222m<");
		ft_puterr(var);
		ft_puterr("></");
		ft_puterr(var);
		ft_puterr(">\033[0m not found.\n");
		return (NULL);
	}
	if ((value = get_value(type, entry)) == NULL)
		return (NULL);
	xfree(format);
	return (value);
}
