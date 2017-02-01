/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoncalv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/27 13:51:02 by jgoncalv          #+#    #+#             */
/*   Updated: 2017/01/27 13:51:04 by jgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

t_room	*new_room(t_room *lst_room, char *name, int x, int y)
{
	t_room	*newroom;

	newroom = NULL;
	if (!(newroom = (t_room*)malloc(sizeof(t_room))))
		return (NULL);
	if (name)
	{
		newroom->name = ft_strnew(ft_strlen(name));
		newroom->name = ft_strcpy(newroom->name, name);
	}
	else
		newroom->name = NULL;
	newroom->ants = 0;
	newroom->ants_min = 0;
	newroom->path_len = 0;
	newroom->coord_x = x;
	newroom->coord_y = y;
	newroom->path = NULL;
	newroom->lst_link = NULL;
	if (!lst_room)
		newroom->next = NULL;
	else
		newroom->next = lst_room;
	lst_room = newroom;
	return (lst_room);
}

t_link	*new_link(t_link *lst_link, t_room *room, t_link *parent)
{
	t_link	*newlink;
	t_link	*tmp;

	if (!(newlink = (t_link*)malloc(sizeof(t_link))))
		return (NULL);
	newlink->link = room;
	newlink->parent = parent;
	newlink->next = NULL;
	if (!lst_link)
		lst_link = newlink;
	else
	{
		tmp = lst_link;
		while (tmp && tmp->next)
			tmp = tmp->next;
		tmp->next = newlink;
	}
	return (lst_link);
}

t_ants	*add_ants(t_ants *lants, t_room *room, int id)
{
	t_ants	*nants;
	t_ants	*tmp;

	if (!(nants = (t_ants*)malloc(sizeof(t_ants))))
		return (NULL);
	nants->room = room;
	nants->ants_id = id;
	nants->room->ants++;
	if (!lants)
	{
		nants->next = NULL;
		nants->prev = NULL;
		lants = nants;
	}
	else
	{
		tmp = lants;
		nants->next = NULL;
		while (tmp && tmp->next)
			tmp = tmp->next;
		nants->prev = tmp;
		tmp->next = nants;
	}
	return (lants);
}
