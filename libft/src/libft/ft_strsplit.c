/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoncalv <jgoncalv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 12:31:42 by jgoncalv          #+#    #+#             */
/*   Updated: 2016/12/12 12:32:47 by jgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int		ft_nbword(char const *s, char c)
{
	int i;
	int nb_word;

	i = 0;
	nb_word = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			nb_word++;
			while (s[i] != c && s[i])
				i++;
		}
		else
			i++;
	}
	return (nb_word);
}

static	char	**ft_isplit(char const *s, char c, int nb_word)
{
	int		i;
	int		j;
	int		start;
	char	**tab;

	i = 0;
	j = 0;
	start = 0;
	if (!(tab = (char**)malloc(sizeof(char*) * (nb_word + 1))))
		return (NULL);
	while (j < nb_word)
	{
		if (s[i] != c)
		{
			start = i;
			while (s[i] != c && s[i] != '\0')
				i++;
			tab[j] = ft_strsub(s, start, i - start);
			j++;
		}
		else
			i++;
	}
	tab[j] = NULL;
	return (tab);
}

char			**ft_strsplit(char const *s, char c)
{
	if (!s)
		return (NULL);
	return (ft_isplit(s, c, ft_nbword(s, c)));
}
