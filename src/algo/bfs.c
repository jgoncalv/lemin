/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfs.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoncalv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/27 22:27:24 by jgoncalv          #+#    #+#             */
/*   Updated: 2017/01/27 22:27:26 by jgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static t_link	*bfs_init(t_link *path, t_graph *gr)
{
	t_link *link_start;

	link_start = gr->start->lst_link;
	while (link_start)
	{
		if (link_start->link == gr->end)
			return (NULL);
		if (!link_start->link->path)
			if (!(path = new_link(path, link_start->link, NULL)))
				return (NULL);
		link_start = link_start->next;
	}
	return (path);
}

static int		check_exist(t_link *path, t_room *room)
{
	while (path)
	{
		if (path->link == room)
			return (0);
		path = path->next;
	}
	return (1);
}

static void		stock_path(t_link *pointe)
{
	while (pointe->parent)
	{
		pointe->parent->link->path = pointe->link;
		pointe->parent->link->path_len = pointe->link->path_len + 1;
		pointe = pointe->parent;
	}
}

static int		breadth_first_search(t_link *path, t_link *pointe, t_graph *gr)
{
	t_link	*tmp;

	if (!path)
		return (0);
	while (pointe && pointe->link != gr->end)
	{
		tmp = pointe->link->lst_link;
		while (tmp)
		{
			if (check_exist(path, tmp->link) &&
				!tmp->link->path && tmp->link != gr->start)
				path = new_link(path, tmp->link, pointe);
			tmp = tmp->next;
		}
		tmp = path;
		while (tmp != pointe)
			tmp = tmp->next;
		pointe = tmp->next;
	}
	if (!pointe)
		return (0);
	stock_path(pointe);
	return (1);
}

void			bfs_start(t_graph *gr)
{
	t_link	*path;

	path = NULL;
	if (!(path = bfs_init(path, gr)))
		return ;
	while (breadth_first_search(path, path, gr) == 1)
	{
		path = link_del(path);
		path = bfs_init(path, gr);
	}
	path = link_del(path);
}
