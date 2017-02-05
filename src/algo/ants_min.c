/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ants_min.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoncalv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/28 02:23:13 by jgoncalv          #+#    #+#             */
/*   Updated: 2017/01/28 02:23:14 by jgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static t_ants	*add_lst_ants(t_ants *ants, t_room *room)
{
	t_ants *nants;

	if (!(nants = (t_ants*)malloc(sizeof(t_ants))))
		return (NULL);
	nants->room = room;
	if (!ants)
		nants->next = NULL;
	else
	{
		ants->prev = nants;
		nants->next = ants;
	}
	nants->prev = NULL;
	ants = nants;
	return (ants);
}

static t_ants	*ft_sort(t_ants *ants)
{
	t_ants	*tmp;
	t_ants	*tmpnext;
	t_room	*roomtmp;

	tmp = ants;
	while (tmp && tmp->next)
	{
		tmpnext = tmp->next;
		while (tmpnext && tmp->next)
		{
			if (tmp->room->path_len > tmpnext->room->path_len)
			{
				roomtmp = tmp->room;
				tmp->room = tmpnext->room;
				tmpnext->room = roomtmp;
			}
			tmpnext = tmpnext->next;
		}
		tmp = tmp->next;
	}
	while (ants && ants->prev != NULL)
		ants = ants->prev;
	return (ants);
}

static void		del_ants(t_ants *ants)
{
	if (ants && ants->next)
		del_ants(ants->next);
	free(ants);
	ants = NULL;
}

static void		calc_ants_min(t_ants *path)
{
	int	i;

	i = 0;
	while (path)
	{
		if (path->prev == NULL)
			path->room->ants_min = 0;
		else
			path->room->ants_min = path->room->path_len +
		path->prev->room->ants_min - i;
		path = path->next;
		i++;
	}
}

void			ants_min(t_link *path, t_graph *gr)
{
	t_ants	*ants;
	t_link	*tmp;

	ants = NULL;
	tmp = path;
	while (tmp)
	{
		if (tmp->link->path || tmp->link == gr->end)
			ants = add_lst_ants(ants, tmp->link);
		tmp = tmp->next;
	}
	ants = ft_sort(ants);
	calc_ants_min(ants);
	del_ants(ants);
}
