/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memjoinf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoncalv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/24 13:47:53 by jgoncalv          #+#    #+#             */
/*   Updated: 2017/01/24 13:47:54 by jgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memjoinf(void *mem1, void *mem2, size_t len1, size_t len2)
{
	void	*ret;

	ret = ft_memjoin(mem1, mem2, len1, len2);
	ft_memdel(&mem1);
	ft_memdel(&mem2);
	return (ret);
}
