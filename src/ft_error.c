/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoncalv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/25 15:46:23 by jgoncalv          #+#    #+#             */
/*   Updated: 2017/01/25 15:46:25 by jgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

t_link		*link_del(t_link *lst_link)
{
	if (lst_link && lst_link->next)
		link_del(lst_link->next);
	free(lst_link);
	return (NULL);
}

t_graph		*del(t_graph *gr)
{
	t_room *tmp;

	if (gr != NULL)
	{
		while (gr->room)
		{
			tmp = gr->room;
			link_del(gr->room->lst_link);
			ft_strdel(&gr->room->name);
			gr->room = gr->room->next;
			free(tmp);
			tmp = NULL;
		}
		ft_strdel(&gr->anthill);
		free(gr);
		gr = NULL;
	}
	return (gr);
}

void		ft_error(char *str, t_graph *gr)
{
	ft_putstr_fd(str, 2);
	gr = del(gr);
	exit(1);
}

void		error_del_tab(char *msg, char **tab, int p_msg, t_graph *gr)
{
	int i;

	i = 0;
	while (tab[i])
	{
		ft_strdel(&tab[i]);
		i++;
	}
	free(tab);
	if (p_msg == 1)
		ft_error(msg, gr);
}
