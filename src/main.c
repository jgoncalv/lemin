/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoncalv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/24 18:33:04 by jgoncalv          #+#    #+#             */
/*   Updated: 2017/01/24 18:33:05 by jgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static t_graph	*graph_init(void)
{
	t_graph	*graph;

	if (!(graph = (t_graph*)malloc(sizeof(t_graph))))
		return (NULL);
	graph->n_ants = 0;
	graph->anthill = NULL;
	graph->start = NULL;
	graph->end = NULL;
	graph->room = NULL;
	return (graph);
}

static int		check_path(t_link *path, t_graph *gr)
{
	while (path)
	{
		if (path->link == gr->end)
			return (1);
		if (path->link->path)
			return (1);
		path = path->next;
	}
	return (0);
}

static int		next_is_end(t_graph *gr)
{
	t_link	*path;
	int		id;

	id = 0;
	path = gr->start->lst_link;
	while (path)
	{
		if (path->link == gr->end)
		{
			while (gr->end->ants != gr->n_ants)
			{
				display(id, gr->end->name);
				gr->start->ants--;
				gr->end->ants++;
				id++;
			}
			ft_putchar('\n');
			return (1);
		}
		path = path->next;
	}
	return (0);
}

void			display(int d, char *str)
{
	ft_putchar('L');
	ft_putnbr(d);
	ft_putchar('-');
	ft_putstr(str);
	ft_putchar(' ');
}

int				main(int ac, char **av)
{
	t_graph	*gr;

	(void)av;
	if (ac != 1)
	{
		ft_putstr_fd("Usage : ./lem-in || ./lem-in < file\n", 2);
		return (1);
	}
	if (!(gr = graph_init()))
		return (1);
	get_anthill(gr);
	bfs_start(gr);
	if (check_path(gr->start->lst_link, gr) == 0)
		ft_error("Error : No path start to end\n", gr);
	write(1, gr->anthill, ft_strlen(gr->anthill));
	ft_putchar('\n');
	if (!next_is_end(gr))
	{
		ants_min(gr->start->lst_link);
		send_ants(gr);
	}
	gr = del(gr);
	return (0);
}
