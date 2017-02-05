/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoncalv <jgoncalv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 20:04:59 by jgoncalv          #+#    #+#             */
/*   Updated: 2016/12/12 12:32:42 by jgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t i;
	size_t j;
	size_t k;

	i = 0;
	if (!*little)
		return ((char*)big);
	while (big[i] && i < len)
	{
		j = 0;
		k = i;
		if (little[j] == big[k])
		{
			while (big[k] == little[j] && k < len)
			{
				j++;
				k++;
				if (little[j] == '\0')
					return ((char*)(&big[i]));
			}
		}
		i++;
	}
	return (0);
}
