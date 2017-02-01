/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   param.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoncalv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/25 15:19:29 by jgoncalv          #+#    #+#             */
/*   Updated: 2017/01/25 15:19:30 by jgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static t_graph	*nb_ants(t_graph *gr, char *line)
{
	int			i;
	long long	nbr;

	i = 0;
	nbr = 0;
	while (line[i])
	{
		if (!ft_isdigit(line[i]))
			ft_error("Error : Unconform\n", gr);
		if ((nbr = nbr * 10 + (line[i] - '0')) <= 0 || nbr > INT_MAX)
			ft_error("Error : Not the good size of ants\n", gr);
		i++;
	}
	gr->n_ants = ft_atoi(line);
	return (gr);
}

static char		*anthilltostr(char *str, char *line)
{
	char *newline;
	char *newstr;

	newline = malloc(sizeof(char) * (ft_strlen(line) + 2));
	ft_strcpy(newline, line);
	newline[ft_strlen(line)] = '\n';
	newline[ft_strlen(line) + 1] = '\0';
	if (!str)
	{
		str = malloc(sizeof(char) * (ft_strlen(newline) + 1));
		str = ft_strcpy(str, newline);
	}
	else
	{
		newstr = (char*)malloc(sizeof(char) *
			(ft_strlen(str) + ft_strlen(newline) + 1));
		ft_bzero(newstr, 0);
		newstr = ft_strcpy(newstr, str);
		newstr = ft_strcat(newstr, newline);
		ft_strdel(&str);
		str = newstr;
	}
	ft_strdel(&newline);
	return (str);
}

static void		param(t_graph *gr, char *line, char c)
{
	static int i = 0;

	if (*line && gr->n_ants == 0)
	{
		if (c)
			ft_error("Error : Unconform\n", gr);
		nb_ants(gr, line);
	}
	else if (!ft_strchr(line, '-') && i == 0)
		room(gr, line, c);
	else if (ft_strchr(line, '-'))
	{
		i = 1;
		if (c)
			ft_error("Error : Unconform\n", gr);
		lst_link(gr, line);
	}
	else
		ft_error("Error : Unconform\n", gr);
}

void			get_anthill(t_graph *gr)
{
	char	*line;
	char	c;

	line = NULL;
	while (get_next_line(0, &line) == 1)
	{
		if (!(gr->anthill = anthilltostr(gr->anthill, line)))
			ft_error("Error : failed to malloc\n", gr);
		if (ft_strcmp(line, "##start") == 0)
			c = 's';
		else if (ft_strcmp(line, "##end") == 0)
			c = 'e';
		else if (*line == '#')
			;
		else
		{
			param(gr, line, c);
			if (c)
				c = '\0';
		}
		ft_strdel(&line);
	}
	if (!gr->n_ants || !gr->room)
		ft_error("Error : Unconform\n", gr);
	gr->start->ants = gr->n_ants;
}
