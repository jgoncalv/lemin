/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoncalv <jgoncalv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 19:45:17 by jgoncalv          #+#    #+#             */
/*   Updated: 2016/12/29 16:17:45 by jgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char *str;

	if (!s1 || !s2)
		return (0);
	if (!(str = (char*)ft_strnew(ft_strlen(s1) + ft_strlen(s2))))
		return (0);
	ft_strcpy(str, s1);
	ft_strcat(str, s2);
	return (str);
}
