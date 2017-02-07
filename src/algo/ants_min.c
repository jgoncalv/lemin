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

static void		ft_sort(t_ants *ants)
{
	t_ants	*tants;
	t_room	*tmp;

	while (ants && ants->next)
	{
		tants = ants->next;
		while (tants)
		{
			if (ants->room->path_len > tants->room->path_len)
			{
				tmp = ants->room;
				ants->room = tants->room;
				tants->room = tmp;
			}
			tants = tants->next;
		}
		ants = ants->next;
	}
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
	t_ants	*tmp;
	int		i;

	i = 0;
	while (path)
	{
		if (path->prev == NULL)
			path->room->ants_min = 0;
		else
		{
			tmp = path->prev;
			while (tmp)
			{
				path->room->ants_min += ((path->room->path_len + 1)
					- (tmp->room->path_len + 1));
				tmp = tmp->prev;
			}
		}
		i++;
		path = path->next;
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
	ft_sort(ants);
	calc_ants_min(ants);
	del_ants(ants);
}
