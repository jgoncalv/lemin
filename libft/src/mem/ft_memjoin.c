/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoncalv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/24 13:46:51 by jgoncalv          #+#    #+#             */
/*   Updated: 2017/01/24 13:46:53 by jgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memjoin(const void *mem1, const void *mem2,
					size_t len1, size_t len2)
{
	void	*ret;

	if (!(ret = (void *)malloc(sizeof(void) * (len1 + len2))))
		return (NULL);
	ft_memcpy(ret, mem1, len1);
	ft_memcpy(ret + len1, mem2, len2);
	return (ret);
}
