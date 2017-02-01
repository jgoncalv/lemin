/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoncalv <jgoncalv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 17:22:59 by jgoncalv          #+#    #+#             */
/*   Updated: 2016/12/15 11:00:29 by jgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include "libft.h"
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

# define BUFF_SIZE 1024

typedef	struct		s_fds
{
	char			*str;
	int				cfd;
	struct s_fds	*next;
	struct s_fds	*prev;
}					t_fds;

int					get_next_line(const int fd, char **line);

#endif
