/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoncalv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/24 19:07:53 by jgoncalv          #+#    #+#             */
/*   Updated: 2017/01/24 19:10:22 by jgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEMIN_H
# define LEMIN_H

# include "libft.h"
# include "get_next_line.h"
# include "limits.h"
# include "stdio.h"
# include "ft_printf.h"

typedef struct s_link	t_link;

typedef struct		s_room
{
	char			*name;
	int				ants;
	int				path_len;
	int				ants_min;
	int				coord_x;
	int				coord_y;
	t_link			*lst_link;
	struct s_room	*path;
	struct s_room	*next;
}					t_room;

struct				s_link
{
	t_room			*link;
	t_link			*parent;
	struct s_link	*next;
};

typedef	struct		s_graph
{
	int				n_ants;
	char			*anthill;
	t_room			*start;
	t_room			*end;
	t_room			*room;
}					t_graph;

typedef struct		s_ants
{
	t_room			*room;
	int				ants_id;
	struct s_ants	*next;
	struct s_ants	*prev;
}					t_ants;

typedef struct		s_bonus
{
	int				nb_coup;
	enum
	{
		nul,
		p
	}				opt;
}					t_bonus;

/*
**	ERREUR
*/

void				ft_error(char *str, t_graph *gr);
void				error_del_tab(char *msg, char **tab,
					int p_msg, t_graph *gr);

/*
**	PARAM
*/
void				get_anthill();
void				room(t_graph *gr, char *line, char c);
void				lst_link(t_graph *gr, char *line);

/*
**	LISTE
*/
t_room				*new_room(t_room *lst_room, char *name, int x, int y);
t_link				*new_link(t_link *lst_link, t_room *room, t_link *parent);
t_ants				*add_ants(t_ants *lants, t_room *room, int id);
t_link				*link_del(t_link *lst_link);

/*
**	ALGO
*/
void				bfs_start(t_graph *gr);
void				ants_min(t_link *path, t_graph *gr);
int					send_ants(t_graph *gr);
int					check_path(t_link *path, t_graph *gr);

/*
**	DISPLAY
*/
void				display(int d, char *str);

/*
**	DEL
*/
t_graph				*del(t_graph *gr);

/*
**	OPTION
*/
int					get_bonus(char **av, int ac, t_bonus *bon);
void				display_path(t_link *path, t_graph *gr, t_bonus bon);

#endif
