/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wstrlen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoncalv <jgoncalv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 13:46:46 by jgoncalv          #+#    #+#             */
/*   Updated: 2016/12/12 12:33:05 by jgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_wstrlen(wchar_t *wstr)
{
	int	i;
	int len;

	i = 0;
	len = 0;
	while (wstr[i])
	{
		if (wstr[i] <= 0x7F)
			len += 1;
		else if (wstr[i] <= 0x7FF)
			len += 2;
		else if (wstr[i] <= 0xFFFF)
			len += 3;
		else if (wstr[i] <= 0x1FFFFF)
			len += 4;
		i++;
	}
	return (len);
}
