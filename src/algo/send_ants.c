/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   send_ants.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoncalv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/27 23:30:47 by jgoncalv          #+#    #+#             */
/*   Updated: 2017/01/27 23:30:48 by jgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static void		del_ants(t_ants *ants)
{
	if (ants && ants->next)
		del_ants(ants->next);
	free(ants);
	ants = NULL;
}

static void		move_ants(t_ants *ants)
{
	while (ants)
	{
		if (ants->room->path)
		{
			ants->room->ants--;
			ants->room = ants->room->path;
			ants->room->ants++;
			display(ants->ants_id, ants->room->name);
		}
		ants = ants->next;
	}
}

static t_ants	*move_start_ants(t_ants *lants, t_graph *gr)
{
	t_link		*path;
	static int	id = 1;
	int			i;

	if (gr->start->ants > 0)
	{
		path = gr->start->lst_link;
		i = 0;
		while (path && gr->start->ants - i > 0)
		{
			if ((path->link->path || path->link == gr->end)
				&& path->link->ants_min <= gr->start->ants)
			{
				if (!(lants = add_ants(lants, path->link, id)))
					ft_error("Error\n", gr);
				display(id, path->link->name);
				id++;
				i++;
			}
			path = path->next;
		}
		gr->start->ants -= i;
	}
	return (lants);
}

int				send_ants(t_graph *gr)
{
	t_ants		*lants;
	int			i;

	lants = NULL;
	i = 0;
	while (gr->end->ants != gr->n_ants)
	{
		move_ants(lants);
		lants = move_start_ants(lants, gr);
		ft_putchar('\n');
		i++;
	}
	del_ants(lants);
	return (i);
}
