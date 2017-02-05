/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoncalv <jgoncalv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 14:20:03 by jgoncalv          #+#    #+#             */
/*   Updated: 2016/12/12 12:31:38 by jgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_realloc(void *ptr, size_t size)
{
	char *newptr;

	if (!size && ptr)
	{
		if (!(newptr = (char*)malloc(sizeof(char*) * 1)))
			return (NULL);
		ft_memdel(&ptr);
	}
	else if (ptr)
	{
		if (!(newptr = (char*)malloc(sizeof(char*) * size)))
			return (NULL);
		ft_memcpy(newptr, ptr, size);
		ft_memdel(&ptr);
	}
	else
		newptr = NULL;
	return (newptr);
}
