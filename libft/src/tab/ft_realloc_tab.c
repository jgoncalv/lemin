/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoncalv <jgoncalv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 14:36:58 by jgoncalv          #+#    #+#             */
/*   Updated: 2016/12/12 12:31:44 by jgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_realloc_tab(char **tab, size_t size)
{
	char		**tmp;
	size_t		i;

	i = 0;
	if (!(tmp = ft_tabnew(size)))
		return (NULL);
	while (i < size)
	{
		if (tab[i])
		{
			if (!(tmp[i] = ft_realloc(tab[i], ft_strlen(tab[i]))))
				return (NULL);
		}
		i++;
	}
	free(tab);
	tab = NULL;
	return (tmp);
}
