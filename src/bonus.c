/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoncalv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/04 13:53:14 by jgoncalv          #+#    #+#             */
/*   Updated: 2017/02/04 13:53:15 by jgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void		display_path(t_link *path, t_graph *gr, t_bonus bon)
{
	t_room *tmp;

	ft_printf("\nMove=%d", bon.nb_coup);
	if (path)
		ft_putstr("\n\nPath :\n");
	while (path)
	{
		if (path->link->path || path->link == gr->end)
		{
			ft_printf("Lmin=%d  %s-",
				path->link->ants_min, gr->start->name);
			tmp = path->link;
			while (tmp)
			{
				ft_putstr(tmp->name);
				if (tmp->path != NULL)
					ft_putchar('-');
				tmp = tmp->path;
			}
			ft_putchar('\n');
		}
		path = path->next;
	}
}

static int	option(char *str, t_bonus *bon)
{
	int i;

	if ((i = ft_strlen(str)) == 1)
		i++;
	if (str[0] == '-')
		i--;
	if (ft_strchr(str, 'p'))
	{
		bon->opt = p;
		i--;
	}
	if (i != 0)
	{
		ft_putstr_fd("Usage : ./lem-in -option <map\n", 2);
		ft_putstr_fd("Option : p = show path\n", 2);
		return (0);
	}
	return (1);
}

int			get_bonus(char **av, int ac, t_bonus *bon)
{
	if (ac == 2)
		return (option(av[1], bon));
	else if (ac != 1)
	{
		ft_putstr_fd("Usage : ./lem-in -option < map\n", 2);
		ft_putstr_fd("Option : p = show path\n", 2);
		return (0);
	}
	return (1);
}
