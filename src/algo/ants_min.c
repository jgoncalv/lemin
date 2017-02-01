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
	{
		nants->next = NULL;
		nants->prev = NULL;
		ants = nants;
	}
	else
	{
		ants->prev = nants;
		nants->next = ants;
		nants->prev = NULL;
	}
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
	return (ants);
}

static void		del_ants(t_ants *ants)
{
	if (ants && ants->prev)
		del_ants(ants->prev);
	free(ants);
	ants = NULL;
}

void			ants_min(t_link *path)
{
	t_ants	*ants;
	t_link	*tmp;
	t_ants	*tmp_ant;

	ants = NULL;
	tmp = path;
	while (tmp)
	{
		if (tmp->link->path)
			ants = add_lst_ants(ants, tmp->link);
		tmp = tmp->next;
	}
	ants = ft_sort(ants);
	tmp_ant = ants;
	while (tmp_ant)
	{
		if (tmp_ant->prev == NULL)
			tmp_ant->room->ants_min = 0;
		else
			tmp_ant->room->ants_min = tmp_ant->room->path_len -
		tmp_ant->prev->room->path_len + tmp_ant->prev->room->ants_min;
		tmp_ant = tmp_ant->next;
	}
	del_ants(ants);
}
