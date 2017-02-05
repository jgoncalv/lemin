/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoncalv <jgoncalv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 11:25:27 by jgoncalv          #+#    #+#             */
/*   Updated: 2016/11/13 12:40:37 by jgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_cpytrim(char const *s, int start, int end)
{
	char	*str;
	int		i;

	if (!(str = ft_strnew(end - start + 1)))
		return (0);
	i = 0;
	while (i <= end - start)
	{
		str[i] = s[i + start];
		i++;
	}
	if (str[i] != '\0')
		str[i] = '\0';
	return (str);
}

char		*ft_strtrim(char const *s)
{
	int		start;
	int		end;
	int		i;

	if (!s)
		return (0);
	i = 0;
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
		i++;
	start = i;
	i = ft_strlen(s) - 1;
	while (i > start && (s[i] == ' ' || s[i] == '\n'
		|| s[i] == '\t' || s[i] == '\0'))
		i--;
	if (i == start)
		end = ft_strlen(s);
	else
		end = i;
	return (ft_cpytrim(s, start, end));
}
