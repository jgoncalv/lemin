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

int				check_path(t_link *path, t_graph *gr)
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
	t_bonus	bonus;

	(void)av;
	if (get_bonus(av, ac, &bonus) == 0 || !(gr = graph_init()))
		return (1);
	get_anthill(gr);
	bfs_start(gr);
	write(1, gr->anthill, ft_strlen(gr->anthill));
	ft_putchar('\n');
	ants_min(gr->start->lst_link, gr);
	bonus.nb_coup = send_ants(gr);
	if (bonus.opt == p)
		display_path(gr->start->lst_link, gr, bonus);
	gr = del(gr);
	return (0);
}
