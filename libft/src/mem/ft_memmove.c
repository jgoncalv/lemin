/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoncalv <jgoncalv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 12:19:05 by jgoncalv          #+#    #+#             */
/*   Updated: 2016/12/12 12:30:48 by jgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char *d;
	unsigned char *s;

	s = (unsigned char*)src;
	d = (unsigned char*)dest;
	if (n > 0)
	{
		if (src >= dest)
		{
			ft_memcpy(dest, src, n);
		}
		else
		{
			n--;
			while (n > 0)
			{
				d[n] = s[n];
				n--;
			}
			d[n] = s[n];
		}
	}
	return (dest);
}
