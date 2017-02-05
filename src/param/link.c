/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   link.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoncalv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/27 19:00:08 by jgoncalv          #+#    #+#             */
/*   Updated: 2017/01/27 19:00:10 by jgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static int	check_hyphen(char *str)
{
	int i;

	i = 0;
	while (*str)
	{
		if (*str == '-')
			i++;
		str++;
	}
	return (i);
}

static int	check_name(t_room *lst_room, char *name)
{
	while (lst_room)
	{
		if (ft_strcmp(lst_room->name, name) == 0)
			return (1);
		lst_room = lst_room->next;
	}
	return (0);
}

static int	check_link(t_room *room, char *r_name, char *l_name)
{
	t_link	*path;

	while (ft_strcmp(room->name, r_name) != 0)
		room = room->next;
	path = room->lst_link;
	while (path)
	{
		if (ft_strcmp(path->link->name, l_name) == 0)
			return (0);
		path = path->next;
	}
	return (1);
}

static int	add_link(t_room *room, char *r_name, char *l_name)
{
	t_room	*link;

	link = room;
	while (room && ft_strcmp(room->name, r_name) != 0)
		room = room->next;
	while (room && ft_strcmp(link->name, l_name) != 0)
		link = link->next;
	if (!room || !link)
		return (0);
	if (!(room->lst_link = new_link(room->lst_link, link, NULL)))
		return (0);
	return (1);
}

void		lst_link(t_graph *gr, char *line)
{
	int		i;
	char	**tab;

	if (!gr->room)
		ft_error("Error : Missign room\n", gr);
	if (!gr->start || !gr->end)
		ft_error("Error : Unconform\n", gr);
	if (ft_strchr(line, ' ') || check_hyphen(line) != 1)
		ft_error("Error : Unconform\n", gr);
	tab = ft_strsplit(line, '-');
	i = 0;
	while (tab[i])
		i++;
	if (i != 2 || ft_strcmp(tab[0], tab[1]) == 0)
		error_del_tab("Error : Unconform\n", tab, 1, gr);
	else if (!(check_name(gr->room, tab[0])) || !(check_name(gr->room, tab[1])))
		error_del_tab("Error : Room name doesn't exist\n", tab, 1, gr);
	else if (!(check_link(gr->room, tab[0], tab[1])))
		error_del_tab("Error : Link already include\n", tab, 1, gr);
	else if (!(add_link(gr->room, tab[1], tab[0])) &&
		!(add_link(gr->room, tab[0], tab[1])))
		error_del_tab("Error : New link failed\n", tab, 1, gr);
	else if (!(add_link(gr->room, tab[0], tab[1])))
		error_del_tab("Error : New link failed\n", tab, 1, gr);
	error_del_tab("", tab, 0, gr);
}
