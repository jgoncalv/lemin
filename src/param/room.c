/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   room.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoncalv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/27 20:21:12 by jgoncalv          #+#    #+#             */
/*   Updated: 2017/01/27 20:21:13 by jgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static int	check_number(char *str)
{
	int			i;
	long long	nbr;

	i = 0;
	nbr = 0;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		if ((nbr = nbr * 10 + (str[i] - '0')) < 0 || nbr > INT_MAX)
			return (0);
		i++;
	}
	return (1);
}

static int	check_name(char *str, t_room *room)
{
	int i;

	i = 0;
	if (str[0] == 'L' || ft_strchr(str, '-'))
		return (0);
	while (room)
	{
		if (ft_strcmp(room->name, str) == 0)
			return (0);
		room = room->next;
	}
	return (1);
}

static int	check_coord(t_room *room, int x, int y)
{
	if (!room)
		return (1);
	while (room)
	{
		if (room->coord_x == x && room->coord_y == y)
			return (0);
		room = room->next;
	}
	return (1);
}

static int	check_conform(char *line)
{
	int	i;
	int	space;

	i = 0;
	space = 0;
	while (line[i])
	{
		if (line[i] == ' ')
			space++;
		i++;
	}
	if (space != 2)
		return (0);
	return (1);
}

void		room(t_graph *gr, char *line, char c)
{
	char	**tab;
	int		i;

	tab = NULL;
	if (!(check_conform(line)) || !(tab = ft_strsplit(line, ' ')))
		ft_error("Error : Unconform\n", gr);
	i = 0;
	while (tab[i])
		i++;
	if (i != 3)
		ft_error("Error : Unconform\n", gr);
	if (!(check_name(tab[0], gr->room)))
		error_del_tab("Error : Name unconform or already exist\n", tab, 1, gr);
	if (!(check_number(tab[1]) || !(check_number(tab[2]))))
		error_del_tab("Error : Coord unconform or bad size\n", tab, 1, gr);
	if (!(check_coord(gr->room, ft_atoi(tab[1]), ft_atoi(tab[2]))))
		error_del_tab("Error : Coord already taken\n", tab, 1, gr);
	if (!(gr->room = new_room(gr->room, tab[0],
		ft_atoi(tab[1]), ft_atoi(tab[2]))))
		error_del_tab("Error : New room failed\n", tab, 1, gr);
	if (c == 's')
		gr->start = gr->room;
	else if (c == 'e')
		gr->end = gr->room;
	error_del_tab("", tab, 0, gr);
}
